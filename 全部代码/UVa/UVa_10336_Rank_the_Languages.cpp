#include <iostream>
#include <cstring>
#include <map>
using namespace std;

char a[101][101];
int b[101][101];

void dfs(int i, int j)
{
	b[i][j] = 0;
	if (b[i+1][j] && a[i+1][j] == a[i][j]) dfs(i+1, j);
	if (b[i][j+1] && a[i][j+1] == a[i][j]) dfs(i, j+1);
	if (b[i-1][j] && a[i-1][j] == a[i][j]) dfs(i-1, j);
	if (b[i][j-1] && a[i][j-1] == a[i][j]) dfs(i, j-1);
}

int main()
{
	int n, count=0;
	cin >> n;
	while (n--) {
		count++;
		memset(b, 0, sizeof(b));
		int h, w;
		cin >> h >> w;
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++) {
				cin >> a[i][j];
				b[i][j] = 1;
			}

			map<char, int> world;
			map<char, int>::iterator iter;
			int max = 0;

			for (int i = 1; i <= h; i++)
				for (int j = 1; j <= w; j++)
					if (b[i][j]) {
						world[a[i][j]]++;
						if (world[a[i][j]] > max) max = world[a[i][j]];
						dfs(i, j);
					}

			cout << "World #" << count << endl;
			for (int i = max; i > 0; i--)
				for (iter = world.begin(); iter != world.end(); ++iter) {
					if (iter->second == i)
						cout << iter->first << ": " << iter->second << endl;
				}
	}

	//system("pause");
	return 0;   
}
