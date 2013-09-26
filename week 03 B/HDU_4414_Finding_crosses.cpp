#include <iostream>
#include <cstring>
using namespace std;

char a[51][51];
int b[51][51];

int dfs(int x, int y, int direction, int cnt)
{
	b[x][y] = 0;
	if (direction == 1) {  // up
		if (a[x][y-1] == '#' || a[x][y+1] == '#') {
			b[x][y] = 1;
			return 0;
		} else if (b[x-1][y] && a[x-1][y] == '#')
			return dfs(x-1, y, 1, cnt+1);
	}
	if (direction == 2) {  // right
		if (a[x-1][y] == '#' || a[x+1][y] == '#') {
			b[x][y] = 1;
			return 0;
		} else if (b[x][y+1] && a[x][y+1] == '#')
			return dfs(x, y+1, 2, cnt+1);
	}
	if (direction == 3) {  // down
		if (a[x][y-1] == '#' || a[x][y+1] == '#') {
			b[x][y] = 1;
			return 0;
		} else if (b[x+1][y] && a[x+1][y] == '#')
			return dfs(x+1, y, 3, cnt+1);
	}
	if (direction == 4) {  // left
		if (a[x-1][y] == '#' || a[x+1][y] == '#') {
			b[x][y] = 1;
			return 0;
		} else if (b[x][y-1] && a[x][y-1] == '#')
			return dfs(x, y-1, 4, cnt+1);
	}
	return cnt;
}

int main()
{
	int N;
	while (cin >> N && N) {
		memset(b, 0, sizeof(b));
		int result = 0;

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				cin >> a[i][j];
				b[i][j] = 1;
			}

		for (int i = 2; i <= N-1; i++)
			for (int j = 2; j <= N-1; j++)
				if (b[i][j] && a[i][j] == '#') {
					if (!(a[i-1][j] == '#' && a[i+1][j] == '#' && a[i][j-1] == '#' && a[i][j+1] == '#')) continue;
					
					b[i][j] = 0;

					int cnt_up = dfs(i-1, j, 1, 1);  // up
					if (!cnt_up) continue;

					int cnt_down = dfs(i+1, j, 3, 1);  // down
					if (!cnt_down || cnt_up != cnt_down) continue;

					int cnt_right = dfs(i, j+1, 2, 1);  // right
					if (!cnt_right || cnt_right != cnt_up) continue;

					int cnt_left = dfs(i, j-1, 4, 1);  // left
					if (!cnt_left || cnt_left != cnt_right) continue;

					result++;

					//cout << i << ' ' << j << ' ' << cnt_up << endl;
					//for (int i = 1; i <= N; i++) {
					//	for (int j = 1; j <= N; j++) {
					//		cout << b[i][j];
					//	}
					//	cout << endl;
					//}
				}

		cout << result << endl;
	}
	return 0;
}