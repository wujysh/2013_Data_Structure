#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxsize = 330000;

struct Node {
	int left, right, mid, value;
};

class SegmentTree {
private:
	static Node node[maxsize];
public:
	void build(int l, int r, int rt);
	void insert(int p, int x, int rt);
	int query(int l, int r, int rt);
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
	node[rt].value++;
	if (node[rt].left < node[rt].right) {
		if (p <= node[rt].mid ) {
			insert(p, x, rt << 1);
		} else {
			insert(p, x, (rt << 1) | 1);
		} 
	}
}
int SegmentTree::query(int l, int r, int rt) {
	if ((l <= node[rt].left)&&(node[rt].right <= r)) {
		return node[rt].value;
	} else {
		int c = 0;
		if (l <= node[rt].mid) {
			c += query(l, r, rt << 1);
		}
		if (node[rt].mid < r) {
			c += query(l, r, (rt << 1) | 1);
		}
		return c;        
	}
}

class Stars {
private:
	vector <int> level;
	int numberOfStars;
	SegmentTree st;
public:
	void initial();
	void work();
};
void Stars::initial() {
	st.build(0, 32000, 1);
	level.clear();
}
void Stars::work() {
	scanf("%d", &numberOfStars);
	level.resize(numberOfStars);

	for (int i = 0; i < numberOfStars; i++) {
		int p, h;
		scanf("%d%d", &p, &h);

		level[st.query(0, p, 1)]++;

		st.insert(p, h, 1);
	}
	for (int i = 0; i < level.size(); i++) {
		cout << level[i] << endl;
	}
}

int main() {
	Stars s;

	s.initial();
	s.work();

	return 0;
}