#pragma once
#include<map>
#include<list>
#include <vector>
#include <functional>
#include "PeriodicDelayedCounter.h"

struct Task {
	Task(std::function<void()> function,
		unsigned long delay,
		unsigned long duration,
		bool async): function(function), delay(delay), duration(duration), async(async) {}

	void run() {
		function();
	}

protected:
	std::function<void()> function;
	unsigned long delay;
	unsigned long duration;
	bool async;
};

struct RepetitiveTask : public Task{
public:
	RepetitiveTask(std::function<void()> function,
		unsigned long delay,
		unsigned long duration,
		bool async) : Task(function, delay, duration, async), pdc(PeriodicDelayedCounter(delay, duration)){}

	bool canRun() {
		return pdc.canRun();
	}
private:
	PeriodicDelayedCounter pdc;
};

class TaskManager {
public:
	unsigned int registerTask(std::function<void()> function, unsigned long delay);
	unsigned int registerRepetitiveTask(std::function<void()> function, unsigned long delay = 0, unsigned long period = 1);

	bool cancel(unsigned int taskID);
	bool wasRun(unsigned int taskID);

	void runTasks();

private:
	//usefull to use two maps ?
	std::map<unsigned int, Task> tasks;
	std::map<unsigned int, RepetitiveTask> repetitiveTasks;

	unsigned int taskCounter = 0;
};