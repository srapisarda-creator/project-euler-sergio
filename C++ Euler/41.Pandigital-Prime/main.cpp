#include <iostream>
#include <string>
#include <algorithm>
using namespace std; 

/*
41. Pandigital Prime
	we shall say that an n-digit number is pandigital if it makes use of all the
	digits 1 to n exactly once, e.g. 2143 is a 4 digit pandigital and is also prime
	What is the largest n-digit pandigital prime that exists?
	 * the largest n-digit prime must start with a 7, as the sum of the digits upto
	 * n must not be divisible by 3 (i.e start with 9) as will not be pandigital
*/

bool isPrime(int n) {
	for (int p {2}; p * p <= n; p++) {
		if (n % p == 0)
			return false;
	}
	return true;
}

int main() {
	string s {"7654321"};  // highest starting point
	bool flag {false};
	while (!flag) {  // works backwards through prev_perm.. 
		int n = stoi(s);
		if (isPrime(n)) {  // check if prime
			cout << n  << "\n";
			flag = true;  // break
		}    // prev_permutation rearranges the elements in the range into
		prev_permutation(s.begin(), s.end());  // the previous lexicographically-
	}	                                       // ordered permutation
	return 0;
}