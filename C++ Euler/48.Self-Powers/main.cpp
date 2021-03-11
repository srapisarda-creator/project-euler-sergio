#include <iostream>
using namespace std; 

/*
48. Self Powers
	the series 1^1 + 2^2 .. 10^10 = 10405071317
	Find the last ten digits of the series 1^1 + 2^2 .. + 1000^1000.
	 * a^b, a, b <= 1000
	 * use modulo 1e10 (% 10,000,000,000) to access the last ten digits
*/

typedef unsigned long long ull;

int main() {
	ull ans = 0;
	for (int a {1}; a <= 1000; a++) {
		ull temp {1};
		for (int b {1}; b <= a; b++) {
			temp = (temp * a) % 10'000'000'000; 
		}
		ans = (temp + ans) % 10'000'000'000;
	}
	cout << ans << "\n";
	return 0;
}