#include <iostream>
using namespace std;

/*
4. Largest Palindrome Product
	find the largest palindrome made from the product of two 3-digit numbers
	 * will use two for loops, counting backwards from 999
	 * this will calculate the product of i * j
	 * check if this is a palindrome
	 * find the largest
*/
bool isPalindrome(int x) {
	bool found = false;
	int digit, reverse = 0, check;
	check = x;
	
	while (x) {
		digit = x % 10;
		x /= 10;
		reverse = reverse * 10 + digit;
	}
	if (reverse == check)
		found = true;
	return found;
}

int main() {
	int palindrome, final;
	
	for (int i {999}; i >= 100; i--) {
		for (int j {999}; j >= 100; j--) {
			palindrome = i * j;
			if (isPalindrome(palindrome)) {
				cout << palindrome << "\n";
				if (isPalindrome(palindrome) && palindrome > final)
					final = palindrome;
			}
		}
	}
	cout << "The largest Palindrome is: " << final << "\n";
	return 0;
}

