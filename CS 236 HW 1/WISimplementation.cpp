#include "WISheader.h"

void WIS::SetWIS(int size) {
	try {
		intervals = new Interval[size];
		weightsArray = new int[size];
		numIntervals = size;
	}
	catch (std::bad_alloc error) {
		std::cerr << "Creation of Object failed, " << error.what();
	}
}

void WIS::DestroyWIS() {
	numIntervals = 0;
	if (intervals != nullptr) {
		delete[] intervals;
		intervals = nullptr;
	}
	if (weightsArray != nullptr) {
		delete[] weightsArray;
		weightsArray = nullptr;
	}
}

void WIS::AddInterval(Interval interval) {
	if (nextIndex < numIntervals) {
		intervals[nextIndex] = interval;
		nextIndex++;
	}
	else {
		std::cout << "array is full\n\n";
	}
}

void WIS::SortIntervals() {
	for (int i = 0; i < numIntervals; i++) {
		int minFinish = i;
		bool shouldSwap = false;
		for (int j = i + 1; j < numIntervals; j++) {
			if (intervals[j].finish < intervals[minFinish].finish) {
				minFinish = j;
				shouldSwap = true;
			}
		}
		if (shouldSwap) {

			Interval temp = intervals[i];
			intervals[i] = intervals[minFinish];
			intervals[minFinish] = temp;
		}

	}
	//copy into weights array
	for (int i = 0; i < numIntervals; i++) {
		weightsArray[i] = intervals[i].weight;
	}
}

void WIS::PrintSortedIntervals() {
	std::cout << "Sorted Input Intervals by finishing time:\n"
		"\tIndex<i>\tS<i>\tF<i>\tW<i>\n";

	for (int i = 0; i < numIntervals; i++) {
		std::cout << std::right << "\t" << i + 1 << " " <<
			std::setw(15) << intervals[i].start <<
			std::setw(8) << intervals[i].finish <<
			std::setw(8) << intervals[i].weight << "\n";
	}
}

int WIS::FindMaxWeight() {
	if (numIntervals > 1) {
		for (int i = 1; i < numIntervals; i++) {
			for (int j = 0; j < i; j++) {
				if (intervals[j].finish <= intervals[i].start) {
					/*std::cout << "job " << j + 1 << " and job " << i + 1 <<
						" work together\n";*/
					int tempMax = weightsArray[j] + intervals[i].weight;
					if (tempMax >= weightsArray[i]) {
						weightsArray[i] = tempMax;
						intervals[i].previousJobIndex = j;
						/*std::cout << "job " << j + 1 << " and job " << i + 1 << 
							" work together and produce" << tempMax << "\n";*/
					}

				}

			}
		}
	}
	int maxWeightIndex = 0;
	for (int i = 0; i < numIntervals; i++) {
		//std::cout << "index: " << i << " weight " << weightsArray[i] << "\n";
		if (weightsArray[i] > weightsArray[maxWeightIndex]) {
			//std::cout << weightsArray[i] << ">" << maxWeightIndex << "\n";
			maxWeightIndex = i;
		}

	}
	//std::cout << maxWeightIndex << "\n";
	return maxWeightIndex;
}

int WIS::GetMaxWeight(int index) {
	return weightsArray[index];
}

void WIS::PrintJobsInvolved(int index) {
	std::string indices = std::to_string(index);
	int prev = intervals[index].previousJobIndex;
	while (prev >= 0) {
		indices += std::to_string(prev);
		prev = intervals[prev].previousJobIndex;
	}
	int len = indices.length();
	for (int i = len - 1; i >= 0; i--) {
		int tempIndex = indices[i] - '0';
		std::cout << "(" << intervals[tempIndex].start << " " <<
			intervals[tempIndex].finish << " " << intervals[tempIndex].weight << ")";
		if (tempIndex != index) {
			std::cout << ", ";
		}
	}
	
}