#include <iostream>
using namespace std; 

/*
34. Digit Factorials
	145 is a curious number,as 1!+4!+5! = 1+24+120 = 145
	Find the sum of all numbers which are equal to the sum
	of the factorial of their digits.
	 * 1! and 2! are not included as they are not sums
*/

int main() {
	int factorials[10] = {true};
	for (int i {1}; i < 10; i++) {  // pre-compute 0! -> 9!
		factorials[i] = factorials[i-1] * i;
	}
	int totalSum {0};
	for (int i {3}; i < 50000; i++) {
		int temp {i}, factorialSum {0};  // using % 10 here to access right-most digit
		for (; temp > 0; factorialSum += factorials[temp % 10], temp /= 10);
		if (factorialSum == i)
			totalSum += i;
	}
	cout << totalSum << "\n";
	return 0;
}