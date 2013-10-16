#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 500010;

int n, arr[MAXN], hashtable[MAXN]; 
__int64 c[MAXN<<2];

struct node {
	int val, id;
	friend bool operator<(const node &a, const node &b) {
		return a.val < b.val;
	}
} tmp[MAXN];

void update(int rt, int left, int right, int data) {
	c[rt]++;
	if (left == right) return;
	int m = (left + right) >> 1;
	if (data <= m) update(rt << 1, left, m, data);
	else update((rt << 1) | 1, m+1, right, data);
}

__int64 query(int rt, int left, int right, int l, int r) {
	if (left == l && right == r) return c[rt];
	int m = (left + right) >> 1;
	if (r <= m) return query(rt << 1, left, m, l, r);
	else if(l > m) return query((rt << 1) | 1, m+1, right, l, r);
	else return query(rt << 1, left, m, l, (left + right) >> 1) + query((rt << 1) | 1, m+1, right, ((left + right) >> 1) + 1, r);
}

int main() {
	while (~scanf("%d", &n) && n) {
		memset(c, 0, sizeof(c));
		memset(hashtable, 0, sizeof(hashtable));
		for(int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			tmp[i].val = arr[i];
			tmp[i].id = i;
		}
		sort(tmp, tmp + n);
		for(int i = 0; i < n; i++){
			hashtable[tmp[i].id] = i + 1;
		} 
		__int64 ans=0;
		for(int i = 0; i < n; i++){
			int x = hashtable[i];
			ans += query(1, 1, n + 1, x + 1, n + 1);
			update(1, 1, n+1, x);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
