#include <iostream>
#include <string>
#include <algorithm>
using namespace std; 

/*
38. Pandigital Multiples
	take the number 192 and multiply it by each of 1,2 and 3
	192 x 1 = 192,  192 x 2 = 384, 192 x 3 = 576
	by concatenating each product we get the 1 to 9 pandigital, 192384576
	What is the largest 1 to 9 pandigital 9-digit number that can be formed
	as the concatenated product of an integer (1,2..n) where n > 1? 
	 * cannot multiply by a 5 digit number is this will lead to a product
	 * that is at least 10 digits long
*/

int numDigits(int n) {  // counts the number of digits in n
	int count {0};
	while (n > 0) {
		n /= 10;
		count++;
	}
	return count;
}

bool pandigital(int n) {  // checks if n is pandigital 
	bool digits[10] = {false};
	while (n > 0) {
		if (digits[n % 10] == true || n % 10 == 0) 
			return false;
			
		digits[n % 10] = true;  // move to next digit
		n /= 10;
	}
	for (int i {1}; i <= 9; i++) {  // check
		if (digits[i] == false)
			return false;
	}
	return true;
}

int main() {
	int largest {0};
	for (int i {1}; i < 10000; i++) {  // i {9000}; i < 9500 - narrows the search
		int current {i};
		int j {2};  // j = i + 1
		while (current < 123456789) {
			for (int g {0}; g < numDigits(i * j); g++)
				current *= 10;
			current += i * j;
			j++;
		}
		if (pandigital(current) && current > largest)
			largest = current;
	}
	cout << largest << "\n";
	return 0;
}