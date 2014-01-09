#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 50010;
int height[MAXN], mmax, mmin;

const int maxsize = 263000;

struct Node {
	int left, right, mid;
	int max, min;
};

class SegmentTree {
private:
	static Node node[maxsize];
public:
	void build(int l, int r, int rt);
	void query(int l, int r, int rt);
};
Node SegmentTree::node[maxsize];
void SegmentTree::build(int l, int r, int rt) {
	node[rt].left = l;
	node[rt].right = r;
	node[rt].mid = (l + r) >> 1;
	if (l < r) {
		int m = (l + r) >> 1;
		build(l, m, rt << 1);
		build(m + 1, r, (rt << 1) | 1);
		node[rt].max = max(node[rt << 1].max, node[(rt << 1) | 1].max);
		node[rt].min = min(node[rt << 1].min, node[(rt << 1) | 1].min);
	} else if (l == r) {
		node[rt].max = node[rt].min = height[l];
	}
}
void SegmentTree::query(int l, int r, int rt) {
	if (l <= node[rt].left && node[rt].right <= r) {
		mmax = max(mmax, node[rt].max);
		mmin = min(mmin, node[rt].min);
	} else {
		if (l <= node[rt].mid) {
			query(l, r, rt << 1);
		}
		if (node[rt].mid < r) {
			query(l, r, (rt << 1) | 1);
		}
	}
}

class BalancedLineup {
private:
	int numOfCows, numOfQueries;
	SegmentTree st;
public:
	void init(int n, int q) {
		numOfCows = n;
		numOfQueries = q;
	}
	void input();
	void work();
	void query();
};
void BalancedLineup::input() {
	int h;
	for (int i = 1; i <= numOfCows; i++) {
		scanf("%d", &height[i]);
	}
}
void BalancedLineup::work() {
	st.build(1, numOfCows, 1);
}
void BalancedLineup::query() {
	int l, r;
	for (int i = 0; i < numOfQueries; i++) {
		scanf("%d%d", &l, &r);
		mmax = 0;  mmin = 1000000;
		st.query(l, r, 1);
		printf("%d\n", mmax - mmin);
	}
}

int main() {
	BalancedLineup bl;
	int n, q;
	while (cin >> n >> q) {
		bl.init(n, q);
		bl.input();
		bl.work();
		bl.query();
	}
	return 0;
}