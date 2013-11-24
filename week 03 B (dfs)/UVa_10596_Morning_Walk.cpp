#include <cstring>
#include <iostream>
using namespace std;

int b[210], a[210][210], N, R;

void dfs(int v)
{
	b[v] = true;
	for (int i = 0; i < N; i++)
		if (!b[i] && a[v][i])
			dfs(i);
}  

int main()
{
	while (cin >> N >> R) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		int r1, r2;
		for (int i = 0; i < R; i++) {
			cin >> r1 >> r2;
			a[r1][r2] = a[r2][r1] = 1;
			b[r1]++; 
			b[r1]++;
		}

		int cnt = 0;
		for (int i = 0; i < N; i++)
			if (b[i] % 2 == 1) {
				cnt++;
				break;
			}

			memset(b, 0, sizeof(b));

			if (cnt || R<2) cout << "Not Possible" << endl;
			else {
				dfs(0);
				bool flag = true;
				for (int i = 0; i < N; i++)
					if (!b[i]) flag = false;

				if (flag) cout << "Possible" << endl;
				else cout << "Not Possible" << endl;
			}
	}
	return 0;
}