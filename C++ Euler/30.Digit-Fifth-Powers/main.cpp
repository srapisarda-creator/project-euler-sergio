#include <iostream>
using namespace std; 

/*
30. Digit Fifth Powers
	Find the sum of all the numbers that can be written as the sum of
	fifth powers of their digits.
	 * split the number into its digits
	 * check if the sum of digits value when raised to ^5 is equal to the
	 * original number
*/

typedef unsigned int ui;

int main() {
	ui answer {0};
	for (ui i {2}; i < 354295; i++) {  // limit is 354294, max sum for 6 digits
		ui digitsFithSum {0}, red {i};
		while (red > 0) {
			ui digit = red % 10;
			red /= 10;
			ui power {1};
			for (ui j {1}; j <= 5; j++) {
				power *= digit;
			}
			digitsFithSum += power;
		}
		if (digitsFithSum == i) {
			answer += i;
			cout << answer << " " << i << "\n";
		}
	}
	cout << answer << "\n";
	
	return 0;
}