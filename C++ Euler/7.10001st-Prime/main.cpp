#include <iostream>
#include <vector>
using namespace std;

/*
7. 10001st Prime
	what is the 10,001st prime number?
	
*/

int main() {
	vector<int> primes;
	primes.reserve(10001);  // use reserve to allocate space for vector
	primes.push_back(2);  // 2 is the only positive prime
	                     // add it now, so only search for odd numbers later
	for (int  x {3}; primes.size() <= 10000; x += 2) {
		bool isPrime = true;  // true by default
		for (auto p : primes) {
			if ( x % p == 0) {  // if a divisor is found, break
				isPrime = false;
				break;
			}
			if (p * p > x)  // no larger prime factors, break
				break;
		}
		if (isPrime) {
			primes.push_back(x);
//			cout << x << "\n";
		}
	}
	cout << primes[10000] << "\n";  // index starts at 0 for list of Primes
	return 0;
}