#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

const int MAXN = 510;
const int dx[4] = { -1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

char graph[MAXN][MAXN];
int begin_x, begin_y, end_x, end_y;
int n, m, t;

struct Node {
    int x, y, time;
    friend bool operator < (Node a, Node b) {
        return a.time > b.time;
    }
};

void bfs() {
    priority_queue <Node> q;
    Node next, cur;
    next.x = begin_x;  next.y = begin_y;  next.time = 0;
    graph[next.x][next.y] = '#';
    q.push(next);
    while (!q.empty()) {
        cur = q.top();
        q.pop();
        if (cur.x == end_x && cur.y == end_y) {
            cout << cur.time + 1 << endl;
            return;
        }
        for (int i = 0; i < 4; i++) {
            next.x = cur.x + dx[i];  next.y = cur.y + dy[i];
            if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m || graph[next.x][next.y] == '#') continue;
            if (graph[next.x][next.y] == '.') {
                next.time = cur.time + 1;
            } else {
                next.time = cur.time + t + 1;
            }
            graph[next.x][next.y] = '#';
            q.push(next);
        }
    }
}

int main() {
    int nCase;
    cin >> nCase;
    while (nCase--) {
        cin >> n >> m >> t;
        for (int i = 0; i < n; i++) {
            scanf("%s", graph[i]);
            for (int j = 0; j < m; j++) {
                if (graph[i][j] == 'S') {
                    begin_x = i;  begin_y = j;
                }
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && graph[i][j] != '#') {
                    end_x = i;  end_y = j;
                }
            }
        }

        bfs();
    }
    return 0;
}
