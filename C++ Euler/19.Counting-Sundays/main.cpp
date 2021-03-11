#include <iostream>
#include <cmath>
using namespace std; 

/*
19. Counting Sundays
	how many Sundays fell on the first of the month during the 20th century?
	1 January 1901 -> 31 December 2000
	 * Gauss' Algorithm Disparate Version
	 * w = (d + [2.6m - 0.2] + y + [y/4] + [c/4] - 2c) mod 7
	 * Y is year (or Y minus 1 for Jan / Feb), y is the last 2 digits of Y
	 * c is the first 2 digits of Y, d is the day of the month (1 -> 31)
	 * m is the shifted month (march = 1, february = 12)
	 * w is day of the week (0 = sunday, 6 = saturday, if negative -> + 7)
	
*/

int firstSunday(int y, int m) {
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; // months Jan -> Dec
	y -= m < 3;  
	return 0 == floor((y + y/4 - y/100 + y/400 + t[m - 1] + 1) % 7);  // 0 == Sunday
}  // this can be changed to a different day, e.g 1 == .. for Mondays


int countingSundays() {
	int answer {0};
	for (int i {1901}; i <= 2000; i++) {
		for (int j {1}; j <= 12; j++) {
			if(firstSunday(i, j)) {
				answer++;
			}
		}
	}
	return answer;
}

int main() {
	cout << countingSundays() << "\n";
	
	return 0;
}