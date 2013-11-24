#include <iostream>
//#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
#define MAXN 30

int InDegree[MAXN];
bool Graph[MAXN][MAXN], Exist[MAXN];

bool TopologicalSort() {
	//stack <int> Zero;
	queue <int> Zero;
	while (!Zero.empty()) { Zero.pop(); }
	for (int i = 1; i <= 26; i++) {
		if (Exist[i] && !InDegree[i]) Zero.push(i);
	}
	//int cnt = 0;
	while (!Zero.empty()) {
		//int x = Zero.top();  // stack
		int x = Zero.front();  // queue
		Zero.pop();
		//if (cnt) cout << " ";
		cout << char(x + 'A' - 1);  // output
		//cnt++;
		for (int i = 1; i <= 26; i++) {
			if (Exist[i] && Graph[x][i]) {
				if (!(--InDegree[i])) Zero.push(i);
			}
		}
	}
	//if (cnt < n) return false;  // ERROR
	//else return true;  // OK
	return true;
}

int main() {
	string st, pre_st;
	memset(Graph, 0, sizeof(Graph));
	memset(InDegree, 0, sizeof(InDegree));
	memset(Exist, 0, sizeof(Exist));

	while (cin >> st && st != "#") {
		if (!pre_st.length()) pre_st = st;
		if (pre_st.length()) {
			int len1 = pre_st.length();
			int len2 = st.length();
			int len = len1 < len2 ? len1 : len2;
			for (int i = 0; i < len; i++) {
				if (pre_st[i] != st[i]) {
					if (!Graph[pre_st[i] - 'A' + 1][st[i] - 'A' + 1]) {  // avoid repeated update!!!
						Graph[pre_st[i] - 'A' + 1][st[i] - 'A' + 1] = true;
						InDegree[st[i] - 'A' + 1]++;
						Exist[pre_st[i] - 'A' + 1] = Exist[st[i] - 'A' + 1] = true;
					}
					break;
				} else {
					Exist[st[i] - 'A' + 1] = true;
				}
			}
		}
		pre_st = st;
	}

	TopologicalSort();

	cout << endl;

	return 0;
}