#include <iostream>
using namespace std; 

/*
31. Coin Sums
	in the UK there are eight coins in circulation: 1p,2p,5p,10p,20p,50p,£1,£2
	How many different ways can £2 be made using any number of coins?
*/

int main() {  // store number of ways to make £2 in a list
	int coinsList[8] = {1,2,5,10,20,50,100,200}, answer[201] = {0}; 
	answer[0] = 1;
	for (int coin {0}; coin < 8; coin++) {
		for (int i {0}; i + coinsList[coin] <= 200; i++) {  // the limit is 200 = £2
			answer[i + coinsList[coin]] += answer[i];
		}
	}
	cout << answer[200] << "\n";
	return 0;
}