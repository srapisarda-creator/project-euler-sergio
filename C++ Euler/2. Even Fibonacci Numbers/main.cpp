#include <iostream>
using namespace std;

/*
2. Even Fibonacci Numbers
	by considering the terms in the Fibonacci sequence whose values 
	do not exceed four million, find the sum of the even-valued terms
*/

int main() {
	long long a {1}; // first term of sequence
	long long b {1}; // second term of sequence
	long long sum {0};
	while (a <= 4000000) {
		if (a % 2 == 0)
		  sum += a;
	
	auto next = a + b;
	a = b;
	b = next;  // use next to change the value of b
	}
	
	cout << sum << "\n";
	return 0;
}