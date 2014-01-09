#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 55;
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

class TheDieIsCast {
private:
	int width, height, nCase = 0;
	int graph[MAXN][MAXN];
	priority_queue <int> ans;
public:
	void init(int, int);
	bool check(int, int);
	void dfs(int, int, int &);
	void dfs2(int, int);
	void input();
	void work();
	void output();
};
void TheDieIsCast::init(int w, int h) {
	width = w;
	height = h;
	memset(graph, 0, sizeof(graph));
	while (!ans.empty()) ans.pop();
	nCase++;
}
bool TheDieIsCast::check(int x, int y) {
	if (x < 0 || x >= height) return false;
	if (y < 0 || y >= width) return false;
	return true;
}
void TheDieIsCast::dfs(int x, int y, int &cnt) {
	if (graph[x][y] == 2) {
		cnt++;
		dfs2(x, y);
	}
	graph[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (check(nx, ny) && graph[nx][ny]) {
			dfs(nx, ny, cnt);
		}
	}
}
void TheDieIsCast::dfs2(int x, int y) {
	graph[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (check(nx, ny) && graph[nx][ny] == 2) {
			dfs2(nx, ny);
		}
	}
}
void TheDieIsCast::input() {
	char ch;
	for (int i = 0; i < height; i++) {
		getchar();
		for (int j = 0; j < width; j++) {
			ch = getchar();
			if (ch == '*') {
				graph[i][j] = 1;
			} else if (ch == 'X') {
				graph[i][j] = 2;
			}
		}
	}
}
void TheDieIsCast::work() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (graph[i][j]) {
				int cnt = 0;
				dfs(i, j, cnt);
				ans.push(-cnt);
			}
		}
	}
}
void TheDieIsCast::output() {
	int cnt = 0;
	cout << "Throw " << nCase << endl;
	while (!ans.empty()) {
		if (cnt++) cout << " ";
		cout << -ans.top();
		ans.pop();
	}
	cout << endl << endl;
}

int main() {
	TheDieIsCast tdic;
	int w, h;
	while (cin >> w >> h && (w || h)) {
		tdic.init(w, h);
		tdic.input();
		tdic.work();
		tdic.output();
	}
	return 0;
}