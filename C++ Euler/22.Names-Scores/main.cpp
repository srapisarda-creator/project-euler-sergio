#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std; 

/*
22. Names Scores
	using names.txt, sort into alphabetical order, then calculate the value for each
	position alphabetically and by positional value, e.g COLIN = 3+15+12+9+14 = 53
	it is the 938th name in list, and value is 938*53 = 49714
	what is the total of all such scores using the list?
*/

int nameScore(string name) {  // calculate the sum of the value of letters in the name
	int score {0};
	for (char& c : name) {
		if (isalpha(c))  // checks for only letters, no ""
			score += toupper(c) - 'A' + 1;
	}
	return score;
}

int answer(const char* filename) {
	typedef map<string, int> namesMap;
	namesMap names;
	ifstream file(filename);
	for (string text ; getline(file, text); ) {
		stringstream ss(text);
		string name;
		
		while (getline(ss, name, ',')) {  // strip the , 
			int score = nameScore(name);
			
			namesMap::iterator n = names.find(name);
			if (n != names.end()) {  // search for name in collection
				n->second += score;  // if duplicate, count again
			} else
				names.insert(namesMap::value_type(name, score));
		}
	}
	
	int total {0}, pos {1};
	for (namesMap::iterator itr = names.begin(); itr != names.end(); itr++, pos++) {
		cout << "Name: " << pos << ":" << itr->first << ":" << itr->second << endl;
		total += (pos * itr->second);
	}
	return total;
}

int main() {
	const char* file = "names.txt";
	cout << answer(file) << "\n";
	return 0;
}