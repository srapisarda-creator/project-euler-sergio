#include <iostream>
#include <string>
#include <algorithm>
using namespace std; 

/*
36. Double Base Palindromes
	the decimal number 585 (base 10) = 1001001001^^2 (base 2) is palindromic
	in both bases
	Find the sum of all numbers less than one million which are palindromic
	in base 10 and base 2. 
	 * each digit in a binary number represents a power of two, count the
	 * digits from the right - starting with 0, e.g. 101100101, numbering the
	 * digits: 876543210 -> 
	 * 1*2^8 + 0*2^7 + 1*2^6 + 1*2^5 + 0*2^4 + 0*2^3 + 1*2^2 + 0*2^1 + 1*2^0
	 * = 256 + 0 * 128 + 64 + 32 + 0 * 16 + 0 * 8 + 4 + 0 * 2 + 1
	 * = 256 + 64 + 32 + 4 + 1 = 357
	 * to  convert from base 10 to 2, divide by two and track the remainders
	 * 357/2=178 (r 1), 178/2=89 (r 0), 89/2=44 (r 1), 44/2=22 (r 0), 22/2=11 (r 0),
	 * 11/2=5 (r 1), 5/2=2 (r 1), 2/2=1 (r 0) -> 101100101 (start from the right)
*/

typedef unsigned int ui;

ui bin(ui n) {  // convert base 10 integer to base 2 
	ui binaryNumber {0}, remainder, i {1}; 
	while (n != 0) {
		remainder = n % 2;
//		ui step {1};
//		cout << "Step " << step++ << ": " << n << "/2, Remainder = " 
//			<< remainder << "\n";
		n /= 2;
		binaryNumber += remainder * i;
		i *= 10;
	}
	return binaryNumber;
}

string numString(ui x, ui base) {  // converts num in either base to a string
	string result;
	while (x > 0) {
		auto digit = x % base;
		x /= base;
		result.insert(0, 1, char(digit + '0'));
	}
	return result;
}

bool isPalindrome(string& x) {  // check if the string is palindromic
	auto other = x;
	reverse(other.begin(), other.end());
	return other == x;
}

int main() {
	ui sum;
	for (ui x {1}; x < 1000000; x++) {
		string val = numString(x, 10);
		string binVal = numString(x, 2);
		if (isPalindrome(val) && isPalindrome(binVal)) {
			sum += x;
			cout << "x: " << x << " sum: " << sum << "\n";
		}
	}
	cout << sum << "\n";
	return 0;
}