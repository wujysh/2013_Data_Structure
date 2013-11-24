#include <iostream>
//#include <stack>
#include <queue>
#include <cstring>
using namespace std;
#define MAXN 105

int n, m, InDegree[MAXN];
bool Graph[MAXN][MAXN];

bool TopologicalSort() {
	//stack <int> Zero;
	queue <int> Zero;
	while (!Zero.empty()) { Zero.pop(); }
	for (int i = 1; i <= n; i++) {
		if (!InDegree[i]) Zero.push(i);
	}
	int cnt = 0;
	while (!Zero.empty()) {
		//int x = Zero.top();  // stack
		int x = Zero.front();  // queue
		Zero.pop();
		if (cnt) cout << " ";
		cout << x;  // output
		cnt++;
		for (int i = 1; i <= n; i++) {
			if (Graph[x][i]) {
				if (!(--InDegree[i])) Zero.push(i);
			}
		}
	}
	//if (cnt < n) return false;  // ERROR
	//else return true;  // OK
	return true;
}

int main() {
	while (cin >> n >> m && (n || m)) {
		memset(Graph, 0, sizeof(Graph));
		memset(InDegree, 0, sizeof(InDegree));

		for (int k = 0; k < m; k++) {
			int i, j;
			cin >> i >> j;
			Graph[i][j] = true;
			InDegree[j]++;
		}

		TopologicalSort();
		cout << endl;
	}
	return 0;
}