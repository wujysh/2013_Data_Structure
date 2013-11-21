#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 160

const int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

class SlashMaze {
private:
	int numOfCycles, LongestLength, width, height, nCase;
	int last_x, last_y;
	int Graph[MAXN][MAXN];  // 0-" "; 1-"/"; 2-"\"
	bool Visited[MAXN][MAXN];
public:
	void initial(int, int);
	void input();
	void work();
	void dfs(int, int, int &);
	bool check(int, int, int, int);
	void output();
};
void SlashMaze::initial(int w, int h) {
	width = w;
	height = h;
	LongestLength = 0;
	numOfCycles = 0;
	memset(Graph, 0, sizeof(Graph));
	memset(Visited, false, sizeof(Visited));
}
void SlashMaze::input() {
	getchar();
	for (int i = 0; i < height * 2; i += 2) {
		for (int j = 0; j < width * 2; j += 2) {
			char ch;
			ch = getchar();
			if (ch == '/') {
				Graph[i][j] = Graph[i + 1][j + 1] = 0;
				Graph[i + 1][j] = Graph[i][j + 1] = 1;
			}
			if (ch == '\\') {
				Graph[i][j] = Graph[i + 1][j + 1] = 2;
				Graph[i + 1][j] = Graph[i][j + 1] = 0;
			}
		}
		getchar();
	}
}
void SlashMaze::work() {
	for (int i = 0; i < height * 2; i++) {
		for (int j = 0; j < width * 2; j++) {
			if (!Graph[i][j] && !Visited[i][j]) {
				Visited[i][j] = true;
				int cnt = 1;
				dfs(i, j, cnt);
				bool isCircle = false;
				if (cnt >= 4) {
					for (int k = 0; k < 8; k++) {
						if (i + dx[k] == last_x && j + dy[k] == last_y) {
							isCircle = true;
							break;
						}
					}
				}
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
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (check(nx, ny, x, y)) {
			Visited[nx][ny] = true;
			last_x = nx; last_y = ny;
			step++;
			dfs(nx, ny, step);
		}
	}

}
bool SlashMaze::check(int nx, int ny, int x, int y) {
	if (nx < 0 || nx >= height * 2) return false;
	if (ny < 0 || ny >= width * 2) return false;
	if (Graph[nx][ny]) return false;
	if (Visited[nx][ny]) return false;
	if (nx == x + 1 && ny == y + 1 && Graph[x][ny] == 1 && Graph[nx][y] == 1) return false;
	if (nx == x - 1 && ny == y - 1 && Graph[x][ny] == 1 && Graph[nx][y] == 1) return false;
	if (nx == x + 1 && ny == y - 1 && Graph[x][ny] == 2 && Graph[nx][y] == 2) return false;
	if (nx == x - 1 && ny == y + 1 && Graph[x][ny] == 2 && Graph[nx][y] == 2) return false;
	return true;
}
void SlashMaze::output() {
	if (numOfCycles) {
		cout << numOfCycles << " Cycles; the longest has length " << LongestLength << "." << endl;
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