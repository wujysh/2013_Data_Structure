#include <iostream>
using namespace std;

const int MAXN = 10010;

int Sets[MAXN<<1], Rank[MAXN<<1];

int Find(int x) {
	return Sets[x] == x ? x : Sets[x] = Find(Sets[x]);
}

void Union(int x, int y) {
	if (Rank[x] < Rank[y]) {
		Sets[x] = y;
		//Sums[y] += Sums[x];
	} else {
		if (Rank[x] == Rank[y])
			Rank[x] ++;
		Sets[y] = x;
		//Sums[x] += Sums[y];
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < (n << 1); i++) {
		Sets[i] = i;
		Rank[i] = 1;
	}
	int c, x, y;
	while (cin >> c >> x >> y && (c || x || y)) {
		int x1, x2, y1, y2;
		x1 = Find(x);  x2 = Find(x + n);
		y1 = Find(y);  y2 = Find(y + n);
		if (c == 1) {
			if (x1 == y2) {
				cout << "-1" << endl;
			} else {
				Union(x1, y1);
				Union(x2, y2);
			}
		} else if (c == 2) {
			if (x1 == y1) {
				cout << "-1" << endl;
			} else {
				Union(x1, y2);
				Union(x2, y1);
			}
		} else if (c == 3) {
			if (x1 == y1) {
				cout << "1" << endl;
			} else {
				cout << "0" << endl;
			}
		} else if (c == 4) {
			if (x1 == y2) {
				cout << "1" << endl;
			} else {
				cout << "0" << endl;
			}
		}
	}
	return 0;
}
