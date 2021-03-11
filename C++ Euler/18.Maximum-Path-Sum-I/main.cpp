#include <iostream>
#include <cmath>
#include <cassert>
using namespace std; 

/*
18. Maximum Path Sum I
	find the maximum total from top to bottom in the triangle
	 * brute would be simply check the value of each path and find max
	 * however, checking from the base of the triangle, such that
	 *   a     -> the solution is a + max(b, c)
	 * b   c
*/

int main() {
	int triangle[] = 
    {
	75,
	95, 64,
	17, 47, 82,
	18, 35, 87, 10,
	20, 4, 82, 47, 65,
	19, 1, 23, 75, 4, 34,
	88, 2, 77, 73, 7, 63, 67,
	99, 65, 4, 28, 6, 16, 70, 92,
	41, 41, 26, 56, 83, 40, 80, 70, 33,
	41, 48, 72, 33, 47, 32, 37, 16, 94, 29,
	53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,
	70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,
	91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,
	63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,
	4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23
    };
	const int size = sizeof(triangle) / sizeof(int);
	const int tri = static_cast<int>(sqrt(2.0 * size));
	assert(tri * (tri + 1) == 2 * size);  // ensures size is a triangular number
	// loops backwards, finding max value of element
	for (int n = tri - 1; n > 0; n--) {  // n = length of row
		for (int k = (n * (n - 1)) / 2; k < (n * (n + 1)) / 2; k++) {  // go along each row
			triangle[k] += max(triangle[k + n], triangle[k + n + 1]);  
		}
	}
	
	cout << triangle[0] << "\n";;
	
	return 0;
}