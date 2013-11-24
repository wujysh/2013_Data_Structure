#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[101][101], b[101], cnt=0, N;

void dfs(int x)
{
	b[x] = 0;
	cnt++;
	for (int i = 1; i <= N; i++) {
		if (b[i] && a[x][i]) {
			dfs(i);
		}
	}
}

int main()
{
	while (scanf("%d",&N)==1 && N!=0) {
		getchar();

		memset(a, 0, sizeof(a));
		int n, result=0, x;

		char buf[10000], *p;

		while (gets(buf)) {
			if (!strcmp(buf, "0")) break;
			p = strtok(buf," ");
			sscanf(p,"%d",&n);

			while ((p=strtok(NULL," "))) {
				sscanf(p,"%d",&x);

				a[n][x] = a[x][n] = 1;
			}
		}

		for (int i = 1; i <= N; i++) {
			memset(b, 1, sizeof(b));
			b[i] = 0;  // disable one exchange
			cnt = 0;

			if (i+1 <= N) dfs(i+1);
			else dfs(1);

			if (cnt < N-1) {
				result++;
			}
		}
		cout << result << endl;
	}
	return 0;
}
