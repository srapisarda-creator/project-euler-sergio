#include <iostream>
#include <vector>
#include <string>
using namespace std; 

/*
20. Factorial Digit Sum
	find the sum of the digits in the number 100!
*/

typedef unsigned long long ull;
typedef unsigned int ui;
typedef uint64_t ui64;

static const int sizeLim {158};  //  there are 158 digits in 100!

int factorialDigitSum(int amount) {
	int digits[sizeLim] = {0};
	digits[0] = 1;
	int sum {0};
	int lim {2};
	
	for (int factor {2}; factor < amount; factor++) {
		int carry {0};
		for (int j {0}; j <= lim; j++) {
			int x = digits[j] * factor + carry;
			carry = 0;
			sum = x;
			if (x > 9) {
				sum = x % 10;
				carry = x / 10;
				if (j == lim) {
					lim += 2;
				}
			}
			digits[j] = sum;
		}
	}
	int answer {0};
	for (int i {0}; i < lim; i++) {
		answer += digits[i];
	}
	return answer;
}

int main() {
	cout << factorialDigitSum(100) << "\n";
	
	
	return 0;
}