#include <iostream>
#include <vector>
using namespace std; 

/*
26. Reciprocal Cycles
	Find the value for d < 1000 for which 1/d contains the longest 
	recurring cycle in its decimal fraction.
	 * instead of using floats use whole numbers, to calculate % 
	 * use long division in cycles()
*/
typedef unsigned int ui;

ui cycles(ui x) {
	if (x == 0) {
		cerr << "Input cannot be <= 0.\n";
		return 0;
	}
	const ui check {0};
	vector<ui> lastPos(x, check);
	ui pos {1};
	ui div {1};
	while (true) {
		ui rem = div % x;
		if (rem == 0)
			return 0;
		
		if (lastPos[rem] != check)
			return pos - lastPos[rem];
		
		lastPos[rem] = pos;
		pos++;
		div = rem * 10;
	}
}

int main() {
	vector<ui> listOfCycles = { 0 };  
	ui longestDenom {0}, longest {0};
	
	for (ui i {1}; i < 1000; i++) {
		ui current = cycles(i);
		if (longest < current) {
			longest = current;
			longestDenom = i;
		}
		listOfCycles.push_back(longestDenom);
	}
	cout << listOfCycles[999] << "\n";
	return 0;
}