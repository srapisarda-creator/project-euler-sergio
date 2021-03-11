#include <iostream>
#include <algorithm>
using namespace std;

/*
5. Smallest Multiple
	what is the smallest positive number that is evenly divisible by all 
	of the numbers from 1 to 20?
	 * to find LCM (smallest multiple) 
*/
int leastCommonMultiple(int num) {
	int ans = 1;
	for (int i {1}; i <= num + 1; i++) {
		ans = ans * (i / __gcd(ans, i));
	}
	return ans;
}

int main() {
	cout << leastCommonMultiple(20) << endl;
	return 0;
}