#include <iostream>
#include <cstring>
#include <stack>
#include <string>
using namespace std;

char a[10][10];
int b[10][10];
string order = "@IEHOVA#";
bool flag = false;
stack<string> route;

void dfs(int x, int y, int d)
{
	b[x][y] = 0;  // visited
	if (a[x][y] == '#' && d == 7) {  // found
		flag = true;
		return;
	}
	if (x-1 > 0 && b[x-1][y] && a[x-1][y] == order[d+1]) {  // forth
		dfs(x-1, y, d+1);
		if (flag)
			route.push("forth");
	}
	if (b[x][y+1] && a[x][y+1] == order[d+1]) {  // right
		dfs(x, y+1, d+1);
		if (flag)
			route.push("right");
	}
	if (y-1 > 0 && b[x][y-1] && a[x][y-1] == order[d+1]) {  // left
		dfs(x, y-1, d+1);
		if (flag)
			route.push("left");
	}
}

int main()
{
	int N;
	cin >> N;
	while (N--) {
		int m, n, start_x, start_y;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		cin >> m >> n;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
				if (a[i][j] == '@') {
					start_x = i;
					start_y = j;
				}
				b[i][j] = 1;
			}
		
		dfs(start_x, start_y, 0);

		while (!route.empty()) {
			cout << route.top();
			if (route.size() != 1)
				cout << ' ';
			else
				cout << endl;
			route.pop();
		}
	}
	return 0;
}