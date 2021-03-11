#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std; 

/*
42. Coded Triangle Numbers
	the nth term of the sequence of triangle numbers is given by
	tn = 1/2 * n * (n + 1), so the first ten triangle numbers are 
	1,3,6,10,15,21,28,36,45,55.. by converting each letter in a word to a number
	corresponding to its alphabetical position and adding these values we form a
	word value, e.g. the word SKY = 19 + 11 + 25 = 55 = t10, if the word value is a
	triangle number, then we shall call the word a triangle word
	Using words.txt, a 16k text file containing nearly 2000 common English words,
	how many are triangle words?
	 * Gauss' method for finding the sum of consecutive numbers: sum = n*n(n+1) / 2
	 * -> n = sqrt(2 * sum - sqrt(2 * sum - ...)))
*/

vector<int> triangularNumbers;

int nthTriangular(int n) {
	int tn = n * (n + 1) / 2;
	return tn;
}

void triangularNumberGen() {
	for (int i {1}; i <= 10; i++) {
		triangularNumbers.push_back(nthTriangular(i));
	}
}


int main() {
	triangularNumberGen();
	for (auto t : triangularNumbers)
		cout << t << "\n";
	
	
	ifstream file("words.txt");
	int triangularWords {0};
	char s[20];
	while (file.getline(s, 20, ',')) {  // use , as seperator
		int sum {0};
		for (int i {0}; s[i]; i++) {
			if (s[i] == '"')  // ignore ""
				continue;
			sum += s[i] - 'A' + 1;  // sum += int value of char
		}
		double n = sqrt(2 * sum + 1./4) - 1./2;  // Gauss' method
		if (n == (int)n)
			triangularWords++;
	}
	
	cout << triangularWords << "\n";
	return 0;
}