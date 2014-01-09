#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

const int MAXN = 105;
const double eps = 1e-6;

int Sets[MAXN], Rank[MAXN], Sums[MAXN];
double x[MAXN], y[MAXN], r[MAXN];

int Find(int x) {
	return Sets[x] == x ? x : Sets[x] = Find(Sets[x]);
}

void Union(int x, int y) {
	if (Rank[x] < Rank[y]) {
		Sets[x] = y;
		Sums[y] += Sums[x];
	} else {
		if (Rank[x] == Rank[y])
			Rank[x] ++;
		Sets[y] = x;
		Sums[x] += Sums[y];
	}
}

int main() {
	int n;
	while (cin >> n && n != -1) {
		for (int i = 1; i <= n; i++) {
			Sets[i] = i;  Rank[i] = 1;  Sums[i] = 1;
			cin >> x[i] >> y[i] >> r[i];
		}

		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				double d = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
				double addr = r[i] + r[j];
				double subr = fabs(r[i] - r[j]);
				if (subr - d < eps && d - addr < eps) {
					if (Find(i) != Find(j)) {
						Union(Find(i), Find(j));
					}
				}
			}
		}

		int max = 0;
		for (int i = 1; i <= n; i++) {
			if (Sums[i] > max)
				max = Sums[i];
		}

		cout << "The largest component contains ";
		if (max == 1) cout << "1 ring." << endl;
		else cout << max << " rings." << endl; 
	}
	return 0;
}