#pragma once

class DelayedCounter
{
public:
	DelayedCounter(unsigned long delay) : delay(delay) {

	}

	bool canRun() {
		if (delay == counter)
			return true;
		else
		{
			counter++;
			return false;
		}
	}

private:
	unsigned long delay;
	unsigned long counter = 0;
};