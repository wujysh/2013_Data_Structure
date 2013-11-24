#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<char, int> list;
	map<string, int> number;
	map<string, int>::iterator it;

	list['a'] = list['b'] = list['c'] = 2;
	list['d'] = list['e'] = list['f'] = 3;
	list['g'] = list['h'] = list['i'] = 4;
	list['j'] = list['k'] = list['l'] = 5;
	list['m'] = list['n'] = list['o'] = 6;
	list['p'] = list['q'] = list['r'] = list['s'] = 7;
	list['t'] = list['u'] = list['v'] = 8;
	list['w'] = list['x'] = list['y'] = list['z'] = 9;

	int T;
	scanf("%d", &T);
	while (T--) {
		int N, M;
		string num[5000];
		number.clear();

		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			cin >> num[i];
		}
		for (int i = 0; i < M; i++) {
			string word, num="";
			cin >> word;
			for (int j = 0; j < word.length(); j++) {
				num += (char)list[word[j]] + '0';
			}
			number[num]++;
		}
		for (int i = 0; i < N; i++) {
			it = number.find(num[i]);
			if (it != number.end())
				printf("%d\n", it->second);
			else
				printf("0\n");
		}
	}
	return 0;
}