#include <iostream>
#include <limits>
#include <string>
#include <map>
using namespace std;

string str[120010];
bool exist[0x7fffffff] = { false };

unsigned int jenkins_one_at_a_time_hash(const string &input, int start, int n) {
	unsigned int hash = 0;
	for (int i = 0; i < n; i++) {
		hash += input[start + i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash;
}

int main() {
	int cnt = 0;
	
	while (cin >> str[cnt] && str[cnt] != "") {
		exist[jenkins_one_at_a_time_hash(str[cnt], 0, str[cnt].length())] = true;
		cnt++;
	}
	for (int i = 0; i < cnt; i++) {
		for (int j = 1; j < str[i].length() - 1; j++) {
			string a = str[i].substr(0, j - i);
			string b = str[i].substr(j, str[i].length() - j);
			if (exist[jenkins_one_at_a_time_hash(a, 0, a.length())] && exist[jenkins_one_at_a_time_hash(b, 0, b.length())]) {
				cout << str[i] << endl;
			}
		}
	}
	return 0;
}