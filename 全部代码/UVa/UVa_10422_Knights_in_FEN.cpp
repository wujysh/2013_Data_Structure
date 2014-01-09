#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

const int dx[8] = { -2, -2, -1, 1, 2, 2, 1, -1 };
const int dy[8] = { -1, 1, 2, 2, 1, -1, -2, -2 };
int aim[5][5] = { { 1, 1, 1, 1, 1 }, { 0, 1, 1, 1, 1 }, { 0, 0, 2, 1, 1 }, { 0, 0, 0, 0, 1 }, { 0, 0, 0, 0, 0 } };
int board[5][5];
int ans;

void dfs(int x, int y, int step) {
	if (step >= ans) return;
	if (memcmp(board, aim, sizeof(board)) == 0) {
		if (step < ans) ans = step;
		return;
	}
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
			int tmp = board[x][y];
			board[x][y] = board[nx][ny];
			board[nx][ny] = tmp;

			dfs(nx, ny, step + 1);

			tmp = board[nx][ny];
			board[nx][ny] = board[x][y];
			board[x][y] = tmp;
		}
	}
}

int main() {
	int nCase;
	scanf("%d", &nCase);
	getchar();
	while (nCase--) {
		int empty_x, empty_y;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				char ch = getchar();
				if (ch == '0') board[i][j] = 0;
				if (ch == '1') board[i][j] = 1;
				if (ch == ' ') {
					board[i][j] = 2;
					empty_x = i;
					empty_y = j;
				}
			}
			getchar();
		}
		ans = 11;
		dfs(empty_x, empty_y, 0);
		if (ans > 10)
			printf("Unsolvable in less than 11 move(s).\n");
		else
			printf("Solvable in %d move(s).\n", ans);
	}
	return 0;
}
