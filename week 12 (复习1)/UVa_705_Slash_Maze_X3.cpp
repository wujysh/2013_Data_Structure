#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 300

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

class SlashMaze {
private:
	int numOfCycles, LongestLength, width, height, nCase;
	bool Graph[MAXN][MAXN];
	bool Visited[MAXN][MAXN];
	bool isCircle;
public:
	void initial(int, int);
	void input();
	void work();
	void dfs(int, int, int &);
	bool check(int, int, int, int);
	void output();
};
void SlashMaze::initial(int w, int h) {
	width = w * 3;
	height = h * 3;
	LongestLength = 0;
	numOfCycles = 0;
	memset(Graph, true, sizeof(Graph));
	memset(Visited, false, sizeof(Visited));
}
void SlashMaze::input() {
	getchar();
	for (int i = 0; i < height; i += 3) {
		for (int j = 0; j < width; j += 3) {
			char ch;
			ch = getchar();
			if (ch == '/') {
				Graph[i][j + 2] = Graph[i + 1][j + 1] = Graph[i + 2][j] = false;
			}
			if (ch == '\\') {
				Graph[i][j] = Graph[i + 1][j + 1] = Graph[i + 2][j + 2] = false;
			}
		}
		getchar();
	}
}
void SlashMaze::work() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (Graph[i][j] && !Visited[i][j]) {
				int cnt = 1;
				isCircle = true;
				dfs(i, j, cnt);
				if (isCircle) {
					numOfCycles++;
					if (cnt > LongestLength)
						LongestLength = cnt;
				}
			}
		}
	}
}
void SlashMaze::dfs(int x, int y, int &step) {
	if (x < 0 || x >= height || y < 0 || y >= width) {
		isCircle = false;
		step--;
		return;
	}
	if (!Graph[x][y] || Visited[x][y]) {
		step--;
		return;
	}
	Visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		step++;
		dfs(nx, ny, step);
	}
}
bool SlashMaze::check(int nx, int ny, int x, int y) {
	if (nx < 0 || nx >= height) return false;
	if (ny < 0 || ny >= width) return false;
	if (!Graph[nx][ny]) return false;
	if (Visited[nx][ny]) return false;
	return true;
}
void SlashMaze::output() {
	if (numOfCycles) {
		cout << numOfCycles << " Cycles; the longest has length " << LongestLength / 3 << "." << endl;
	} else {
		cout << "There are no cycles." << endl;
	}
	cout << endl;
}

int main() {
	int w, h, nCase = 0;
	SlashMaze sm;
	while (cin >> w >> h && (w || h)) {
		nCase++;
		sm.initial(w, h);
		sm.input();
		sm.work();
		cout << "Maze #" << nCase << ":" << endl;
		sm.output();
	}
	return 0;
}