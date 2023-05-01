#pragma once
#include<map>
#include<list>
#include <vector>
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
	unsigned int runTask(std::function<void()> function, unsigned long delay);
	unsigned int runRepetitiveTask(std::function<void()> function, unsigned long delay = 0, unsigned long period = 1);

	bool cancel(unsigned int taskID);
	bool wasRun(unsigned int taskID);

	void updateTasks();

private:
	//usefull to use two maps ?
	std::map<unsigned int, Task> tasks;
	std::map<unsigned int, Task> permanentTasks;

	unsigned int taskCounter = 0;
};