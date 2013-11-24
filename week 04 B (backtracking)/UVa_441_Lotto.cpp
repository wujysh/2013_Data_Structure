#include <iostream>
#include <cstring>
#define MAXN 15
using namespace std;

int a[MAXN], n, ans[MAXN];
bool visited[MAXN];

void dfs(int step)
{
	if (step >= 6) {
		for (int i = 0; i < 6; i++) {
			if (i != 0) cout << " ";
			cout << a[ans[i]];
		}
		cout << endl;
	} else {
		for (int i = 0; i < n; i++) {
			if (visited[i] || a[i] < a[ans[step-1]]) continue;
			ans[step] = i;
			visited[i] = true;

			dfs(step+1);

			visited[i] = false;
		}
	}
}

int main()
{
	int cnt = 0;
	while (cin >> n && n) {
		cnt++;
		if (cnt != 1) cout << endl;

		memset(visited, false, sizeof(visited));
		memset(ans, 0, sizeof(ans));
		memset(a, 0, sizeof(a));

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		dfs(0);
	}

	return 0;
}