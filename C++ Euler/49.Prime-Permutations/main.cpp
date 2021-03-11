#include <iostream>
#include <cmath>
#include <vector>
using namespace std; 

/*
49. Prime Permutations
	the arithmetic sequence, 1487, 4817, 8147, in which each term increases by 3330
	is unusual in two ways, first each of the three terms is prime, second, each of
	the 4-digit numbers are permutations of one another
	there are no arithmetic sequences made up of three 1-,2- or 3-digit primes with
	this property, but there is another 4-digit increasing sequence 
	What 12-digit number is formed by concatenating the three terms in the sequence?
*/

typedef unsigned int ui;

bool sieve[5000];
vector<ui> primes;

void getPrimes() {
	for (ui i {1}; i <= ((int)sqrt((double)10000) - 1) / 2; i++) {
		if (!sieve[i])
			for (ui j {2 * i * (i + 1)}; j <= 9999 / 2; j += 2 * i + 1)
				sieve[j] = true;
	}
	for (ui i {500}; i <= 9999 / 2; i++) {
		if (!sieve[i])
			primes.push_back(2 * i + 1);
	}
}

void nextSequence(ui digits, vector<ui> &primes, ui usedList[], ui current) {
	if (digits == 0) {
		if (current > 1000 && current % 2 && !sieve[(current - 1) / 2]) 
			primes.push_back(current);
		return;
	}
	for (ui n {0}; n < 10; n++) {
		if (usedList[n]) {
			usedList[n]--;
			nextSequence(digits - 1, primes, usedList, current * 10 + n);
			usedList[n]++;
		}
	}
}

int main() {
	getPrimes();
	for (ui p {0}; p < primes.size(); p++) {
		if (sieve[(primes[p] - 1) / 2]) 
			continue;
		
		vector<ui> list;
		ui unused[10] = {0};
		for (ui temp {primes[p]}; temp > 0; temp /= 10)
			unused[temp % 10]++;
		nextSequence(4, list, unused, 0);
		
		bool isPermPrime[10000] = {false};
		for (ui i {0}; i < list.size(); i++) {
			sieve[(list[i] - 1) / 2] = 1;
			isPermPrime[list[i]] = 1;
		}
		
		if (list.size() < 3 || primes[p] == 1487) 
			continue;
		for (ui i {0}; i < list.size() - 2; i++) {
			for (ui j {i + 1}; j < list.size() - 1 && 
			list[j] + list[j] - list[i] < 10000; j++) {
				if (isPermPrime[list[j] + list[j] - list[i]]) {
					cout << list[i] << list[j] << list[j] + list[j] - list[i] << "\n";
					return 0;
				}
			}
		}
	}
}