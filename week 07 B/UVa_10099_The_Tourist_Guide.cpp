#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
	int n, r, cnt = 0;
	while (cin >> n >> r && (n || r)) {
		cnt++;
		int map[110][110];
		memset(map, -1, sizeof(map));

		for (int i = 0; i < r; i++) {
			int c1, c2, p;
			cin >> c1 >> c2 >> p;
			map[c1][c2] = map[c2][c1] = p;
		}

		for (int i = 1; i <= n; i++) {
			map[i][i] = 0;
		}

		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					map[i][j] = max(map[i][j], min(map[i][k], map[k][j]));

		int a, b, c;
		cin >> a >> b >> c;

		cout << "Scenario #" << cnt << endl;
		cout << "Minimum Number of Trips = " << (int)ceil((float)c/(map[a][b]-1)) << endl << endl;
	}
	return 0;
}