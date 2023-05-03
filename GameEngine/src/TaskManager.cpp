#include "TaskManager.h"
#include <iterator>

unsigned int TaskManager::registerTask(std::function<void()> function, unsigned long delay)
{
	Task task(function, delay, 1, false);
	tasks.insert({ taskCounter, task });
	taskCounter++;
	return taskCounter;
}

unsigned int TaskManager::registerRepetitiveTask(std::function<void()> function, unsigned long delay, unsigned long period)
{
	RepetitiveTask task(function, delay, period, false);
	repetitiveTasks.insert({ taskCounter, task });
	taskCounter++;
	return taskCounter;
}

bool TaskManager::cancel(unsigned int taskID)
{
	return (tasks.find(taskID) == tasks.end());
}

void TaskManager::runTasks()
{
	for (auto firstPairIt = tasks.begin(); firstPairIt != tasks.end(); )
	{
		firstPairIt->second.run();
		firstPairIt = tasks.erase(firstPairIt);
	}

	for (auto firstPairIt = repetitiveTasks.begin(); firstPairIt != repetitiveTasks.end(); std::advance(firstPairIt, 1))
	{
		if (firstPairIt->second.canRun())
			firstPairIt->second.run();
	}
}
