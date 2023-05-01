#include "TaskManager.h"
#include <iterator>

unsigned int TaskManager::runRepetitiveTask(std::function<void()> function, unsigned long delay, unsigned long period)
{
	Task task(function, delay, period, false);
	if (delay == 0)
		tasks.insert({ taskCounter, task });
	else
	{
		auto it = waitingTasks.begin();
		std::advance(it, delay);
		it->push_back(task);
	}
	return 0;
}