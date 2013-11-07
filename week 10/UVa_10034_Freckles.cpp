#include <iostream>
#include <iomanip>
#include <queue>
#include <cstdio>
#include <cmath>
using namespace std;
#define MAXN 110

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
	int nCase;
	cin >> nCase;
	getchar();
	while (nCase--) {
		sum = 0;
		int n;
		double x[MAXN], y[MAXN];
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
			root[i] = i;
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
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
		if (nCase) cout << endl;
	}
	return 0;
}
