#include <iostream>
#include <iomanip>
#include <queue>
#include <cmath>
using namespace std;
#define MAXN 760

struct edge {
	int a, b;
	double len;
	friend bool operator < (const edge a, const edge b) {
		return a.len > b.len;
	}
};
priority_queue <edge> q;

int root[MAXN];
double sum;

int findroot(int x) {
	return root[x] == x ? x : root[x] = findroot(root[x]);
}

int main() {
	int n, m;
	while (cin >> n && n) {
		sum = 0;
		int x[MAXN], y[MAXN];

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
				q.push(e);
			}
		}

		while (!q.empty()) {
			edge e = q.top();
			q.pop();
			if (findroot(e.a) != findroot(e.b)) {
				root[findroot(e.a)] = findroot(e.b);
				sum += e.len;
			}
		}

		cout << fixed << setprecision(2) << sum << endl;
	}
	return 0;
}