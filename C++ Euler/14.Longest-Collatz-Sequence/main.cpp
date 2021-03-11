#include <iostream>
#include <vector>
using namespace std; 

/*
14. Longest Collatz Sequence
	n -> n / 2 (n is even)  |   n -> 3n + 1 (n is odd)
	which starting number, under 1 million, produces the longest chain?
	 * brute force counting method - store the size of longest sequence
	 * found an optimised method, which acts recursively 
	 * and stores previous values for faster look-up
*/
typedef unsigned long long ull;
typedef unsigned int ui;
typedef uint64_t ui64;

ui64 nextCollatzTerm(ui64 previous) {
	ui64 next;
	if(previous % 2 == 0) {
		next = previous / 2;
	} else {
		next = (3 * previous) + 1;
	}
	return next;
}

int collatzTerms(ui64 x) {                    // brute force
	int count {1};                            // count each term
	while (x != 1) {
		x = nextCollatzTerm(x);
		count++;
	}
	return count;
}

ui64 findLongestSequence(ui64 end) {  // upto the end-limit
	int max {0}, counter {0};         // check number of terms in sequence
	for (ui64 i {1}; i < end; i++) {  // store the max
		int terms = collatzTerms(i);
		if (max < terms) {
			max = terms;
			counter = i;
		}
	}
	return counter;
}


static vector<int> countsList(1000000,-1);

int count_collatz_terms_opt(ui64 start) {  // optimised method
	if (start == 1)                   
		return 1;
	int count {0};
	
	if (start < 1000000) {
		count = countsList.at(start);
		if(count == -1) {                   // recursive
			count = count_collatz_terms_opt(nextCollatzTerm(start));
			count++;
			countsList.at(start) = count;   // stores previous counts
		}
	} else {
		count = collatzTerms(start);        // brute force generate sequence
	}
	return count;
}

ui64 longest_collatz_sequence_opt(ui64 max_check) {
	int max_count {0}, max_counter {0};
	for (ui64 i {2}; i < max_check; i++) {
		if (countsList.at(i) == -1) {
			int count = count_collatz_terms_opt(i);
			if (max_count < count) {
				max_count = count;
				max_counter = i;
			}
		}
	}
	return max_counter;
}


int main() {
	int answer = findLongestSequence(1000000);
	cout << "Answer: " << answer << "\n";
	
	int optimised = longest_collatz_sequence_opt(1000000);
	cout << "Answer: " << optimised << "\n";
	
	
	return 0;
}