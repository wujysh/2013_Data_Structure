#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;

map <string, string> dictionary;

int main() {
	char str[50];
	while (gets(str) && strcmp(str, "") != 0) {
		char english[50], foreign[50];
		sscanf(str, "%s%s", english, foreign);
		dictionary[foreign] = english;
	}
	while (scanf("%s", str) != EOF) {
		if (dictionary.find(str) != dictionary.end())
			printf("%s\n", dictionary[str].c_str());
		else
			printf("eh\n");
	}
	return 0;
}