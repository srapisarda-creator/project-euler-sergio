#include <iostream>
#include <vector>
#include <cmath>
using namespace std; 

/*
28. Number Spiral Diagonals
	starting with the number one and moving clockwise, a 5 by 5 spiral is formed:
				21 22 23 24 25
				20  7  8  9 10
				19  6  1  2 11  it can be verified the sum of the diagonals is 101
				18  5  4  3 12
				17 16 15 14 13
	What is the sum of the diagonals in a 1001 by 1001 spiral formed the same way?
	 * the sum of the diagonals is summarised to
	 * f(n) = 4(2n + 1) ^ 2 - 12n + f(n - 1)
*/

typedef unsigned int ui;

ui spiralSum(ui n) {
	if (n < 1 || n % 2 == 0) {
		cerr << n << "\n";
		return 0;
	}
	vector<ui> numbers;
	numbers.push_back(1);
	while (numbers.size() < (2 * n - 1)) {
		ui increment = numbers.size() * 0.5 + 1.5;
		for (int p {0}; p < 4; p++) {
			numbers.push_back(numbers.back() + increment);
		}
	}
	ui numberSum {0};
	for (auto num : numbers) {
		numberSum += num;
	}
	return numberSum;
}


int main() {
	cout << spiralSum(1001) << "\n";
	return 0;
}