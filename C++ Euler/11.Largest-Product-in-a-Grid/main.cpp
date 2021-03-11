#include <iostream>
#include <fstream>
using namespace std; 

/*
11. Largest Product in a Grid
	what is the greatest product of four adjacent numbers in the same direction 
	(up, down, left, right, or diagonally) in the 20×20 grid?
	 * we need to check in 8 directions - this is done simply checking only 4
	 * 	up, right, rightup rightdown ->\^/<-
*/

typedef unsigned int ui;

int main() {
	const ui size = 20;
	ui M[size][size];
	ui row = 0, col = 0;
	
	ifstream grid("num.txt");
	for (row = 0; row < size * size; row++)
			grid >> M[row / size][row % size];
	grid.close();
		
	ui product {1};
	ui maxProduct = product;
	
	for (col = 0; col < size; col++)             // UP
		for (row = 0; row < size - 3; row++) {
			product = M[row][col] * M[row+1][col] * M[row+2][col] * M[row+3][col];
			if (maxProduct < product)
				maxProduct = product;
		}
	
	for (row = 0; row < size; row++)             // RIGHT
		for (col = 0; col < size - 3; col++) {
			product = M[row][col] * M[row][col+1] * M[row][col+2] * M[row][col+3];
			if (maxProduct < product)
				maxProduct = product;
		} 
	
	for (col = 0; col < size - 3; col++)         // RIGHTUP
		for (row = 0; row < size - 3; row++) {
			product = M[row][col] * M[row+1][col+1] * M[row+2][col+2] 
				* M[row+3][col+3];
			if (maxProduct < product)
				maxProduct = product;  
		}
	
	for (col = 3; col < size; col++)             // RIGHTDOWN
		for (row = 0; row < size - 3; row++) {
			product = M[row][col] * M[row+1][col-1] * M[row+2][col-2] 
				* M[row+3][col-3];
			if (maxProduct < product)
				maxProduct = product;
		}
	
	cout << maxProduct << "\n";
	
	return 0;
}