// cpsysinfo character device kernel module
// References: ../1/dummy.c (basic module), ../2/osinfo.c and ../3/osinfo.c
// (character device with minor-number based output).

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>
#include <linux/sched/signal.h>
#include <linux/mm.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("OpenAI ChatGPT");
MODULE_DESCRIPTION("\"cpsysinfo\" Character Device");

#define DEVICENAME "cpsysinfo"
#define PROC_BUF_SIZE (1024 * 1024)
#define MEM_BUF_SIZE 256

struct cpsysinfo_data {
	char *buf;
	size_t len;
};

static int dev_major;

static int device_open(struct inode *inode, struct file *file);
static int device_release(struct inode *inode, struct file *file);
static ssize_t device_read(struct file *file, char __user *buffer,
				   size_t length, loff_t *offset);

static const struct file_operations dev_fops = {
	.owner = THIS_MODULE,
	.read = device_read,
	.open = device_open,
	.release = device_release,
};

static unsigned long pages_to_kb(unsigned long pages)
{
	return pages << (PAGE_SHIFT - 10);
}

static int fill_process_info(struct cpsysinfo_data *data)
{
	struct task_struct *task;
	size_t pos = 0;

	data->buf = kvmalloc(PROC_BUF_SIZE, GFP_KERNEL);
	if (!data->buf)
		return -ENOMEM;

	rcu_read_lock();
	for_each_process(task) {
		int n;

		if (pos >= PROC_BUF_SIZE - 1)
			break;

		n = scnprintf(data->buf + pos, PROC_BUF_SIZE - pos,
			      "%d,%s\n", task->pid, task->comm);
		pos += n;
	}
	rcu_read_unlock();

	if (pos < PROC_BUF_SIZE - 1)
		pos += scnprintf(data->buf + pos, PROC_BUF_SIZE - pos,
				 "Author: OpenAI ChatGPT\n");

	data->len = pos;
	return 0;
}

static int fill_memory_info(struct cpsysinfo_data *data)
{
	struct sysinfo i;
	unsigned long available;

	data->buf = kmalloc(MEM_BUF_SIZE, GFP_KERNEL);
	if (!data->buf)
		return -ENOMEM;

	si_meminfo(&i);
	available = si_mem_available();

	data->len = scnprintf(data->buf, MEM_BUF_SIZE,
			    "MemTotal: %lu kB\n"
			    "MemFree: %lu kB\n"
			    "MemAvailable: %lu kB\n"
			    "Author: OpenAI ChatGPT\n",
			    pages_to_kb(i.totalram),
			    pages_to_kb(i.freeram),
			    pages_to_kb(available));
	return 0;
}

static int device_open(struct inode *inode, struct file *file)
{
	struct cpsysinfo_data *data;
	unsigned int minor = iminor(inode);
	int ret;

	data = kzalloc(sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	if (minor == 0)
		ret = fill_process_info(data);
	else if (minor == 1)
		ret = fill_memory_info(data);
	else
		ret = -EINVAL;

	if (ret) {
		kvfree(data->buf);
		kfree(data);
		return ret;
	}

	file->private_data = data;
	printk(KERN_INFO DEVICENAME ": opened minor %u\n", minor);
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	struct cpsysinfo_data *data = file->private_data;

	if (data) {
		kvfree(data->buf);
		kfree(data);
	}
	return 0;
}

static ssize_t device_read(struct file *file, char __user *buffer,
				   size_t length, loff_t *offset)
{
	struct cpsysinfo_data *data = file->private_data;

	if (!data || !data->buf)
		return -EFAULT;

	return simple_read_from_buffer(buffer, length, offset,
				       data->buf, data->len);
}

static int __init cpsysinfo_init(void)
{
	dev_major = register_chrdev(0, DEVICENAME, &dev_fops);
	if (dev_major < 0) {
		printk(KERN_ALERT DEVICENAME ": register_chrdev failed: %d\n",
		       dev_major);
		return dev_major;
	}

	printk(KERN_INFO DEVICENAME ": major number %d\n", dev_major);
	printk(KERN_INFO "Create devices with:\n");
	printk(KERN_INFO "  mknod /dev/%s0 c %d 0\n", DEVICENAME, dev_major);
	printk(KERN_INFO "  mknod /dev/%s1 c %d 1\n", DEVICENAME, dev_major);
	return 0;
}

static void __exit cpsysinfo_exit(void)
{
	unregister_chrdev(dev_major, DEVICENAME);
	printk(KERN_INFO DEVICENAME ": cleanup\n");
}

module_init(cpsysinfo_init);
module_exit(cpsysinfo_exit);
