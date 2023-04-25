#pragma once
#include <functional>

class TaskManager {
public:
	int runTask(std::function<void()> function);
	int runTask(std::function<void()> function, unsigned long delay);
	int runRepetitiveTask(std::function<void()> function);

	bool cancel(int taskID);
	bool wasRun(int taskID);
};