#pragma once

#include "Math.h"

class PeriodicDelayedCounter
{
public:
	PeriodicDelayedCounter(unsigned long delay, unsigned long period) : delay(delay), period(period) {
		unsigned long targetBias = period - 1;
		unsigned long bias = Math::one_complement(period, (maxValue % period));
		if (bias == targetBias)
			maxFrame = maxValue;
		else
		{
			unsigned long diff = targetBias - bias;
			maxFrame = maxValue + diff - period ;
		}
	}

	bool canRun() {
		if (hasRun){
			if (count % period == 0){
				count++;
				return true;
			}
			else {
				count++;
				return false;
			}
		}
		else {
			if (count == delay){
				count = 1;
				hasRun = true;
				return true;
			}
			else{
				count++;
				return false;
			}
		}
	}

private:
	unsigned long maxFrame;
	unsigned long count = 0;
	unsigned long delay;
	unsigned long period;
	bool hasRun = false;
	static const unsigned long maxValue = ~0;
};