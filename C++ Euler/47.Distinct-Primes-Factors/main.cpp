#include <iostream>
using namespace std; 

/*
47. Distinct Primes Factors
	the first two consecutive numbers to have two distinct prime factors are:
	14 = 2 * 7, 15 = 3 * 5
	the first three consecutive numbers to have three distinct prime factors are:
	644 = 2^2 * 7 * 23, 645 = 3 * 5 * 43, 646 = 2 * 17 * 19
	Find the first four consecutive integers to have four distinct prime factors 
	each.  What is the first of these numbers?
*/

int distinctPrimeFactors(int n) {
	bool flag {false};
	int count {0}, divider {2};
	while (n > 1) {
		while (n % divider == 0) {
			n /= divider;
			flag = true;
		}
		if (flag) {
			count++;
			flag = false;
		}
		if (divider == 2) 
			divider++;
		else
			divider += 2;
	}
	return count;
}


bool fourFactors(int n) {
	bool flag {true};
	for (int i {0}; i < 4 && flag; i++)
		flag = distinctPrimeFactors(n + i) == 4;
	return flag;
}

int main() {
	int num {2};
	while(!fourFactors(num)) {
		num++;
	}
	cout << num << "\n";
	
	return 0;
}