#include <iostream>
using namespace std;

struct fraction
{
	long long unsigned numerator; // fen zi
	long long unsigned denominator; // fen mu
};

int main(int argc, char *argv[])
{
	long long unsigned up, down;
	fraction left, right, middle;

	while (cin >> up >> down, (up - down)) {
		left.numerator = 0;
		left.denominator = 1;

		right.numerator = 1;
		right.denominator = 0;

		middle.numerator = 1;
		middle.denominator = 1;

		while (1) {			
			if (up * middle.denominator == down * middle.numerator)
				break;

			if (up * middle.denominator > down * middle.numerator) { // the current number is bigger than the middle one, then turn to right part
				cout << "R";

				left.numerator =  middle.numerator;
				left.denominator = middle.denominator;

				middle.numerator = (left.numerator + right.numerator);
				middle.denominator = (left.denominator + right.denominator);
			}
			else {													// the current number is smaller than the middle one, then turn to left part
				cout << "L";

				right.numerator =  middle.numerator;
				right.denominator = middle.denominator;

				middle.numerator = (left.numerator + right.numerator);
				middle.denominator = (left.denominator + right.denominator);			
			}
		}
		cout << endl;
	}

	return 0;
}


