#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxsize = 263000;

struct Node {
	int left, right, mid;
	__int64 value;
};

class SegmentTree {
private:
	static Node node[maxsize];
public:
	void build(int l, int r, int rt);
	void insert(int p, int x, int rt);
	__int64 query(int l, int r, int rt);
};
Node SegmentTree::node[maxsize];
void SegmentTree::build(int l, int r, int rt) {
	node[rt].left = l;
	node[rt].right = r;
	node[rt].mid = (l + r) >> 1;
	node[rt].value = 0; 
	if (l < r) {
		int m = (l + r) >> 1;
		build(l, m, rt << 1);
		build(m + 1, r, (rt << 1)|1);
	}
}
void SegmentTree::insert(int p, int x, int rt) {
	node[rt].value += x;
	if (node[rt].left < node[rt].right) {
		if (p <= node[rt].mid) {
			insert(p, x, rt << 1);
		} else {
			insert(p, x, (rt << 1) | 1);
		} 
	}
}
__int64 SegmentTree::query(int l, int r, int rt) {
	if ((l <= node[rt].left)&&(node[rt].right <= r)) {
		return node[rt].value;
	} else {
		__int64 c = 0;
		if (l <= node[rt].mid) {
			c += query(l, r, rt << 1);
		}
		if (node[rt].mid < r) {
			c += query(l, r, (rt << 1) | 1);
		}
		return c;
	}
}

struct Integer {
	int position;
	__int64 value;
	Integer(int a = 0, __int64 b = 0) {position = a; value = b;}
	friend bool operator < (Integer i1, Integer i2) {
		return i1.value < i2.value;
	}
};

int main() {
	// initial the program
	vector <Integer> integer;
	SegmentTree st;
	// input data
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		__int64 x;
		scanf("%d", &x);
		integer.push_back(Integer(i, x));
	}
	
	// build segment tree
	st.build(1, integer.size(), 1);
	sort(integer.begin(), integer.end());
	for (int i = 0; i < integer.size(); i++) {
		st.insert(integer[i].position, integer[i].value, 1);
	}
	// query the segment tree
	for (int i = 0; i < q; i++) {
		char op;
		int a, b;
		__int64 c;
		getchar();
		scanf("%c%d%d", &op, &a, &b);
		//cin >> op >> a >> b;
		if (op == 'C') {
			scanf("%lld", &c);
			for (int i = a-1; i < b; i++) {
				st.insert(integer[i].position, c, 1);
			}
		} else {
			printf("%lld\n", st.query(a, b, 1));
		}
	}
	return 0;
}
