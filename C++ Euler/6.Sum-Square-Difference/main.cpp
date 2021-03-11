#include <iostream>
#include <cmath>
using namespace std;

/*
6. Sum Square Difference
	find the difference between the sum of the squares of the first 
	one hundred natural numbers and the square of the sum.
	 * sum of squares = 1^2 + 2^2 + 3"....
	 * square of sums = (1 + 2 + 3...)^2
*/

int sumSquares(int x) {
	int sum {0};
	for(int i {0}; i <= x; i++)
		sum += pow(i, 2);
	return sum;
}

int squareSum(int x) {
	int result {0}, sum {0};
	for(int i {0}; i <= x; i++)
		sum += i;
	result = pow(sum, 2);
	return result;
}

int main() {
	cout << squareSum(100) << " - " << sumSquares(100) << " = " 
		<< squareSum(100) - sumSquares(100) << "\n";
	return 0;
}