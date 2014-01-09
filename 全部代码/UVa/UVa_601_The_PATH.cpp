#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 81;
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

class ThePath {
private:
	int size, minU;
	int graph[MAXN][MAXN];  // 1-white; 2-black; 3-white from left; 4-white from right; 5-black from top; 6-black from bottom
public:
	void init(int);
	void input();
	bool check(int, int);
	void dfs_white_left(int, int);
	void dfs_white_right(int, int);
	void dfs_black_top(int, int);
	void dfs_black_bottom(int, int);
	void process();
};
void ThePath::init(int n) {
	size = n;
	memset(graph, 0, sizeof(graph));
}
void ThePath::input() {
	char ch;
	getchar();
	for (int i = 0; i < size; i++) {
		getchar();
		for (int j = 0; j < size; j++) {
			ch = getchar();
			if (ch == 'W') {
				graph[i][j] = 1;
			} else if (ch == 'B') {
				graph[i][j] = 2;
			}
		}
	}
}
bool ThePath::check(int x, int y) {
	if (x < 0 || x >= size) return false;
	if (y < 0 || y >= size) return false;
	return true;
}
void ThePath::dfs_white_left(int x, int y) {
	graph[x][y] = 3;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (check(nx, ny) && graph[nx][ny] == 1) {
			dfs_white_left(nx, ny);
		}
	}
}
void ThePath::dfs_white_right(int x, int y) {
	graph[x][y] = 4;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (check(nx, ny) && graph[nx][ny] == 1) {
			dfs_white_right(nx, ny);
		}
	}
}
void ThePath::dfs_black_top(int x, int y) {
	graph[x][y] = 5;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (check(nx, ny) && graph[nx][ny] == 2) {
			dfs_black_top(nx, ny);
		}
	}
}
void ThePath::dfs_black_bottom(int x, int y) {
	graph[x][y] = 6;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (check(nx, ny) && graph[nx][ny] == 2) {
			dfs_black_bottom(nx, ny);
		}
	}
}
void ThePath::process() {
	// white from left to right
	for (int i = 0; i < size; i++) {
		if (graph[i][0] == 1) {
			dfs_white_left(i, 0);
		}
	}
	for (int i = 0; i < size; i++) {
		if (graph[i][size - 1] == 3) {
			cout << "White has a winning path." << endl;
			return;
		}
	}
	// white from right to left
	for (int i = 0; i < size; i++) {
		if (graph[i][size - 1] == 1) {
			dfs_white_right(i, size - 1);
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (graph[i][j] == 0 && ((graph[i][j - 1] == 3 && graph[i][j + 1] == 4) || (j == 0 && graph[i][j + 1] == 4) || (j == size - 1 && graph[i][j - 1] == 3))) {
				cout << "White can win in one move." << endl;
				return;
			}
		}
	}

	// black from top to bottom
	for (int j = 0; j < size; j++) {
		if (graph[0][j] == 2) {
			dfs_black_top(0, j);
		}
	}
	for (int j = 0; j < size; j++) {
		if (graph[size - 1][j] == 5) {
			cout << "Black has a winning path." << endl;
			return;
		}
	}
	// black from bottom to top
	for (int j = 0; j < size; j++) {
		if (graph[size - 1][j] == 2) {
			dfs_black_bottom(size - 1, j);
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (graph[i][j] == 0 && ((graph[i - 1][j] == 5 && graph[i + 1][j] == 6) || (i == 0 && graph[i + 1][j] == 6) || (i == size - 1 && graph[i - 1][j] == 5))) {
				cout << "Black can win in one move." << endl;
				return;
			}
		}
	}

	// no win
	cout << "There is no winning path." << endl;
}

int main() {
	ThePath tp;
	int n;
	while (cin >> n && n) {
		tp.init(n);
		tp.input();
		tp.process();
	}
	return 0;
}