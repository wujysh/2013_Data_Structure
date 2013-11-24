#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, c;
vector <int> table;

inline int min(int a, int b) {
	return a < b ? a : b;
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((c / table[i]) % n == (c / table[j]) % n) {
				c = min((c / table[i] + 1)*table[i], (c / table[j] + 1)*table[j]);
				solve();
				return;
			}
		}
	}
}

int main() {
	char str[256];
	while (gets(str)) {
		table.clear();
		int i = 0;
		while (str[i] != '\0') {
			string word;
			while (str[i] == ' ') i++;
			while (str[i] != ' ' && str[i] != '\0') {
				word += str[i];
				i++;
			}
			int sum = 0;
			for (unsigned j = 0; j < word.length(); j++) {
				sum <<= 5;
				sum += word[j] - 'a' + 1;
			}
			table.push_back(sum);
		}

		sort(table.begin(), table.end());
		n = table.size();
		c = table[0];
		solve();

		printf("%s\n", str);
		printf("%d\n\n", c);
	}
	return 0;
}