#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace std;
#define MAXN 50010
int set[MAXN], cnt[MAXN];

int findset(int x) {
	return set[x] == x ? x : set[x] = findset(set[x]);
}

int main() {
	int nCase = 0;
	int n, m;
	while (cin >> n >> m && n && m) {
		nCase++;
		for (int i = 1; i <= n; i++) {
			set[i] = i;
			cnt[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int a, b, x, y;
			scanf("%d %d", &a, &b);
			x = findset(a);
			y = findset(b);
			if (x != y) set[x] = y;
		}

		for (int i = 1; i <= n; i++) {
			cnt[findset(i)]++;
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt[i]) ans++;
		}
		printf("Case %d: %d\n", nCase, ans);
	}
	return 0;
}