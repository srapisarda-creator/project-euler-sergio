#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

/*
21. Amicable Numbers
	let d(n) be defined as the sum of the proper divisors of n (divide evenly into n)
	if d(a) = b && d(b) = a, a != b, a & b are an amicable pair
	Evaluate the sum of all amicable numbers under 10000.
*/

typedef unsigned long long ull;
typedef unsigned int ui;
typedef uint64_t ui64;

int amicableNumbersSum(int limit) {
	int a {0}, b {0}, sum {0};
	for (int i {1}; i < limit; i++) {
		a = 0;
		for (int j {1}; j < i; j++) {
			if (i % j == 0)
				a += j;
		}
		b = 0;
		for (int k {1}; k < a; k++) {
			if (a % k == 0)
				b += k;
		}
		if (b == i  && b != a) {
			sum += i;
			cout << i << endl;
		}
	}
	return sum;
}

int main() {
	cout << amicableNumbersSum(10000) << "\n";    
	return 0;
}