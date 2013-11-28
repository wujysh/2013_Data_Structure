#include <iostream>
#include <iomanip>
#include <queue>
#include <cmath>
using namespace std;
#define MAXN 510

struct edge {
	int a, b;
	double len;
	friend bool operator < (const edge a, const edge b) {
		return a.len > b.len;
	}
};
priority_queue <edge> q;

int root[MAXN];

int findroot(int x) {
	return root[x] == x ? x : root[x] = findroot(root[x]);
}

int main() {
	int nCase;
	cin >> nCase;
	while (nCase--) {
		int s, p, sum = 0;
		double ans = 0;
		double x[MAXN], y[MAXN];

		while (!q.empty()) q.pop();

		cin >> s >> p;

		for (int i = 1; i <= p; i++) {
			cin >> x[i] >> y[i];
			root[i] = i;
		}

		for (int i = 1; i <= p; i++) {
			for (int j = i + 1; j <= p; j++) {
				edge e;
				e.a = i;
				e.b = j;
				e.len = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
				q.push(e);
			}
		}

		int cnt = 0;
		while (!q.empty()) {
			edge e = q.top();
			q.pop();
			if (findroot(e.a) != findroot(e.b)) {
				root[findroot(e.a)] = findroot(e.b);
				sum += e.len;
				cnt++;
				if (cnt == p - s) {
					ans = e.len;
					break;
				}
			}
		}

		cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}