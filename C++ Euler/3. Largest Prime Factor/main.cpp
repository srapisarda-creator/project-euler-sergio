#include <iostream>
using namespace std;

/*
3. Largest Prime Factor
	the prime factors of 13195 are 5, 7, 13 and 29
	what is the largest prime factor of the number 600851475143?
*/

int main() {
	long long x {600851475143};
	
	for (long long i {2}; i * i <= x; i++) {
		while (x % i == 0 && x != i)  // cancel when x == i 
			x /= i;					  // this is the largest prime
	}
	
	cout << x << "\n";
	return 0;
}