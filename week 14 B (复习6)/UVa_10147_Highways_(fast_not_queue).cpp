// Similar to UVa 10397 Connect the campus
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
#define MAXN 760

struct edge {
	int a, b;
	double len;
	friend bool operator < (const edge a, const edge b) {
		return a.len < b.len;
	}
};

int Sets[MAXN], Rank[MAXN];
vector <edge> edges;

int Find(int x) {
	return Sets[x] == x ? x : Sets[x] = Find(Sets[x]);
}

void Union(int x, int y) {
	if (Rank[x] < Rank[y]) {
		Sets[x] = y;
	} else {
		if (Rank[x] == Rank[y])
			Rank[x]++;
		Sets[y] = x;
	}
}

int main() {
	int nCase;
	cin >> nCase;
	while (nCase--) {
		int n, m;
		int x[MAXN], y[MAXN];
		edges.clear();

		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> x[i] >> y[i];
			Sets[i] = i;
			Rank[i] = 1;
		}

		cin >> m;
		for (int i = 0; i < m; i++) {
			int c1, c2;
			cin >> c1 >> c2;
			int a = Find(c1);
			int b = Find(c2);
			if (a != b) {
				Union(a, b);
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				edge e;
				e.a = i;
				e.b = j;
				e.len = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
				edges.push_back(e);
			}
		}

		// kruskal
		int cnt = 0;
		sort(edges.begin(), edges.end());
		for (unsigned int i = 0; i < edges.size(); i++) {
			int a = Find(edges[i].a);
			int b = Find(edges[i].b);
			if (a != b) {
				Union(a, b);
				cout << edges[i].a << " " << edges[i].b << endl;
				cnt++;
			}
		}

		if (!cnt) cout << "No new highways need" << endl;
		if (nCase) cout << endl;
	}
	return 0;
}