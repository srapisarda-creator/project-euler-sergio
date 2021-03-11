#include <iostream>
#include <cmath>
using namespace std; 

/*
39. Integer Right Triangles
	if p is the perimeter of a right angle triangle with integral sides {a,b,c},
	there are exactly three solutions for p = 120 ->
	{20,48,52}, {24,45,51}, {30,40,50}
	For which value of p <= 1000 is the number of solutions maximised?
	 * -> a + b + c = p <= 1000, a*a + b*b = c*c
	 * b = (p * a - p * p / 2) / (a - p), c = sqrt(a*a + b*b)
	 * 
	 * p must be even -> p*p = 2(c + a)(c + b)
	 * (p - a) and (p - b) must be divisors of p*p / 2, i * j = p * p / 2
	 * i = (p - a), j = (p - b) -> a = p - j, b = p - i
*/

int integerRightTriangles(int p) {  // finds the number of 
	int count {0}, a, b, i, j;
	for (i = 1; i * i <= (p * p / 2); i++) {
		if ((p * p / 2) % i == 0) {
			j = (p * p / 2) / i;  
			a = p - j;
			b = p - i;
			if ((p - a) * (p - b) == (p * p) / 2 && b > 0)
				count++;
		}
	}
	return count;
}

int main() {
	int current, largest, P;
	for (int p {2}; p <=  1000; p += 2) {
		current = integerRightTriangles(p);
		if (current > largest) {
			largest = current;
			P = p;
		}
	}
	cout << "P = " << P << ", with " << largest << " right angle triangles\n";
	return 0;
}