#include "TaskManager.h"
#include <iterator>

unsigned int TaskManager::registerTask(std::function<void()> function, unsigned long delay)
{
	Task task(function, delay, 1, false);
	if (delay == 0)
		tasks.insert({ taskCounter, task });
	taskCounter++;
	return taskCounter;
}

unsigned int TaskManager::registerRepetitiveTask(std::function<void()> function, unsigned long delay, unsigned long period)
{
	RepetitiveTask task(function, delay, period, false);
	if (delay == 0)
		repetitiveTasks.insert({ taskCounter, task });
	taskCounter++;
	return taskCounter;
}

void TaskManager::runTasks()
{
	for (auto firstPairIt = tasks.begin(); firstPairIt != tasks.end(); firstPairIt++)
	{
		firstPairIt->second.run();
	}

	for (auto firstPairIt = repetitiveTasks.begin(); firstPairIt != repetitiveTasks.end(); firstPairIt++)
	{
		if (firstPairIt->second.canRun())
			firstPairIt->second.run();
	}
}
