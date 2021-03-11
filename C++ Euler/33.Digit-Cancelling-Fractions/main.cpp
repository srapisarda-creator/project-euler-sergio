#include <iostream>
using namespace std; 

/*
33. Digit Cancelling Products
	the fraction 49/98 is a curious fraction, 49/98 = 4/8
	 * however the fraction 30/50 = 3/5 is a trivial example
	there are exactly four non-trivial examples of this type of fraction, less than
	one in value, and containing two digits in the numerator and denominator
	If the product of these four fractions is given in its lowest common terms, find 
	the value of the denominator.
*/

int main() {
	int numerator = 1, denominator = 1;
	for (int d = 11; d < 100; d++) {  // for loop for denominator
		if (d % 10 == 0) 
			continue;
		for (int n = 10; n < d; n++) {  // for numerator
			if (n % 10 == 0) // if % 10 == 0, continue
				continue;
			double value = double(n)/d;
			if ((d % 10 == n % 10 && double(n/10)/(d/10) == value) ||
				(d/10 == n % 10 && double(n/10)/(d % 10) == value) ||
				(d % 10 == n/10 && double(n % 10)/(d/10) == value) ||
				(d/10 == n/10 && double(n % 10)/(d % 10) == value)) {
					numerator *= n;
					cout << "Numerator: " << numerator << "\n";
					denominator *= d;
					cout << "Denominator: " << denominator << "\n";
			}
		}
	}
	cout << "\n";
	for (int n = 2; n <= numerator; n++) {
		for (; numerator % n == 0 && denominator % n == 0; 
		numerator /= n, denominator /= n) {
			cout << "numerator: " << numerator << "\n";
			cout << "denominator: " << denominator << "\n";
		}
	}
	cout << "\nAnswer: " << denominator << "\n";
	return 0;
}