#include "TaskManager.h"
#include <iterator>

unsigned int TaskManager::runRepetitiveTask(std::function<void()> function, unsigned long delay, unsigned long period)
{
	Task task(function, delay, period, false);
	if (delay == 0)
		permanentTasks.insert({ taskCounter, task });
	taskCounter++;
	return 0;
}