#include <iostream>
#include <cmath>
#include <vector>
using namespace std; 

/*
45. Triangular, Pentagonal and Hexagonal
	triangle    Tn = n(n + 1) / 2  -> 1,3,6,10,15...
	pentagonal  Pn = n(3n - 1) / 2 -> 1,5,12,22,35...
	hexagonal   Hn = n(2n - 1)     -> 1,6,15,28,45... 
	it can be verified that T285 = P165 = H143 = 40755
	Find the next triangle number that is also pentagonal and hexagonal.
	 * all hexagonal numbers are triangular also
*/
typedef unsigned long long ull;

int main() {
	vector<ull> triPenHexNums;
	for (ull n {1}; ; n++) {
		ull h = n * (2 * n - 1);
		double p = (sqrt(24 * h + 1.) + 1) / 6;
		if (p == (int)p) {
			triPenHexNums.push_back(h);
		}
		if (triPenHexNums.size() == 5) {  // stops when first 5 terms that 
			for (auto n : triPenHexNums)  // match are found
				cout << n << endl;
			return 0;
		}
	}
	
}