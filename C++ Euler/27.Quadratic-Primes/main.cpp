#include <iostream>
#include <cmath>
using namespace std; 

/*
27. Quadratic Primes
	considering quadratics of the form n^2 + an + b, |a| < 1000, |b| <= 1000
	Find the product of the coefficients a and b, for the quadratic expression
	that produces the maximum number of primes for consecutive values of n, from n=0.
*/

typedef unsigned int ui;

bool isPrime(int num) {
	if (num <= 1)
		return false;
	if (num == 2)
		return true;
	for (int factor {3}; factor * factor <= num; factor++) {
		if (num % factor == 0)
			return false;
	}
	return true;
}

int main() {
	ui current {0};
	for (int a {-1000}; a <= 1000; a++) {
		for (int b {-1000}; b <= 1000; b++) {
			ui count {0};
			while(isPrime(count * count + a * count + b))
				count++;
				
			if (current < count) {
				current = count;
				cout << "a: " << a << "\n";
				cout << "b: " << b << "\n";
				cout << (a * b) << "\n";
			}
		}
	}
	return 0;
}