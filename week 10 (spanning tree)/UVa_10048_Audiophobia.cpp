#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAXN 110

struct edge {
	int a, b;
	int len;
	friend bool operator < (const edge a, const edge b) {
		return a.len > b.len;
	}
};
priority_queue <edge> q, bak_q;

int root[MAXN], bak_root[MAXN];

int findroot(int x) {
	return root[x] == x ? x : root[x] = findroot(root[x]);
}

int main() {
	int c, s, nq, cnt = 0;
	while (cin >> c >> s >> nq && (c || s || nq)) {
		cnt++;

		for (int i = 1; i <= c; i++) {
			root[i] = i;
		}
		memcpy(bak_root, root, sizeof(root));

		while (!q.empty()) q.pop();
		for (int i = 0; i < s; i++) {
			edge e;
			cin >> e.a >> e.b >> e.len;
			q.push(e);
		}
		bak_q = q;

		if (cnt > 1) cout << endl;
		cout << "Case #" << cnt << endl;

		for (int i = 0; i < nq; i++) {
			int start, destination;
			cin >> start >> destination;

			q = bak_q;
			memcpy(root, bak_root, sizeof(bak_root));
			bool flag = false;

			while (!q.empty()) {
				edge e = q.top();
				q.pop();
				if (findroot(e.a) != findroot(e.b)) {
					root[findroot(e.a)] = findroot(e.b);
				}
				if (findroot(start) == findroot(destination)) {
					cout << e.len << endl;
					flag = true;
					break;
				}
			}
			if (!flag) cout << "no path" << endl;
		}
	}
	return 0;
}
