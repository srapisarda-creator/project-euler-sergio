#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
using namespace std; 

/*
17. Number Letter Counts
	if the numbers 1->5 are written out in words: one two three.. there are 19
	letters used, how many letters are used with numbers 1->1000 written out?
	 * ignore spaces, hypens etc
*/

typedef unsigned long long ull;
typedef unsigned int ui;
typedef uint64_t ui64;

string numberLetters(int num, map<int, string> dict) {
	string letters;
	
	
	if (num > 0 && num <= 20) {
		auto itr = dict.find(num);
		letters.append(itr->second);
	}
	
	if (num >= 21 && num <= 99) {
		int a, b;
		a = div(num, 10).quot;
		b = div(num, 10).rem;
		auto itrA = dict.find(a*10);
		auto itrB = dict.find(b);
		if (b == 0)
			letters.append(itrA->second);
		else 
			letters.append(itrA->second + itrB->second);
	}
	
	if (num >= 100 && num <= 999) {
		if (num % 100 == 0) {
			auto itr = dict.find(num / 100);
			letters.append(itr->second + "hundred");
		}
		else {
			int digit = (num / 100);
			num = num - digit * 100;
			auto itrDigit = dict.find(digit);
			auto itrNum = dict.find(num);
			if (num > 0 && num <= 20)
				letters.append(itrDigit->second + "hundredand" + itrNum->second);
			
			if (num >= 21 && num <= 99) {
				int a, b;
				a = div(num, 10).quot;
				b = div(num, 10).rem;
				auto itrA = dict.find(a*10);
				auto itrB = dict.find(b);
				if (b == 0)
					letters.append(itrDigit->second + "hundredand" + itrA->second);
				else
					letters.append(itrDigit->second + "hundredand" + itrA->second 
						+ itrB->second);
			}
		}
	}
	if (num == 1000)
		letters.append("onethousand");
	
	return letters;
}

int main() {
	map<int, string> dictionary;
	{
//	dictionary.insert(pair<int, string>(0, "zero"));
	dictionary.insert(pair<int, string>(1, "one"));
	dictionary.insert(pair<int, string>(2, "two"));
	dictionary.insert(pair<int, string>(3, "three"));
	dictionary.insert(pair<int, string>(4, "four"));
	dictionary.insert(pair<int, string>(5, "five"));
	dictionary.insert(pair<int, string>(6, "six"));
	dictionary.insert(pair<int, string>(7, "seven"));
	dictionary.insert(pair<int, string>(8, "eight"));
	dictionary.insert(pair<int, string>(9, "nine"));
	dictionary.insert(pair<int, string>(10, "ten"));
	dictionary.insert(pair<int, string>(11, "eleven"));
	dictionary.insert(pair<int, string>(12, "twelve"));
	dictionary.insert(pair<int, string>(13, "thirteen"));
	dictionary.insert(pair<int, string>(14, "fourteen"));
	dictionary.insert(pair<int, string>(15, "fifteen"));
	dictionary.insert(pair<int, string>(16, "sixteen"));
	dictionary.insert(pair<int, string>(17, "seventeen"));
	dictionary.insert(pair<int, string>(18, "eighteen"));
	dictionary.insert(pair<int, string>(19, "nineteen"));
	dictionary.insert(pair<int, string>(20, "twenty"));
	dictionary.insert(pair<int, string>(30, "thirty"));
	dictionary.insert(pair<int, string>(40, "forty"));
	dictionary.insert(pair<int, string>(50, "fifty"));
	dictionary.insert(pair<int, string>(60, "sixty"));
	dictionary.insert(pair<int, string>(70, "seventy"));
	dictionary.insert(pair<int, string>(80, "eighty"));
	dictionary.insert(pair<int, string>(90, "ninety"));
	}
/*	Testing 
	map<int, string>::iterator it = dictionary.begin();
	while (it != dictionary.end()) {
		int numVal = it->first;
		string text = it->second;
		
		cout << numVal << ": " << text << "\n";
		it++;
	}
	div_t res = div(100, 6);
	cout << res.quot << " " << res.rem << "\n";
	
	auto itr = dictionary.find(3); 
	cout << itr->first << "\t" << itr->second << "\n";
	
	string a = numberLetters(15, dictionary);
	cout << a << "\n";
	
	string b = numberLetters(30, dictionary);
	cout << b << "\n";
	
	string c = numberLetters(45, dictionary);
	cout << c << "\n";
	
	string d = numberLetters(200, dictionary);
	cout << d << "\n";
	
	string e = numberLetters(214, dictionary);
	cout << e << "\n";
	
	string f = numberLetters(250, dictionary);
	cout << f << "\n";
	
	string g = numberLetters(995, dictionary);
	cout << g << "\n";
*/
	string str;
	for (int i {0}; i <= 1001; i++) {
		str.append(numberLetters(i, dictionary));
	}
	cout << str << "\n";
	ui answer = str.length();
	cout << answer << "\n";
	return 0;
}