#include <iostream>
#include <cmath>
#include <cstring>
#define MAXN 20
using namespace std;

int n, ans[MAXN];
bool visited[MAXN];

bool isPrime(int x)
{
	for (int i = 2; i <= sqrt((double)x); i++)
		if (x % i == 0) return false;
	return true;
}

void dfs(int step)
{
	if (step >= n) {
		for (int i = 0; i < n; i++) {
			if (i != 0) cout << " ";
			cout << ans[i];
		}
		cout << endl;
	} else {
		for (int i = 2; i <= n; i++) {
			if (visited[i] || !isPrime(i + ans[step-1])) continue;
			if (step == n-1 && !isPrime(1 + i)) continue;
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
		memset(visited, false, sizeof(visited));
		memset(ans, 0, sizeof(ans));

		cnt++;
		if (cnt != 1) cout << endl;
		cout << "Case " << cnt << ":" << endl;

		ans[0] = 1;
		dfs(1);
	}

	return 0;
}
