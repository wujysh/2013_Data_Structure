#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
#define MAXN 1000010
int set[MAXN];

int findset(int x) {
	return set[x] == x ? x : set[x] = findset(set[x]);
}

int main() {
	int nCase;
	scanf("%d", &nCase);
	while (nCase--) {
		int n, successfully = 0, unseccessfully = 0;
		char str[50];
		scanf("%d", &n);
		getchar();
		for (int i = 1; i <= n; i++) {
			set[i] = i;
		}
		while (gets(str) && str[0]) {
			char op;
			int a, b;
			sscanf(str, "%c %d %d", &op, &a, &b);
			if (op == 'c') {
				int x, y;
				x = findset(a);
				y = findset(b);
				if (x != y) set[x] = y;
			} else if (op == 'q') {
				if (findset(a) == findset(b)) {
					successfully++;
				} else {
					unseccessfully++;
				}
			}
		}

		printf("%d,%d\n", successfully, unseccessfully);
		if (nCase) printf("\n");
	}
	return 0;
}
