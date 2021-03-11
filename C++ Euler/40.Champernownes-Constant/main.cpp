#include <iostream>
#include <vector>
#include <string>
using namespace std; 

/*
40. Champernowne's Constant
	an irrational decimal fraction is created by concatenating the positive integers
	0.123456789101112131415161718192021... it can be seen that the 12th digit of the
	fractional part is 1 
	If dn represents the nth digit of the fractional part, find the value of the
	following expression -> d1 * d10 * d100 * d1000 * d10000 * d100000 * d1000000.
	 * running tests can see that 175000 < i < 200000, is the max number needed to
	 * reach d1000000
*/

typedef unsigned int ui;

int main() {
	vector<char> numbers;  // vector of characters
	for (ui i {0}; i <= 200000; i++) {
		string temp = to_string(i);  // convert int to string
		for (auto digit : temp)
			numbers.push_back(digit);  // push back each digit
	}
	int d1 = numbers[1] - '0';  // -'0' to convert to int value instead of char value
	int d10 = numbers[10] - '0';
	int d100 = numbers[100] - '0';
	int d1000 = numbers[1000] - '0';
	int d10000 = numbers[10000] - '0';
	int d100000 = numbers[100000] - '0';
	int d1000000 = numbers[1000000] - '0';
	
	cout << d1 * d10 * d100 * d1000 * d10000 * d100000 * d1000000 << endl;
	return 0;
}