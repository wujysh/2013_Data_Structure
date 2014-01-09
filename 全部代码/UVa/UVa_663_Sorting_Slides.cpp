#include <cstdio>
#include <cstring>
using namespace std;

int N, head[50], lef[50], T[50], flag, cnt;

struct node {
	int x1, y1, x2, y2;
} re[50];

struct Point {
	int x, y;
} p[50];

struct Edge {
	int from, to, next;
} edges[100000];

void addedge(int u, int v) {
	edges[cnt].from = u, edges[cnt].to = v;
	edges[cnt].next = head[u], head[u] = cnt++;
}

bool match(int x) {
	int i, j;
	for (i = head[x]; i != -1; i = edges[i].next) {
		if (i == flag) {
			continue;
		}
		int v = edges[i].to;
		if (!T[v]) {
			T[v] = 1;
			if (lef[v] == -1 || match(lef[v])) {
				lef[v] = x;
				return true;
			}
		}
	}
	return false;
}

int solve() {
	int i, j;
	int res = 0;
	memset(lef, -1, sizeof(lef));
	for (i = 0; i < N; i++) {
		memset(T, 0, sizeof(T));
		if (match(i)) {
			res++;
		}
	}
	return res;
}

int main() {
	int i, j;
	int test = 0;
	while (scanf("%d", &N) == 1 && N) {
		for (i = 0; i < N; i++) {
			scanf("%d %d %d %d", &re[i].x1, &re[i].x2, &re[i].y1, &re[i].y2);
		}
		for (i = 0; i < N; i++) {
			scanf("%d %d", &p[i].x, &p[i].y);
		}
		memset(head, -1, sizeof(head));
		cnt = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (p[i].x > re[j].x1 && p[i].x < re[j].x2 && p[i].y > re[j].y1 && p[i].y < re[j].y2) {
					addedge(j, i);
				}
			}
		}
		flag = -2;
		int res = solve();
		int ok = 0;
		printf("Heap %d\n", ++test);
		for (i = 0; i < N; i++) {
			for (j = head[i]; j != -1; j = edges[j].next) {
				flag = j;
				if (solve() != res) {
					if (ok) {
						printf(" ");
					}
					ok = 1;
					printf("(%c,%d)", i + 'A', edges[j].to + 1);
				}
			}
		}
		if (ok == 0) {
			printf("none\n\n");
		} else {
			printf("\n\n");
		}
	}
	return 0;
}