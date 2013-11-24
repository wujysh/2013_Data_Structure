#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
#define MAXN 50010
int set[MAXN], cnt[MAXN];

int findset(int x) {
	return set[x] == x ? x : set[x] = findset(set[x]);
}

int main() {
	int nCase;
	scanf("%d", &nCase);
	getchar();  getchar();
	while (nCase--) {
		int n;
		char ch, str[50];
		scanf("%c", &ch);
		getchar();
		n = ch - 'A' + 1;
		for (int i = 1; i <= n; i++) {
			set[i] = i;
			cnt[i] = 0;
		}
		while (gets(str) && str[0]) {
			char a, b;
			sscanf(str, "%c%c", &a, &b);
			int x, y;
			x = findset(a - 'A' + 1);
			y = findset(b - 'A' + 1);
			if (x != y) set[x] = y;
		}

		for (int i = 1; i <= n; i++) {
			cnt[findset(i)]++;
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt[i]) ans++;
		}
		printf("%d\n", ans);
		if (nCase) printf("\n");
	}
	return 0;
}
