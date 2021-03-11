#include <iostream>
#include <cmath>
#include <vector>
using namespace std; 

/*
46. Goldbach's Other Conjecture
	it was proposed by Christian Goldbach that every odd composite number can be 
	written as the sum of a prime and twice a square
	9 = 7 + 2 * 1^2, 15 = 7 + 2×2^2, 21 = 3 + 2×3^2, 25 = 7 + 2×3^2
	it turns out the conjecture was false
	What is the smallest odd composite that cannot be written as the sum of 
	a prime and twice a square?
	 * modify the Sieve of Erastothenes to generate composite numbers, and 
	 * keep track of all prime numbers below it
*/

bool sieve[(10000 - 1) / 3];

void getPrimes() {
	for (int i = 1; i <= ((int)sqrt((double)10000) - 1)/2; i++)
		if (!sieve[i])
			for (int j = 2*i*(i+1); j <= (10000 - 1)/2; j += 2*i+1)
				sieve[j] = 1;
}

int main() {
	getPrimes();
	for (int i {1}; i < 10000; i += 2) {
		if (!sieve[(i - 1) / 2]) 
			continue;
		bool flag = true;
		for (int j = 1; flag && 2 * j * j < i; j++)
			if (!sieve[(i - 2 * j * j - 1) / 2])
				flag = false;
		if (flag) {
			cout << i << "\n";
			break;
		}
	}
}