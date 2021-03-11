#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

/*
16. Power Digit Sum
	2^15 = 32768, and the sum of its digits (3+2+7+6+8) = 26
	what is the sum of the digits of the number 2^1000?
*/

typedef unsigned long long ull;
typedef unsigned int ui;
typedef uint64_t ui64;

ui64 power(ui64 num, ui64 pow) {  // created a manual method of pow() from cmath
	if (pow == 0)
		return 1;
	else if (pow % 2 == 0)
		return power(num, pow / 2) * power(num, pow / 2);
	else
		return num * power(num, pow / 2) * power(num, pow / 2);
}

string numToString(ui64 num) {     // converts a number to a string
	string s;
	s = to_string(num);
	return s;
}
// 2^1000 is too large to store as a single int, or even ull

int powerDigitSum(size_t max) {
	vector<int> numbers;
	numbers.push_back(1);
	
	for (size_t i {0}; i < max;  i++) {   // manually multiply value of power
		int carry {0};                    // store the ans as digits in a vector
		for_each(numbers.begin(), numbers.end(), [&carry](int& n) {
			n *= 2;
			n += carry;
			carry = (n >= 10) ? 1 : 0;
			n -= (carry * 10);
		});
		if (carry != 0)
			numbers.push_back(carry);
	}
	int total {0};
	for (auto ptr {numbers.rbegin()}; ptr != numbers.rend(); ptr++) {
		total += *ptr;    // use the *pointer to iterate and access value of digit
	}
	return total;
}

int main() {
	cout << power(2, 15) << "\n";
	string test = numToString(power(2, 15));
	for (auto c : test)
		cout << c << "\n";  // success
	
	cout << powerDigitSum(15) << "\n";
	cout << powerDigitSum(1000) << "\n";
	
	return 0;
}