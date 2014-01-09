#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int main() {
	int n, map[110][110], d[110], cnt = 0;
	while (cin >> n && n) {
		cnt++;
		int s, x, y;
		memset(map, 0, sizeof(map));
		memset(d, 0, sizeof(d));

		cin >> s;
		while (cin >> x >> y && x && y) {
			map[x][y] = -1;
		}

		// Bellman-Ford Algorithm
		for (int i = 1; i <= n; i++)
			d[i] = INT_MAX;
		d[s] = 0;

		bool isChanged = true;
		for (int k = 1; k < n && isChanged; k++) {
			isChanged = false;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (map[i][j] && d[i] != INT_MAX && d[i] + map[i][j] < d[j]) {
						isChanged = 1;
						d[j] = d[i] + map[i][j];
					}
				}
			}
		}

		int min = INT_MAX, mini;
		for (int i = 1; i <= n; i++)
			if (d[i] < min) {
				min = d[i];
				mini = i;
			}

		cout << "Case " << cnt << ": The longest path from " << s << " has length " << -min << ", finishing at " << mini << "." << endl << endl;
	}
	return 0;
}
