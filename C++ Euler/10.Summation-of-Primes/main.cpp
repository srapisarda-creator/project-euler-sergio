#include <iostream>
#include <vector>
using namespace std; 

/*
10. Summation of Primes
	the sum of all primes below 10 is 17 = 2 + 3 + 5 + 7
	find the sum of all primes below two million.
	 * 2 is the only even prime, loop through odd numbers and check if prime
	 * use the sieve of eratosthenes to efficiently find primes
	 * 	find multiples of p to flag notPrime faster
*/
typedef unsigned long long ull;

 ull sumPrimes(ull x) {
	 ull sum {0};
	 vector<bool> sieve ((x + 1), true);  // use a vector to create the sieve
	 for (ull p {2}; p <= x; p++) {       // size of vector is (x + 1)
		 if (sieve[p]) {                  // set to true by default  
			sum += p;          
			for (ull i {p * p}; i <= x; i += p) {
				sieve[i] = false;
			}
		 }
	 }
	 return sum;
 }

int main() {
	cout << sumPrimes(2000000) << endl;
	return 0;
}