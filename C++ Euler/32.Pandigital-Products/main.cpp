#include <iostream>
#include <set>
using namespace std; 

/*
32. Pandigital Products
	we shall say that an n-digit number is pandigital if it makes use of all the
	digits 1 to n exactly once, e.g. 15234 is 1 through 5 pandigital
	the product 7254 is unusual, as the identity, 39 × 186 = 7254, containing
	multiplicand, multiplier, and product is 1 through 9 pandigital
	Find the sum of all products whose multiplicand/multiplier/product identity
	can be written as a 1 through 9 pandigital.
	 * make sure not to count products more than once
*/

bool isPandigital(bool used[], int n) {  // ensures the length of the number
	for (; n > 0; n /= 10) {
		if (used[n % 10])
			return false;                // returns false if % 10
		used[n % 10] = true;  // set value in list to true
	}
	return true;
}

int main() {
	set<int> s;  // set to store the products, also removes duplicates
	
	for (int i {2}; i < 60; i++) {
		bool used[10] = {true};
		if (!isPandigital(used, i)) 
			continue;
		int start {1234};
		if (i > 9)
			start = 123;
		bool temp[10];
		for (int j {start}; j * i < 10000; j++) {  // range is = 10000 // i
			memcpy(temp, used, 10);  // copies used to temp
			if (isPandigital(temp, j) && isPandigital(temp, i*j))
				s.insert(i*j);
		}
	}
	
	int sum {0};
	for (set<int>::iterator itr { s.begin() }; itr != s.end(); itr++) {
		cout << *itr << "\n";
		sum += *itr;
	}
	cout << sum << "\n";
	return 0;
}