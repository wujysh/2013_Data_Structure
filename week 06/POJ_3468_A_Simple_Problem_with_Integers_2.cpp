#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 263000
using namespace std;

struct Node {
	long long sum, add;
} node[MAXN];

int n, q, p1, p2, v, a[MAXN];
long long qsum;

void build(int o, int L, int R) {
	if (L > R) return;
	int lc = o*2, rc = o*2+1,M = ((R-L)>>1)+L;
	if (L == R) node[o].sum=a[L];
	else {
		build(lc, L, M);
		build(rc, M+1, R);
		node[o].sum = node[lc].sum + node[rc].sum;
	}
}
void maintain(int o,int L,int R) {
	int lc = o*2, rc = o*2+1;
	if (L == R) node[o].sum=a[L];
	else node[o].sum = node[lc].sum + node[rc].sum;
	node[o].sum += node[o].add * (R-L+1);
}
void update(int o, int L, int R, int p1, int p2, int v) {
	int lc = o*2, rc = o*2+1, M = ((R-L)>>1)+L;
	if (p1 <= L && R <= p2)
		node[o].add += v;
	else {
		if (p1 <= M) update(lc, L, M, p1, p2, v);
		if (M < p2) update(rc, M+1, R, p1, p2, v);
	}
	maintain(o, L, R);
}
void query(int o, int L, int R, int p1, int p2, long long add) {
	int lc = o*2, rc = o*2+1, M = ((R-L)>>1)+L;
	if (p1 <=L && R<= p2)
		qsum += node[o].sum + add*(R-L+1);
	else {
		if (p1 <= M) query(lc, L, M, p1, p2, add+node[o].add);
		if (M < p2) query(rc, M+1, R, p1, p2, add+node[o].add);
	}
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	memset(node, 0, sizeof(node));
	build(1, 1 ,n);
	for (int i = 1; i <= q; i++) {
		char c;
		scanf("%c", &c);
		while (c != 'C' && c != 'Q') scanf("%c", &c);
		if (c == 'C') {
			scanf("%d%d%d", &p1, &p2, &v);
			update(1, 1, n, p1, p2, v);
		} else {
			scanf("%d%d", &p1, &p2);
			qsum = 0;
			query(1, 1, n, p1, p2, 0);
			printf("%lld\n", qsum);
		}
	}
	return 0;
}