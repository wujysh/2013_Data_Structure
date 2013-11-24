#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;

int a[110][110];
bool b[110][110];
int n, m, cnt;
const int dx[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
const int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

void dfs(int x, int y)
{
    if (!b[x][y] || !a[x][y]) return;
    b[x][y] = false;
    cnt++;
	for (int i = 0; i < 8; i++)
		dfs(x+dx[i], y+dy[i]);
}

int main()
{
    int T;
    cin >> T;
	getchar();
	char str[150];
    gets(str);
    while (T--) {
        n = 1;
        while (gets(str)) {
            if (isdigit(str[0])) break;
            m = strlen(str);
            for (int i = 1; i <= m; i++) {
                if (str[i-1] == 'L')  a[n][i] = 0;
                else if (str[i-1] == 'W')  a[n][i] = 1;
            }
            n++;
        }
		
        int x, y;
		do {
			sscanf(str, "%d %d", &x, &y);
            cnt = 0;
            memset(b, true, sizeof(b));

            dfs(x, y);

            cout << cnt << endl;
        } while (gets(str) && str[0]);

		if (T > 0) cout << endl;
    }
    return 0;
}