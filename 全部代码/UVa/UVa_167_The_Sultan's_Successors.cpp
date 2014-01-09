#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int v[10][10], score = 0;

struct queen {
	int x, y;
} q[10], a[10];

bool valid(int x, int y)
{
	for (int i = 0; i < x; i++) {
		if (q[i].x == x || q[i].y == y) return false;
        if (abs(q[i].x - x) == abs(q[i].y - y)) return false;
	}
	return true;
}

void dfs(int x, int sum)
{
	if (x == 8) {
		if (sum > score) {score = sum;
		for (int i = 0; i < 8; i++)
			a[i] = q[i];}
	} else {
		for (int i = 0; i < 8; i++)
			if (valid(x, i)) {
				q[x].x = x;  q[x].y = i;
				dfs(x + 1, sum + v[x][i]);
			}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		score = 0;
		for (int j = 0; j < 8; j++)
			for (int k = 0; k < 8; k++)
				cin >> v[j][k];

		dfs(0, 0);
		cout << setw(5) << score << endl;
	}
	return 0;
}
