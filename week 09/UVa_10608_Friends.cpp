#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 30010
int set[MAXN], cnt[MAXN];
int n, m;

int findset(int x) {
	return set[x] == x ? x : set[x] = findset(set[x]);
}

int main() {
	int nCase;
	scanf("%d", &nCase);
	while (nCase--) {
		int n, m;
		scanf("%d %d", &n, &m);
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

		int max = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt[i] > max)
				max = cnt[i];
		}
		printf("%d\n", max);
	}
	return 0;
}