#include <iostream>
#include <set>
#include <vector>
#include <cmath>

using namespace std; 

/*
29. Distinct Powers
	consider all integer combinations of a^b for 2<=a<=5 and 2<=b<=5
	if they are all placed in numerical order, with duplicates removed, we get the 
	following sequence 4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125
	How many distinct terms are in the sequence a^b for 2<=a<=100 and 2<=b<=100?
	 * as the upper limits of the values of a and b are very large, fastest way is to 
	 * generate a list of primes and check the prime divisors of the number
	 * this also helps with duplicates
*/

bool isPrime(int num) {
	if (num <= 1) 
		return false;
	for (int i {2}; i < (int)sqrt(num) + 1; i++) {
		if (num % i == 0) 
			return false;
	}
	return true;
}

vector<int> primeDivisors(int num, int power) {
	vector<int> temp;
	if (isPrime(num)) {
		for (int pwr {0}; pwr < power; pwr++) {
			temp.push_back(num);
		}
		return temp;
	}
	for (int i {2}; i <= ceil(num / 2); i++) {
		if (isPrime(i)) {
			int n = num;
			while (n % i == 0) {
				for (int repeat {0}; repeat < power; repeat++)
					temp.push_back(i);
				n /= i;
			}
		}
	}
	return temp;
}


int main() {
	set<vector<int>> answer;
	for (int a {2}; a <= 100; a++) {
		for (int b {2}; b <= 100; b++) {
			vector<int> item = primeDivisors(a, b);
			answer.insert(item);
		}
	}
	cout << answer.size() << "\n";
	return 0;
}