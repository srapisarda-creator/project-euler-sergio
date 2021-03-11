#include <iostream>
using namespace std;

/*
1. Multiples of 3 and 5
	Find the sum of all the multiples of 3 or 5 below 1000
	
	sum(x) = x * (x + 1) / 2
	find the sum of the multiples of 3, 5 
	 * and then 15 to account for instances of 3 & 5 being counted
*/

long long sum(long long x) {
	return x * (x + 1) / 2;
}

int main() {
	long long x;
	cin >> x;
	x--;
	auto sumThrees = 3 * sum(x / 3);
	auto sumFives = 5 * sum(x / 5);
	auto sumFifteen = 15 * sum(x / 15);
	
	cout << (sumThrees + sumFives - sumFifteen) << "\n";
    return 0;
}