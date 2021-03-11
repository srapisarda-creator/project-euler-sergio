#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std; 

/*
43. Sub-String Divisibility
	the number 1406357289 is a 1->9 pandigital and has an interesting sub-string
	property, let d1 be the first digit, d2 the second..
	d2d3d4=406 is divisible by 2, d3d4d5=063 is divisible by 3,
	d4d5d6=635 is divisible by 5, d5d6d7=357 is divisible by 7
	Find the sum of all 0->9 pandigital numbers with this property.
	 * divisible by a prime
*/

int main() {
	long long sum {0};
	int perms[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	do {
		if (perms[0] && (perms[1] * 100 + perms[2] * 10 + perms[3]) % 2 == 0 && 
			(perms[2] * 100 + perms[3] * 10 + perms[4]) % 3 == 0 &&
			(perms[3] * 100 + perms[4] * 10 + perms[5]) % 5 == 0 &&
			(perms[4] * 100 + perms[5] * 10 + perms[6]) % 7 == 0 &&
			(perms[5] * 100 + perms[6] * 10 + perms[7]) % 11 == 0 &&
			(perms[6] * 100 + perms[7] * 10 + perms[8]) % 13 == 0 &&
			(perms[7] * 100 + perms[8] * 10 + perms[9]) % 17 == 0 ) {
				for (int i=0; i<10; i++ )
					sum += perms[i] * pow(10, 9-i);
            }
    } while (next_permutation(perms,perms+10));
	
	cout << sum << "\n";
	
	return 0;
}