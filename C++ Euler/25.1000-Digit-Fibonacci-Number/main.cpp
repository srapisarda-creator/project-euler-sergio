#include <iostream>
#include <vector>
using namespace std; 

/*
25. 1000 Digit Fibonacci Number
	Fn = Fn-1 + Fn-2, f1 = 1, f2 = 1
	What is the index of the first term in the sequence to have 1000 digits?
*/

typedef unsigned int ui;
typedef vector<ui> Digits;
Digits add(const Digits& a, const Digits& b) {  // add two long numbers, b >= a
	Digits result = b;
	ui carry {0};
	for (ui i {0}; i < result.size(); i++) {
		if (i < a.size())        
			result[i] += a[i];
		result[i] += carry;
		
		if (result[i] >= 10) {   // overflow
			carry = 1;
			result[i] -= 10;
		} else
			carry = 0;
	}
	if (carry != 0)
		result.push_back(carry);	
	return result;
}

int main() {
	vector<ui> digitsList { 1 };  // store list of number of digits in each term
	digitsList.reserve(1000);
	
	Digits a {1}, b {1};  // first two terms of sequence
	ui index {2};         
	while (digitsList.size() <= 1000) {
		index++;          // next term
		auto next = add(a, b);
		a = move(b);
		b = move(next);
		
		auto current {b.size()};  // digits of current Fibonacci number 
		auto largest {digitsList.size() - 1};
		if (largest < current)
			digitsList.push_back(index);
	}
	
	cout << digitsList[1000] << "\n";
	return 0;
}