#ifndef WIS_H
#define WIS_H

#include <iostream>
#include <iomanip>
#include <string>

struct Interval {
	int start;
	int finish;
	int weight;
	int previousJobIndex = -1;
};

class WIS {
public:
	WIS() { SetWIS(0); }
	WIS(int size) { SetWIS(size); }
	void SetWIS(int size);
	void AddInterval(Interval interval);
	void SortIntervals();
	void PrintSortedIntervals();
	int  FindMaxWeight();
	int GetMaxWeight(int index);
	void PrintJobsInvolved(int indexEndJob); 
	~WIS() { DestroyWIS(); }

private:
	int numIntervals = 0;
	int nextIndex = 0;
	Interval* intervals = nullptr;
	int* weightsArray = nullptr;
	void DestroyWIS();
};


#endif
