#include <iostream>
#include <cstring>
using namespace std;

int N, cnt;
char a[205][205];
bool b[205][205];
const int dx[6] = {-1, -1,  0, 0, 1, 1};
const int dy[6] = {-1,  0, -1, 1, 0, 1};
char winner;

void dfs(int x, int y, const char player)
{
	if (a[x][y] != player || !b[x][y]) return;
	if (y == N && a[x][y] == 'w') {
		winner = 'W';
		return;
	}
	if (x == N && a[x][y] == 'b') {
		winner = 'B';
		return;
	}
	b[x][y] = false;
	
	for (int i = 0; i < 6; i++)
		dfs(x+dx[i], y+dy[i], player);
}

int main()
{
	while (cin >> N && N) {
		cnt++;
		memset(a, 0, sizeof(a));
		memset(b, false, sizeof(b));
		bool flag = false;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> a[i][j];
				b[i][j] = true;
			}
		}

		for (int i = 1; i <= N; i++)  // black
			if (b[1][i] && a[1][i] == 'b')
				dfs(1, i, 'b');

		for (int i = 1; i <= N; i++)  // white
			if (b[i][1] && a[i][1] == 'w')
				dfs(i, 1, 'w');

		cout << cnt << ' ' << winner << endl;
	}
	return 0;
}
