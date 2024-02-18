#include <iostream>

#include "WISheader.h"

using namespace std;

int main() {
	cout << "++++ Weighted Interval Sheduling with Bottom up dynamic programming ++++\n";
	int numIntervals;
	WIS wis;
	cout << "Enter number of Intervals : ";
	cin >> numIntervals;
	wis.SetWIS(numIntervals);
	cout << "Enter Start time, Finish time and Weight separate by a space: \n"
		"Si  Fi  Wi\n";
	Interval temp;
	int tempS, tempF, tempW;
	for (int i = 0; i < numIntervals; i++) {
		cin >> tempS >> tempF >> tempW;
		temp.start = tempS;
		temp.finish = tempF;
		temp.weight = tempW;
		wis.AddInterval(temp);
	}

	wis.SortIntervals();
	cout << "\n";
	wis.PrintSortedIntervals();

	int index = wis.FindMaxWeight();
	cout << "\nMaximum profit of non-overlapping scheduling is " << wis.GetMaxWeight(index) << "\n\n";

	cout << "The jobs involved in the maximum profit are ";
	wis.PrintJobsInvolved(index);
	cout << "\n";

	return 0;
}


//TESTS

/*
1 2 4
1 4 6
4 7 9
3 9 10
*/

/*
1 4 2
2 6 4
3 9 7
8 10 2
5 8 4
8 11 3
*/