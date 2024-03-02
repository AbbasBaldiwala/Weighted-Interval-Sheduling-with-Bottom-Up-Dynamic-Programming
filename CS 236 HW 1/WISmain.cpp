//Abbas Baldiwala CS 236
// Weighted Interval Sheduling with Bottom up dynamic programming

#include <iostream>
#include <limits>

#include "WISheader.h"

using namespace std;

void ClearInvalidInput(string errMsg);

int main() {
	cout << "++++ Weighted Interval Sheduling with Bottom up dynamic programming ++++\n";
	int numIntervals;
	WIS wis;
	bool invalid = true;
	while (invalid) {
		cout << "Enter number of Intervals : ";
		cin >> numIntervals;
		if (!cin.good()) {
			ClearInvalidInput("INVALID INPUT");
		}
		else if (numIntervals <= 0) {
			ClearInvalidInput("INVALID INPUT, MUST BE GREATER THAN 0");
		}
		else {
			invalid = false;
		}
	}
	wis.SetWIS(numIntervals);
	cout << "Enter Start time, Finish time and Weight separate by a space: \n"
		"Si  Fi  Wi\n";
	Interval temp;
	int tempS, tempF, tempW;
	for (int i = 0; i < numIntervals; i++) {
		cin >> tempS >> tempF >> tempW;

		if (!cin.good()) {
			ClearInvalidInput("INVALID INPUT");
			i--;
		}
		else if (tempS < 0 || tempF <= 0 || tempW < 0) {
			ClearInvalidInput("INVALID INPUT, NUMBERS MUST BE POSITIVE");
			i--;
		}
		else if (tempS >= tempF) {
			ClearInvalidInput("INVALID INPUT, END TIME MUST BE GREATER THAN START TIME");
			i--;
		}
		else {
			temp.start = tempS;
			temp.finish = tempF;
			temp.weight = tempW;
			wis.AddInterval(temp);
		}
		
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

void ClearInvalidInput(string errMsg) {
	cout << "\n" << errMsg << "\n";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

/*
0 3 6
3 4 9
0 5 15
9 12 8
5 9 6
7 13 10
6 8 2
14 17 12
20 24 5
9 11 4
*/