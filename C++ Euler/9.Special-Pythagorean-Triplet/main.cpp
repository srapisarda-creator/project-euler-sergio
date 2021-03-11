#include <iostream>
using namespace std; 

/*
9. Special Pythagorean Triplet
	a^2 + b^2 = c^2
	there exists only one Pythagorean triplet for which
	a + b + c = 1000.  Find the product abc	
	 * refactor the expression to find -> c = 1000 - a - b
*/

int findTriplet(int x) {
	int triplet {0}, c {0};
	for (int a {1}; a <= x; a++) {
		for (int b {a + 1}; b <= x - a; b++) {
			c = x - a - b;
			if ((a * a) + (b * b) == (c * c)) {
				triplet = a*b*c;				
			}
			else 
				continue;
		}
	}
	return triplet;
}

int main() {
	cout << findTriplet(1000) << "\n";
	return 0;
}