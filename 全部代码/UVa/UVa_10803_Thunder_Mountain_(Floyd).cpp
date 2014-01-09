#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;
#define min(a,b) (a) < (b) ? (a) : (b)

const int MAXN = 110;
const int INF = 1 << 10;
const double eps = 1e-4;

struct Town {
	int x, y;
};

class ThunderMountain {
private:
	int numOfTowns, cnt = 0;
	double graph[MAXN][MAXN], ans;
	Town town[MAXN];
public:
	void init();
	void input();
	void process();
	void output();
	inline double distance(int, int);
	inline void floyd();
};
void ThunderMountain::init() {
	memset(graph, INF, sizeof(graph));
	ans = 0;
}
void ThunderMountain::input() {
	cin >> numOfTowns;
	for (int i = 0; i < numOfTowns; i++) {
		cin >> town[i].x >> town[i].y;
	}
}
inline double ThunderMountain::distance(int a, int b) {
	Town t1 = town[a], t2 = town[b];
	double dis = sqrt((t1.x - t2.x) * (t1.x - t2.x) + (t1.y - t2.y) * (t1.y - t2.y));
	return dis - 10.0 > eps ? INF : dis;
}
void ThunderMountain::process() {
	for (int i = 0; i < numOfTowns; i++) {
		for (int j = i + 1; j < numOfTowns; j++) {
			graph[i][j] = graph[j][i] = distance(i, j);
		}
	}
	floyd();
	for (int i = 0; i < numOfTowns; i++) {
		for (int j = 0; j < numOfTowns; j++) {
			if (i != j && graph[i][j] > ans)
				ans = graph[i][j];
		}
	}
}
inline void ThunderMountain::floyd() {
	for (int k = 0; k < numOfTowns; k++) {
		for (int i = 0; i < numOfTowns; i++) {
			for (int j = 0; j < numOfTowns; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
}
void ThunderMountain::output() {
	cnt++;
	cout << "Case #" << cnt << ":" << endl;
	if (fabs(ans - INF) < eps)
		cout << "Send Kurdy" << endl;
	else
		cout << fixed << setprecision(4) << ans << endl;
	cout << endl;
}

int main() {
	ThunderMountain tm;
	int nCase;
	cin >> nCase;
	while (nCase--) {
		tm.init();
		tm.input();
		tm.process();
		tm.output();
	}
	return 0;
}