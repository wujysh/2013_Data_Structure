#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <map>
using namespace std;

const int N = 55;
const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };

struct State {
	int x, y, dir, time;
	State(int a, int b, int c, int d) {
		x = a;  y = b;  dir = c;  time = d;
	}
};

class Robot {
private:
	int m, n, time, minTime, dest_x, dest_y;
	bool graph[N][N];
	bool visited[N][N][4];
	queue <State> q;
	map <string, int> dirCvt;
public:
	void init(int, int);
	void input();
	bool check(int, int);
	void work();
	void output();
};
void Robot::init(int r, int c) {
	m = r;  n = c;
	time = 0;  minTime = 0x3f;  // minTime = INF;
	dest_x = 0;  dest_y = 0;
	memset(graph, false, sizeof(graph));
	memset(visited, false, sizeof(visited));
	while (!q.empty()) q.pop();
	dirCvt["east"] = 0; dirCvt["south"] = 1; dirCvt["west"] = 2; dirCvt["north"] = 3;
}
void Robot::input() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	int x1, y1, dir;
	string direct;
	cin >> x1 >> y1 >> dest_x >> dest_y >> direct;
	dir = dirCvt[direct];
	if (check(x1, y1)) {
		q.push(State(x1, y1, dir, 0));
		visited[x1][y1][dir] = true;
	}
}
bool Robot::check(int x, int y) {
	if (x <= 0 || x >= m || y <= 0 || y >= n) return false;
	if (graph[x][y] || graph[x - 1][y] || graph[x][y - 1] || graph[x - 1][y - 1]) return false;
	return true;
}
void Robot::work() {
	while (!q.empty()) {
		State cur = q.front();
		q.pop();
		int x = cur.x, y = cur.y, dir = cur.dir, time = cur.time;

		if (x == dest_x && y == dest_y) {
			if (time < minTime) {
				minTime = time;
				continue;
			}
		}

		for (int i = 1; i <= 3; i += 2) {  // TURN i (i=1:right; i=3: left)
			int ndir = (dir + i) % 4;
			if (!visited[x][y][ndir]) {  // TURN right
				q.push(State(x, y, ndir, time + 1));
				visited[x][y][ndir] = true;
			}
		}
		for (int i = 1; i <= 3; i++) {  // GO i (i=1,2,3)
			int nx = x + dx[dir] * i, ny = y + dy[dir] * i;
			if (check(nx, ny)) {
				if (visited[nx][ny][dir]) continue;
				q.push(State(nx, ny, dir, time + 1));
				visited[nx][ny][dir] = true;
			} else break;
		}
	}
}
void Robot::output() {
	if (minTime == 0x3f)
		cout << "-1" << endl;
	else
		cout << minTime << endl;
}

int main() {
	int m, n;
	Robot r;
	while (cin >> m >> n && (m || n)) {
		r.init(m, n);
		r.input();
		r.work();
		r.output();
	}
	return 0;
}