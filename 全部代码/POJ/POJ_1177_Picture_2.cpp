#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXN = 5010;

vector <int> y;

struct Node {
	int left, right, num, len, cover;
	bool lb, rb;
};

struct Line {
	int x;
	int y1, y2;
	int flag;  // 1 - in;  -1 - out;
	friend bool operator<(const Line l1, const Line l2) {
		if (l1.x == l2.x) return l1.flag > l2.flag;
		return l1.x < l2.x;
	}
};

Node node[MAXN << 2];
void clear() {
	memset(node, 0, sizeof(node));
}
void build(int l, int r, int rt) {
	node[rt].left = l;
	node[rt].right = r;
	node[rt].num = 0;
	if (l < r - 1) {
		int m = (l + r) >> 1;
		build(l, m, rt << 1);
		build(m, r, (rt << 1) | 1);
	}
}
void update_len(int rt) {
	if (node[rt].cover > 0) {
		node[rt].lb = node[rt].rb = true;
		node[rt].num = 1;
		node[rt].len = y[node[rt].right] - y[node[rt].left];
	} else if (node[rt].left == node[rt].right - 1) {
		node[rt].rb = node[rt].lb = false;
		node[rt].len = node[rt].num = 0;
	} else {
		node[rt].rb = node[(rt << 1) | 1].rb;
		node[rt].lb = node[rt << 1].lb;
		node[rt].len = node[rt << 1].len + node[(rt << 1) | 1].len;
		node[rt].num = node[rt << 1].num + node[(rt << 1) | 1].num - node[(rt << 1) | 1].lb*node[rt << 1].rb;
	}
}
void update(int rt, Line line) {
	if (y[node[rt].left] >= line.y1 && y[node[rt].right] <= line.y2) {
		node[rt].cover += line.flag;
		update_len(rt);
		return;
	}
	if (node[rt].left < node[rt].right - 1) {
		int m = (node[rt].left + node[rt].right) >> 1;
		if (line.y1 <= y[m]) update(rt << 1, line);
		if (line.y2 > y[m]) update((rt << 1) | 1, line);
		update_len(rt);
	}
}

	int numOfRects, ans, last, lines;
	vector <Line> line;

void init() {
	clear();
	line.clear();
	y.clear();
	ans = last = lines = 0;
}
void input() {
	cin >> numOfRects;
	for (int i = 0; i < numOfRects; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		Line l;
		l.x = x1; l.y1 = y1; l.y2 = y2; l.flag = 1;
		line.push_back(l);
		l.x = x2; l.y1 = y1; l.y2 = y2; l.flag = -1;
		line.push_back(l);
		y.push_back(y1);
		y.push_back(y2);
	}
}
void work() {
	sort(line.begin(), line.end());
	sort(y.begin(), y.end());
	unique(y.begin(), y.end());
	build(0, y.size() - 1, 1);
	for (unsigned i = 0; i < line.size(); i++) {
		update(1, line[i]);
		if (i >= 1)
			ans += 2 * lines * (line[i].x - line[i - 1].x);
		ans += abs(node[1].len - last);
		last = node[1].len;
		lines = node[1].num;
	}
}
void output() {
	cout << ans << endl;
}

int main() {
	init();
	input();
	work();
	output();
	return 0;
}