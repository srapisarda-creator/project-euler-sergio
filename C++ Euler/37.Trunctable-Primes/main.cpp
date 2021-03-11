#include <iostream>
#include <vector>
#include <cmath>
using namespace std; 

/*
37. Trunctable Primes
	the number 3797 has an interesting property, being prime itself, it is possible
	to continuously remove digits from either left->right or right->left
	3797, 797, 97, 7 or 3797, 379, 37, 3
	Find the sum of the only eleven primes that are both truncatable from left to
	right and right to left.
	
*/

typedef unsigned int ui;

char sieve[1000001];  // sieve of eratosthenes
vector<int> primes;

void getPrimes() {  // generate list of primes
	for (int p {4}; p <= 1000000; p += 2) 
		sieve[p] = true;
	for (int i {3}; i <= sqrt((double)1000000); i++) {
		if (!sieve[i]) {
			for (int j {i*i}; j <= 1000000; j += i) {
				sieve[j] = true;
			}
		}
	}
	for (int n {2}; n <= 1000000; n++) {  
		if (!sieve[n])
			primes.push_back(n);  // list of all primes for lookup
	}
}

int truncatable(int n, bool dir) {
	if (dir)  // right truncatable
		return n / 10;
	int place {1};
	for (int tempN {n}; tempN > 9; tempN /= 10) 
		place *= 10;
	while (n > place)  // left truncatable
		n -= place;
	return n;
}

int main() {
	getPrimes();
	vector<int> truncatablePrimes;
	
	for (ui p {0}; p < primes.size(); p++) {
		if (primes[p] < 10) {
			sieve[primes[p]] = 5;
			continue;
		}
		int right = truncatable(primes[p], 1);
		int left = truncatable(primes[p], 0);
			
		if (sieve[right] == 3 || sieve[right] == 5) 
			sieve[primes[p]] += 3;
		
		if (sieve[left] == 2 || sieve[left] == 5)
			sieve[primes[p]] += 2;
			
		if (sieve[primes[p]] == 5) {
			truncatablePrimes.push_back(primes[p]);
		}
	}
	ui sum {0}, cnt {1};
	for (auto p : truncatablePrimes) {
		sum += p;
		cout << cnt << "  : " << p << "\n";
		cnt++;
	}
	cout << sum << "\n";
	return 0;
}