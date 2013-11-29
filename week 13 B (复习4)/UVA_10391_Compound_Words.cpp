#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <set>
using namespace std;

set <string> dict;

int main() {
	char buf[1000];

	while (gets(buf)) dict.insert(buf);

	set <string>::iterator it;
	for (it = dict.begin(); it != dict.end(); it++) {
		string str = *it;
		for (int i = 1; i < str.size() - 1; i++) {
			if (dict.find(str.substr(0, i)) != dict.end() && dict.find(str.substr(i)) != dict.end()) {
				puts(str.c_str());
				break;
			}
		}
	}

	return 0;
}