#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 11111;
bool hashi[maxn];
int li[maxn], ri[maxn];
int X[maxn*3];  /*���3��~*/
int col[maxn<<4];  /*2X�Ŀռ临�Ӷ�����ͨ���ı�*/
int cnt;

void PushDown(int rt) {
	if (col[rt] != -1) {
		col[rt<<1] = col[rt<<1|1] = col[rt]; /*ֱ�Ӹ�ֵ  ����֮~*/
		col[rt] = -1;
	}
}

void update(int L, int R, int c, int l, int r, int rt) {
	if (L <= l && r <= R) {
		col[rt] = c;
		return; /*���˹���return*/
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
		return; /*����������ֱ��return��������mark��ֱ�����������䣬���Բ����������PushDown*/
	}
	if (l == r) return ;
	int m = (l + r) >> 1;
	query(l, m, rt << 1);
	query(m+1, r, (rt << 1) | 1);
}

int Bin(int key, int n, int X[]) { /*��ɢ����ϣ����*/
	int l = 0, r = n - 1;
	while (l <= r) {             /*��ɢ����ϣ--����ӳ��*/
		int m = (l + r) >> 1;
		if (X[m] == key) return m;
		if (X[m] < key) l = m + 1;
		else r = m - 1;
	}    
	return -1;      /*ע��keyֵһ��Ҫ��X�У�������ֹ�*/
}

int main() {
	int T, n;
	scanf("%d",&T);
	while (T --) {
		scanf("%d", &n);
		int nn = 0;
		for (int i = 0; i < n; i ++) {  /*�����г��ֵ���װ��X��*/
			scanf("%d%d",&li[i], &ri[i]);
			X[nn++] = li[i];
			X[nn++] = ri[i];
		}
		sort(X, X + nn);
		int m = 1;
		for (int i = 1; i < nn; i ++) {  /*����֮��ȥ��*/
			if (X[i] != X[i-1]) X[m ++] = X[i];
		}
		for (int i = m - 1; i > 0; i --) {  /*��ɢ�����ɣ�͹�Լ�����ɱ������ĵ�����2����*/ 
			if (X[i] != X[i-1] + 1) X[m ++] = X[i-1] + 1;
		}
		sort(X, X + m);  /*�ٴ����򣬱���֮�����ӳ��ʱ�ö��ָ�Чhash*/
		memset(col, -1, sizeof(col));
		for (int i = 0; i < n; i ++) {
			int l = Bin(li[i], m, X);  /*BinΪ��ɢ��ϣ����*/
			int r = Bin(ri[i], m, X);  /*BinΪ��ɢ��ϣ����*/
			update(l, r, i, 0, m, 1);  /*����ɢ��ļ�ֵ�����߶���*/
		}
		cnt = 0;
		memset(hashi, false, sizeof(hashi));
		query(0, m, 1);
		printf("%d\n",cnt);
	}    
	return 0;    
}  