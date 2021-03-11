#include <iostream>
#include <cmath>
using namespace std; 

/*
35. Circular Primes
	the number 197 is a circular prime as all rotations of its digits
	197, 971, and 719 are all prime respectively, there are 13 such primes below 100
	2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97
	How many circular primes are there below one million?
	 * every prime that contains an even digit cannot be circular as there is a
	 * rotation which ends with an even digit, the same applies with the digit 5
*/

bool isPrime(int n) {
	if (n == 2 || n == 3)
		return true;
	if (n % 2 == 0)
		return false;
	for (int i {3}; i <= sqrt(n); i += 2)
		if (n % i == 0)
			return false;
	return true;
}

int main() {
	int sum;
	for (int prime {2}; prime <= 1000000; prime++) {
		if (!isPrime(prime)) 
			continue;
		int i { prime }, digit { int(pow(10, int(log10(prime)) + 1)) };
		do {
			i *= 10;
			i = i / digit + i % digit;
			if (!isPrime(i))
				break;
		} while (i != prime);
		if (!isPrime(i))
			continue;
		cout << "Prime " << sum << " : " << prime << "\n";
		sum++;
	}
	cout << sum << "\n";
	return 0;
}