#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 30;
int n;
double map[MAXN][MAXN][MAXN], d[MAXN][MAXN][MAXN];

void floyd() {
	// Altered Floyed Algorithm
	for (int p = 2; p <= n; p++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					double t;
					if ((t = map[i][k][p-1] * map[k][j][1]) > map[i][j][p]) {
						map[i][j][p] = t;
						for (int m = 2; m < p; m++) {
							d[i][j][m] = d[i][k][m];
						}
						d[i][j][p] = k;
					}
				}
			}
		}
		// output
		for (int i = 1; i <= n; i++)
			if (map[i][i][p] > 1.01) {
				cout << i;
				for (int j = 2; j <= p; j++)
					cout << " " << d[i][i][j];
				cout << " " << i << endl;
				return;
			}
	}
	cout << "no arbitrage sequence exists" << endl;  
}

int main() {
	while (cin >> n) {
		// init
		memset(map, 0, sizeof(map));
		memset(d, 0, sizeof(d));
		// input
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					map[i][j][1] = 1.0;
				} else {
					cin >> map[i][j][1];
					d[i][j][1] = i;
				}
			}
		}
		// work
		floyd();
	}
	return 0;
}