#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std; 

/*
23. Non-Abundant Sums
	a perfect number is a number for which the sum of its proper divisors is exactly
	equal to the number, e.g. 1+2+4+7+14=28. A number is n is deficient if the sum of
	its proper divisors is less than n, or vice versa called abundant.
	Find the sum of all the positive integers which cannot be written as the sum 
	of two abundant numbers.
*/

typedef unsigned int ui;
typedef unsigned long long ull;

int sumOfDivisors(int n) {
	int upper = n;
	int i {2}, total {1};
	while (i < upper) {
		if (n % i == 0){
			upper = n / i;
			total += upper;
			if (upper != i)
				total += i;
		}
		i++;
	}
	return total;
}

bool isAbundant(int n) {  // returns true if n is abundant
	return sumOfDivisors(n) > n;
}

const ui start {28124};  // limit to test to
set<ui> abundant;        // container for abundant numbers

ui getSum(ui x) {
	ui divisorSum {1};
	for (ui divisor {2}; divisor * divisor <= x; divisor++) {
		if (x % divisor == 0) {
			divisorSum += divisor;
			
			ui otherDivisor = x / divisor;
			if (otherDivisor != divisor) 
				divisorSum += otherDivisor;
		}
	}
	return divisorSum;
}

bool isAbundantSum(ui x) {  // returns true if x is sum of abundant numbers
	if (x >= start) 
		return true;
	
	for (auto i : abundant) {
		if (i >= x)
			return false;
		
		ui other = x - i;
		if (abundant.count(other) == 0)
			continue;
		return true;
	}
	return false;
}


int main() {
	cout << isAbundant(12) << "\n";
	
	for (ui i {12}; i < start; i++) {
		if (getSum(i) > i) {
			abundant.insert(i);
		}
	}
	
	ull sum {0};
	for (ui i {0}; i < start; i++) {
		if (!isAbundantSum(i))  
			sum += i;
	}
	cout << sum << "\n";
	return 0;
}