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
    void build (int l, int r, int rt);
    void insert (int p, int x, int rt);
    int query (int l, int r, int rt);
};
Node SegmentTree::node[maxsize];
void SegmentTree::build (int l, int r, int rt) {
    node[rt].left = l;
    node[rt].right = r;
    node[rt].mid = (l + r) >> 1;
    node[rt].value = 0;
    if (l < r) {
        int m = (l + r) >> 1;
        build (l, m, rt << 1);
        build (m + 1, r, (rt << 1) | 1);
    }
}
void SegmentTree::insert (int p, int x, int rt) {
    node[rt].value++;
    if (node[rt].left < node[rt].right) {
        if (p <= node[rt].mid) {
            insert (p, x, rt << 1);
        } else {
            insert (p, x, (rt << 1) | 1);
        }
    }
}
int SegmentTree::query (int l, int r, int rt) {
    if ( (l <= node[rt].left) && (node[rt].right <= r)) {
        return node[rt].value;
    } else {
        int c = 0;
        if (l <= node[rt].mid) {
            c += query (l, r, rt << 1);
        }
        if (node[rt].mid < r) {
            c += query (l, r, (rt << 1) | 1);
        }
        return c;
    }
}

struct Line {
    double l, r, y;
    int type;
    bool operator< (Line a) const {
        return y < a.y;
    }
};

class Atlantis {
private:
    int numOfMaps, ans, numOfLines;
    SegmentTree st;
    Line line[MAXN << 2];
    int Times[MAXN << 2];
    double X[MAXN << 2], sum[MAXN];
public:
    void init (int);
    void input();
    void work();
};
void Atlantis::init (int n) {
    numOfMaps = n;
    numOfLines = 0;
    st.build (0, 32000, 1);
    memset (sum, 0, sizeof (sum));
    memset (Times, 0, sizeof (Times));
    ans = 0;
}
void Atlantis::input() {
    for (int i = 1; i <= numOfMaps; i++) {
        double x1, y1, x2, y2;
        scanf ("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
        line[i * 2 - 1].y = y1, line[i * 2 - 1].l = x1, line[i * 2 - 1].r = x2, line[i * 2 - 1].type = 1;
        line[i * 2].y = y2, line[i * 2].l = x1, line[i * 2].r = x2, line[i * 2].type = -1;
        X[++numOfLines] = x1, X[++numOfLines] = x2;
    }
}
void Atlantis::work() {
    sort (X + 1, X + 1 + numOfLines);
    sort (line + 1, line + 1 + numOfMaps * 2);
    for (int i = 1; i < numOfMaps * 2; i++) {
        ans += sum[1] * (line[i].y - line[i - 1].y);
    }
}

int main() {
    Atlantis a;
    int n;
    while (cin >> n && n) {
        a.init (n);
        a.input();
        a.work();
        a.output();
    }
    return 0;
}
