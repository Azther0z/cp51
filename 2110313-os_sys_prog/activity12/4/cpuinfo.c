// cpuinfo.c
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("KRERK PIROMSOPA, PH.D. <Krerk.P@chula.ac.th>; OpenAI ChatGPT");
MODULE_DESCRIPTION("\"cpuinfo\" Character Device");

#define DEVICENAME "cpuinfo"
#define CPUINFO_BUFSIZE 512

static int dev_major;
static int dev_open;
static char cpuinfo_data[CPUINFO_BUFSIZE];
static char *f_ptr;

static inline void cpuinfo_cpuid(unsigned int *eax, unsigned int *ebx,
				 unsigned int *ecx, unsigned int *edx)
{
	/* ecx is often an input as well as an output. */
	asm volatile("cpuid"
		     : "=a" (*eax),
		       "=b" (*ebx),
		       "=c" (*ecx),
		       "=d" (*edx)
		     : "0" (*eax), "2" (*ecx)
		     : "memory");
}

static void make_cpuinfo(void)
{
	unsigned int eax, ebx, ecx, edx;
	unsigned int stepping, model, family, processor_type;
	unsigned int extended_model, extended_family;
	char vendor[13];

	/* Vendor ID */
	eax = 0;
	ecx = 0;
	cpuinfo_cpuid(&eax, &ebx, &ecx, &edx);
	vendor[0] = ebx & 0xff;
	vendor[1] = (ebx >> 8) & 0xff;
	vendor[2] = (ebx >> 16) & 0xff;
	vendor[3] = (ebx >> 24) & 0xff;
	vendor[4] = edx & 0xff;
	vendor[5] = (edx >> 8) & 0xff;
	vendor[6] = (edx >> 16) & 0xff;
	vendor[7] = (edx >> 24) & 0xff;
	vendor[8] = ecx & 0xff;
	vendor[9] = (ecx >> 8) & 0xff;
	vendor[10] = (ecx >> 16) & 0xff;
	vendor[11] = (ecx >> 24) & 0xff;
	vendor[12] = '\0';

	/* Processor info and feature bits */
	eax = 1;
	ecx = 0;
	cpuinfo_cpuid(&eax, &ebx, &ecx, &edx);
	stepping = eax & 0xf;
	model = (eax >> 4) & 0xf;
	family = (eax >> 8) & 0xf;
	processor_type = (eax >> 12) & 0x3;
	extended_model = (eax >> 16) & 0xf;
	extended_family = (eax >> 20) & 0xff;

	/* Processor serial number */
	eax = 3;
	ecx = 0;
	cpuinfo_cpuid(&eax, &ebx, &ecx, &edx);

	snprintf(cpuinfo_data, CPUINFO_BUFSIZE,
		 "Author OpenAI ChatGPT\n"
		 "Vendor ID %s\n"
		 "stepping %u\n"
		 "model %u\n"
		 "family %u\n"
		 "processor type %u\n"
		 "extended model %u\n"
		 "extended family %u\n"
		 "serial number 0x%08x%08x\n",
		 vendor, stepping, model, family, processor_type,
		 extended_model, extended_family, edx, ecx);
}

static int device_open(struct inode *inode, struct file *file)
{
	if (dev_open)
		return -EBUSY;

	dev_open++;
	printk(KERN_INFO "cpuinfo: dev minor %d\n", MINOR(inode->i_rdev));
	make_cpuinfo();
	f_ptr = cpuinfo_data;
	try_module_get(THIS_MODULE);
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	dev_open--;
	module_put(THIS_MODULE);
	return 0;
}

static ssize_t device_read(struct file *filp, char *buffer, size_t length,
				   loff_t *offset)
{
	int bytes_read = 0;

	if (*f_ptr == 0)
		return 0;

	while (length && *f_ptr) {
		if (put_user(*(f_ptr++), buffer++))
			return -EFAULT;
		length--;
		bytes_read++;
	}

	return bytes_read;
}

static struct file_operations dev_fops = {
	.read = device_read,
	.open = device_open,
	.release = device_release
};

int init_module(void)
{
	printk(KERN_INFO "CPCHAR: dev cpuinfo init\n");
	dev_major = register_chrdev(0, DEVICENAME, &dev_fops);
	if (dev_major < 0) {
		printk(KERN_ALERT "Fail register_chrdev cpuinfo with %d\n", dev_major);
		return dev_major;
	}
	printk(KERN_INFO "Device MajorNumber %d.\n", dev_major);
	printk(KERN_INFO "To create a device file:\n");
	printk(KERN_INFO "\t'mknod /dev/%s c %d 0'.\n", DEVICENAME, dev_major);
	printk(KERN_INFO "Please remove the device file and module when done.\n");
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO "CPCHAR: dev cpuinfo cleanup\n");
	unregister_chrdev(dev_major, DEVICENAME);
}
