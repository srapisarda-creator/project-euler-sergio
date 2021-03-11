#include <iostream>
#include <vector>
using namespace std; 

/*
15. Lattice Paths
	starting in the top left corner, in a 2x2 grid, moving only right and down
	there are exactly 6 routes to the bottom right corner
	how many such routes are there through a 20x20 grid?
*/

typedef unsigned long long ull;
typedef unsigned int ui;
typedef uint64_t ui64;

ui64 factorial(ui64 n) {  
    if(n > 1)             
        return n * factorial(n - 1);
    else
        return 1;
}

ui64 lattice(ui64 n, ui64 k) {  // n = height+width, k = height / width
	return factorial(n) / (factorial(k) * factorial(n-k));
}

// path uses a breadth-first search method
// starts at the root (loops backwards) and explores each neighbour node
ui64 path(int size) {
	vector<ui64> grid((size + 1)*(size + 1), 1);
	for (int x {size - 1}; x >= 0; x--) {
		for (int y{size - 1}; y >= 0; y--) {
			int pos = (y * (size + 1)) + x;
			grid.at(pos) = grid.at(pos + 1) + grid.at(pos+(size + 1)); 
		}                               // save the result to grid[0][0]
	}
	return grid.at(0);
}


int main() {
	cout << path(20) << "\n";
	return 0;
}