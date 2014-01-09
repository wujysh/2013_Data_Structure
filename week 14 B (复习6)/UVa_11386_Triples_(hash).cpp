#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//const int MAXN = 5010;
//template <class T>
//class HASH {
//private:
//	int pos;
//	int next[MAXN];
//	int head[MAXN];
//	T key[MAXN];
//public:
//	HASH();
//	int search(T x);
//	void push(T x);
//	int cnt[MAXN];
//};
//template <class T>
//HASH<T>::HASH() {
//	pos = 0;
//	memset(next, -1, sizeof(next));
//	memset(head, -1, sizeof(head));
//	memset(cnt, 0, sizeof(cnt));
//	//memset(key,-1,sizeof(key));
//}
//template <class T>
//inline int HASH<T>::search(const T x) {
//	int temp = x % MAXN;
//	int t = head[temp];
//	while (t != -1) {
//		if (key[t] == x) {
//			//return 1;
//			return cnt[temp];
//		}
//		t = next[t];
//	}
//	return 0;
//}
//template <class T>
//inline void HASH<T>::push(const T x) {
//	int temp = x % MAXN;
//	if (head[temp] != -1) {
//		next[pos] = head[temp];
//	}
//	head[temp] = pos;
//	key[pos] = x;
//	cnt[temp]++;
//	pos++;
//}
//
//int main() {
//	long long n, num[MAXN], ans;
//	while (scanf("%lld", &n) != EOF) {
//		HASH <long long> h;
//		ans = 0;
//
//		for (int i = 0; i < n; i++) {
//			scanf("%lld", &num[i]);
//			h.push(num[i]);
//		}
//
//		sort(num, num + n);
//
//		for (int i = 0; i < n - 2; i++) {
//			for (int j = i + 1; j < n - 1; j++) {
//				ans += h.search(num[i] + num[j]);
//			}
//		}
//		printf("%lld\n", ans);
//	}
//	return 0;
//}


#include <stdio.h>
#include <algorithm>
#define N 1048575
using namespace std;
int hash1[N + 1];
typedef struct {
	int next, t;
	unsigned v;
} Node;
Node nd[5005];
int size = 0;
void insert(unsigned v) {
	static unsigned m;
	static int now, pre;
	m = v & N, now = hash1[m], pre = 0;
	while (now) {
		if (nd[now].v == v) {
			nd[now].t++;
			return;
		}
		if (nd[now].v > v)
			break;
		pre = now, now = nd[now].next;
	}
	size++;
	if (!pre)    hash1[m] = size;
	else        nd[pre].next = size;
	nd[size].v = v, nd[size].t = 1;
	nd[size].next = now;
}
int find(unsigned v) {
	static unsigned m;
	static int now, pre;
	m = v & N, now = hash1[m], pre = 0;
	while (now) {
		if (nd[now].v == v)
			return nd[now].t;
		if (nd[now].v > v)
			return 0;
		pre = now, now = nd[now].next;
	}
	return 0;
}
int main() {
	int n, i, j;
	unsigned a[5000], b[5000], f[5000];
	while (scanf("%d", &n) == 1) {
		for (i = 1; i <= size; i++) {
			hash1[nd[i].v&N] = 0;
		}
		size = 0;
		for (i = 0; i < n; i++) {
			scanf("%u", &a[i]);
			insert(a[i]);
		}
		sort(a, a + n);
		int m = 0;
		for (i = 0; i < n; i++) {
			if (m == 0 || a[i] != b[m - 1]) {
				b[m] = a[i];
				f[m] = 1;
				m++;
			} else {
				f[m - 1]++;
			}
		}
		long long ans = 0;
		for (i = 0; i < m; i++) {
			ans += find(b[i] + b[i])*f[i] * (f[i] - 1) / 2;
			for (j = i + 1; j < m; j++) {
				ans += find(b[i] + b[j])*f[i] * f[j];
			}
		}
		printf("%lld\n", ans);

	}
	return 0;
}

