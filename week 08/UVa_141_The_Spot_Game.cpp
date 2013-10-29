#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
#define MAXN 55

int n;

struct Board {
	bool v[MAXN][MAXN];
	Board() { memset(v, false, sizeof(v)); }
	friend bool operator < (const Board &a, const Board &b) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a.v[i][j] < b.v[i][j]) return true;
				if (a.v[i][j] > b.v[i][j]) return false;
			}
		}
		return false;
	}
};

set <Board> patterns;

Board rotate(Board board) {
	Board tmp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			tmp.v[j][n - i + 1] = board.v[i][j];
		}
	}
	return tmp;
}

int main() {
	while (cin >> n && n) {
		Board curBoard;
		bool flag = false;
		int x[2 * MAXN], y[2 * MAXN];
		char op[2 * MAXN];
		patterns.clear();

		for (int i = 0; i < 2 * n; i++)
			scanf("%d %d %c", &x[i], &y[i], &op[i]);

		for (int i = 0; i < 2 * n; i++) {
			if (op[i] == '+')
				curBoard.v[x[i]][y[i]] = true;
			else
				curBoard.v[x[i]][y[i]] = false;

			Board tmpBoard = curBoard, board[4];
			for (int j = 0; j < 4; j++) {
				if (patterns.find(tmpBoard) != patterns.end()) {  // pattern repeated
					if (i % 2 == 1) {
						cout << "Player 1 wins on move " << i + 1 << endl;
					} else {
						cout << "Player 2 wins on move " << i + 1 << endl;
					}
					flag = true;
					break;
				} else {
					board[j] = tmpBoard = rotate(tmpBoard);
				}
			}
			if (flag) break;

			for (int j = 0; j < 4; j++)
				patterns.insert(board[j]);
		}
		if (!flag) cout << "Draw" << endl;
	}
	return 0;
}