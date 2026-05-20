package logic.task;

import java.util.ArrayList;

import interfaces.Duplicatable;

public class TaskManager {
	public static ArrayList<Task> getTaskByType(ArrayList<Class> types) {
		ArrayList<Task> tasks = TaskList.getTasks();
		ArrayList<Task> returnTasks = new ArrayList<Task>();
		for (Task task : tasks) {
			for (Class c : types) {
				if (instanceOf(task.getClass(), c)) {
					returnTasks.add(task);
					break;
				}
			}
		}
		return returnTasks;
	}

	public static void deleteDuplicateTasks() {
		ArrayList<Task> tasks = TaskList.getTasks();
		for (int i = 0; i < tasks.size(); i++) {
			if (instanceOf(tasks.get(i).getClass(), Duplicatable.class) && tasks.get(i).toString().contains("-")) {
				System.out.println(tasks.get(i).toString());
				tasks.remove(i);
				i--;
			}
		}
	}

	public static boolean instanceOf(Class checkClass, Class interfaceClass) {
		return interfaceClass.isAssignableFrom(checkClass);
	}
}
