#include <iostream>
#include <vector>
#include <cmath>
using namespace std; 

/*
12. Highly Divisible Triangular Number
	what is the value of the first triangle number
	to have over five hundred divisors?
	 * a triangular number or triangle number counts 
	   objects arranged in an equilateral triangle
	 * quickest way to find the factors of a number is to divide
	   by smallest prime -> x % prime == 0 -> until you reach 1
	 * nth Triangular number is Xn = n(n + 1) / 2 
*/

int* primeSieve(int limit) {
	int boundary = (int)(limit - 1) / 2;
	int upperSqrt = (int)((sqrt((double)limit) - 1) / 2);
	bool primeList[1000] = {false};
	int* numbers = new int[1000];
	int index {0};
	
	for (int i {2}; i <= upperSqrt; i++) {
		if (!primeList[i]) {
			for (int j = i * i; j <= boundary; j += i) {
				primeList[j] = true;
			}
			numbers[index++] = i;
		}
	}
	
	for (int i = upperSqrt + 1; i <= boundary; i++) {
		if (!primeList[i]) {
			numbers[index++] = i;
		}
	}
	numbers[index] = 0;
	return numbers;
}

int NOD(int number, int primelist[]) {
	int nod {1}, exp, remainder;
	remainder = number;
	
	for (int i {0}; primelist[i] != 0; i++) {
		if (primelist[i] * primelist[i] > number) {
			return nod * 2;
		}
		exp = 1;
		
		while (remainder % primelist[i] == 0) {
			exp++;
			remainder = remainder / primelist[i];
		}
		nod *= exp;
		
		if (remainder == 1) {  // if there is no remainder..
			return nod;
		}
	}
	return nod;
}


int main() {
	for (int i {1}; i <= 10; i++) {
		auto sieve = primeSieve(1000);
		int j {2}, cnt {0}, a {2}, b {2};
		
		while (cnt < 500) {
			if (j % 2 == 0) {
				b = NOD(j + 1, sieve);
			} else {
				a = NOD((j +1) / 2, sieve);
			}
			cnt = b * a;
			j++;
		}
		
		if (i == 1)
			cout << "the first Triangle number to have over 500 divisors : " 
				 << j * (j - 1) / 2 << "\n";
	}
	
	
	return 0;
}