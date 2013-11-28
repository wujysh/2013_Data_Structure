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
priority_queue <edge> q, ans;

int root[MAXN];
double sum;

int findroot(int x) {
	return root[x] == x ? x : root[x] = findroot(root[x]);
}

int main() {
	int nCase;
	cin >> nCase;
	while (nCase--) {
		int s, p;
		cin >> s >> p;

		sum = 0;
		int x[MAXN], y[MAXN];

		for (int i = 1; i <= p; i++) {
			cin >> x[i] >> y[i];
			root[i] = i;
		}

		for (int i = 1; i < n; i++) {
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
				ans.
			}
		}

		cout << fixed << setprecision(2) << sum << endl;
	}
	return 0;
}