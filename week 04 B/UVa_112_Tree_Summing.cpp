#include <iostream>
using namespace std;

void IgnoreSpaces()
{
	while (cin.peek() == ' ' || cin.peek() == '\n')
		cin.ignore(1);  // ignore space or enter
}

bool process(int sum, int val, bool *output)
{
	int v, signal = 1;

	IgnoreSpaces();
	cin.ignore(1);  // ignore (
	IgnoreSpaces();

	if (cin.peek() == ')') {
		cin.ignore(1);  // ignore )
		return (sum == val) ? true : false;  // Only when next chars are () and sum = val, return true.
	}

	IgnoreSpaces();

	if (cin.peek() == '-') {
		signal = -1;
		cin.ignore(1);  // ignore -
	}
	cin >> v;  // scan number
	v *= signal;

	bool left = process(sum + v, val, output);
	bool right = process(sum + v, val, output);

	if (left && right)  // If it's a leaf, its left and right parts should both be ().
		*output = true;

	IgnoreSpaces();
	cin.ignore(1);  // ignore )

	return false;
}

int main()
{
	int val;
	bool output;
	while (cin >> val) {
		output = false;
		process(0, val, &output);
		cout << (output ? "yes" : "no") << endl;
	}
	return 0;
}