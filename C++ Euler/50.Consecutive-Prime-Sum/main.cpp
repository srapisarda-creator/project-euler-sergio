#include <iostream>
#include <cmath>
#include <vector>
using namespace std; 

/*
50. Consecutive Prime Sum
	the prime 41 can be written as the sum of six consecutive primes:
	2 + 3 + 5 + 7 + 11 + 13 = 41, this is the longest sum of consecutive primes that
	add to a prime below one hundred, the longest sum of consecutive primes below
	one thousand that adds to a prime contains 21 terms, is equal to 953
	Which prime, below one million, can be written as the sum of the most 
	consecutive primes?
	 * generate list of primes, check the number of prime factors
	 * loop backwards in list of primes to check larger numbers first
*/

typedef unsigned int ui;

bool sieve[550000];
vector<ui> primes;

void getPrimes() {
	for (ui i {1}; i <= ((int)sqrt((double)1000000) - 1) / 2; i++) {
		if (!sieve[i])
			for (ui j {2 * i * (i + 1)}; j <= 1000000 / 2; j += 2 * i + 1)
				sieve[j] = true;
	}
	primes.push_back(2);
	for (ui i {1}; i <= 1000000 / 2; i++) {
		if (!sieve[i])
			primes.push_back(2 * i + 1);
	}
}

int main() {
	getPrimes();	
	vector<ui> cPrimes(primes.size());
	ui factors {0};
	for (ui p {1}; p < primes.size(); p++) {
		cPrimes[p] = cPrimes[p - 1] + primes[p - 1];
		if (factors == 0 && cPrimes[p] > 1000000) {
			factors = p - 1;
			
			for (ui i {factors}; i > 0; i--) {
				for (int j {0}; ; j++) {
					ui prime = cPrimes[j + i] - cPrimes[j];
					
					if (prime > 1000000)
						break;
					
					if (prime % 2 && !sieve[(prime - 1) / 2]) {
						cout << prime << " " << factors << "\n";
						return 0;
					}
				}
			}
		}
	}
}