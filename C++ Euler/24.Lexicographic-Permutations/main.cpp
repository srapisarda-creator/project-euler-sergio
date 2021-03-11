#include <iostream>
#include <algorithm>
#include <string>
using namespace std; 

/*
24. Lexicographic Permutations
	a permutation is an ordered list of objects, if all of the permutations are
	listed numerically or alphabetically, we call it lexicographic order
	What is the millionth lexicographic permutation of 0,1,2,3,4,5,6,7,8,9?
	 * next_permutation - rearranges the elements in range [first,last) into
	 * the next lexicographically greater permutation
*/

typedef unsigned int ui;

int main() {
	ui numPermutation {999999};
	string current = "0123456789";
	while (numPermutation--) 
		next_permutation(current.begin(), current.end());
	cout << current << endl;
	return 0;
}