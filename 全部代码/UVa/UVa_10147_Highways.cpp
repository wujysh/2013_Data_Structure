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

int root[MAXN];
double sum;
vector <edge> edges;

int findroot(int x) {
	return root[x] == x ? x : root[x] = findroot(root[x]);
}

int main() {
	int nCase;
	cin >> nCase;
	while (nCase--) {
		int n, m;
		int x[MAXN], y[MAXN];
		sum = 0;
		edges.clear();

		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> x[i] >> y[i];
			root[i] = i;
		}

		cin >> m;
		for (int i = 0; i < m; i++) {
			int c1, c2;
			cin >> c1 >> c2;
			if (findroot(c1) != findroot(c2))
				root[findroot(c1)] = findroot(c2);
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
		for (unsigned int i = 0; i<edges.size(); i++) {
			int a = findroot(edges[i].a);
			int b = findroot(edges[i].b);
			if (a != b) {
				root[a] = b;
				cout << edges[i].a << " " << edges[i].b << endl;
				cnt++;
			}
		}

		if (!cnt) cout << "No new highways need" << endl;
		if (nCase) cout << endl;
	}
	return 0;
}