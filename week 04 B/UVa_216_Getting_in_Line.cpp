#include <iostream>
#include <iomanip>
#include <vector>
#include <cfloat>
#include <cmath>
#include <cstring>
#define MAXN 10
using namespace std;

int n, arr[MAXN], ans[MAXN];
double minlength;
bool visited[MAXN];

typedef struct Computer {
	int x, y;
} computers;
vector <computers> a;

double dis(int x, int y)
{
	double d = (a[x].x - a[y].x) * (a[x].x - a[y].x) + (a[x].y - a[y].y) * (a[x].y - a[y].y);
	d = sqrt(d);
	return d;
}

void dfs(int step, double length)
{
	if (step == n) {
		if (length < minlength) {
			minlength = length;
			memcpy(ans, arr, sizeof(arr));
		}
	} else {
		if (length >= minlength) return;

		for (int i = 0; i < n; i++) {
			if (visited[i]) continue;
			visited[i] = true;
			arr[step] = i;
			if (step == 0)
				dfs(step+1, 0);  
			else {
				double t = dis(arr[step], arr[step-1]);
				dfs(step+1, length+t+16);
			}
			visited[i] = false;
		}
	}
}

int main()
{
	int cnt = 0;
	while (cin >> n && n) {
		cnt++;
		a.resize(n+1);
		for (int i = 0; i < n; i++) {
			cin >> a[i].x >> a[i].y;
			visited[i] = false;
		}

		minlength = DBL_MAX;

		dfs(0, 0);

		cout << "**********************************************************" << endl;
		cout << "Network #" << cnt << endl;
		for (int i = 1; i < n; i++) {
			//logs l = resultq[i];
			double t = dis(ans[i], ans[i-1]) + 16.0;
			cout << "Cable requirement to connect (" << a[ans[i-1]].x << "," << a[ans[i-1]].y << ") to (" << a[ans[i]].x << "," << a[ans[i]].y << ") is " << fixed << setprecision(2) << t << " feet." << endl;
		}
		cout << "Number of feet of cable required is " << fixed << setprecision(2) << minlength << "." << endl;
	}
	return 0;
}