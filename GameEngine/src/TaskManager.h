#pragma once
#include<map>
#include <functional>

struct Task {
	Task(std::function<void()> function,
		unsigned long delay,
		unsigned long duration,
		bool async): function(function), delay(delay), duration(duration), async(async) {}
	std::function<void()> function;
	unsigned long delay;
	unsigned long duration;
	bool async;
};

class TaskManager {
public:
	unsigned int runTask(std::function<void()> function);
	unsigned int runDelayedTask(std::function<void()> function, unsigned long delay);
	unsigned int runRepetitiveTask(std::function<void()> function, unsigned long delay, unsigned long duration);
	unsigned int runPermanentTask(std::function<void()> function, unsigned long delay);

	bool cancel(int taskID);
	bool wasRun(int taskID);

	void updateTasks();

private:
	//usefull to use two maps ?
	std::map<int, Task> tasks;
	std::map<int, Task> permanentTasks;

	unsigned int taskCounter = 0;
};