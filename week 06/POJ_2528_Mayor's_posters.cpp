#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 11111;
bool hashi[maxn];
int li[maxn], ri[maxn];
int X[maxn*3];  /*最多3倍~*/
int col[maxn<<4];  /*2X的空间复杂度是普通的四倍*/
int cnt;

void PushDown(int rt) {
	if (col[rt] != -1) {
		col[rt<<1] = col[rt<<1|1] = col[rt]; /*直接赋值  覆盖之~*/
		col[rt] = -1;
	}
}

void update(int L, int R, int c, int l, int r, int rt) {
	if (L <= l && r <= R) {
		col[rt] = c;
		return; /*盖了果断return*/
	}
	PushDown(rt);
	int m = (l + r) >> 1;
	if (L <= m) update(L, R, c, l, m, rt << 1);
	if (m < R) update(L, R, c, m+1, r, (rt << 1) | 1);
}    

void query(int l,int r,int rt) {
	if (col[rt] != -1) {
		if (!hashi[col[rt]]) cnt++;
		hashi[col[rt]] = true;
		return; /*由于这里是直接return，在最顶层的mark处直接跳过此区间，所以不用在下面加PushDown*/
	}
	if (l == r) return ;
	int m = (l + r) >> 1;
	query(l, m, rt << 1);
	query(m+1, r, (rt << 1) | 1);
}

int Bin(int key, int n, int X[]) { /*离散化哈希函数*/
	int l = 0, r = n - 1;
	while (l <= r) {             /*离散化哈希--二分映射*/
		int m = (l + r) >> 1;
		if (X[m] == key) return m;
		if (X[m] < key) l = m + 1;
		else r = m - 1;
	}    
	return -1;      /*注意key值一定要在X中，否则各种跪*/
}

int main() {
	int T, n;
	scanf("%d",&T);
	while (T --) {
		scanf("%d", &n);
		int nn = 0;
		for (int i = 0; i < n; i ++) {  /*把所有出现的数装在X里*/
			scanf("%d%d",&li[i], &ri[i]);
			X[nn++] = li[i];
			X[nn++] = ri[i];
		}
		sort(X, X + nn);
		int m = 1;
		for (int i = 1; i < nn; i ++) {  /*排序之后去重*/
			if (X[i] != X[i-1]) X[m ++] = X[i];
		}
		for (int i = m - 1; i > 0; i --) {  /*离散化技巧：凸显间隔（可避免上文的数据2出错）*/ 
			if (X[i] != X[i-1] + 1) X[m ++] = X[i-1] + 1;
		}
		sort(X, X + m);  /*再次排序，便于之后设计映射时用二分高效hash*/
		memset(col, -1, sizeof(col));
		for (int i = 0; i < n; i ++) {
			int l = Bin(li[i], m, X);  /*Bin为离散哈希函数*/
			int r = Bin(ri[i], m, X);  /*Bin为离散哈希函数*/
			update(l, r, i, 0, m, 1);  /*以离散后的键值更新线段树*/
		}
		cnt = 0;
		memset(hashi, false, sizeof(hashi));
		query(0, m, 1);
		printf("%d\n",cnt);
	}    
	return 0;    
}  