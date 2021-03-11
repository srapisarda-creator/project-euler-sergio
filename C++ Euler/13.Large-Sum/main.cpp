#include <iostream>
#include <fstream> 
#include <sstream> 
#include <vector>
#include <string>
using namespace std; 

/*
13. Large Sum
	work out first ten digits of the sum of the 100
	50 digit numbers in .txt
	 * 50 digits too large to interact as a number
	 * store as a string - then use stringstream to read as a number
*/
typedef unsigned long long ull;
typedef unsigned int ui;
typedef uint64_t ui64;

template <typename T> T toNum(const char* num) {    // reads the string of the 
	stringstream ss(num);                           // number and converts to
	T ret;                                         
	return ss >> ret ? ret : 0;                     // an int or 0 if not
}

string sum() {
	ui64 sum {0};
	ifstream txt("numbers.txt");
	for (string line ; getline(txt, line);) {
		sum += toNum<ui64>(line.substr(0,11).c_str());  
	}                                             // this will show      
	return to_string(sum).substr(0, 10);          // first ten digits of num
}

int main() {
	string number;
	vector<string> list;
	ifstream file;
	file.open("numbers.txt");         // learning ifstream
	
	while (file >> number) {  // read the file into a string variable
		list.push_back(number);  // push to the vector list
	}
	
	file.close();
	int i {1};
	vector<ui> realnumbers;           // test
	for (auto l : list) {
		cout << i << ". " << l << "\n";
		i++;
		
	}
	
	cout << "Answer: " << sum() << "\n";
	
	return 0;
}