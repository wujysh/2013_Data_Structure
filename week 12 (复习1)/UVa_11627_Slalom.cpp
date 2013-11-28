#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

struct Gate {
	double l, r, h;
};

class Slalom {
private:
	static Gate gate[MAXN], tmp[MAXN];
	static int ski[MAXN];
	int W, Vh, N, S;
public:
	bool check(int);
	int binary_search();
	void input();
	void init();
	void solve();
};
Gate Slalom::gate[MAXN], Slalom::tmp[MAXN];
int Slalom::ski[MAXN];
bool Slalom::check(int speed) {
	for (int i = 0; i < N - 1; i++) {
		double t = (gate[i + 1].h - gate[i].h) / speed;
		double l = gate[i].l - t * Vh;
		double r = gate[i].r + t * Vh;
		if (gate[i + 1].r < l || gate[i + 1].l > r) return false;
		gate[i + 1].l = max(gate[i + 1].l, l);
		gate[i + 1].r = min(gate[i + 1].r, r);
	}
	return true;
}
int Slalom::binary_search() {
	int l = ski[0], r = ski[S - 1];
	memcpy(tmp, gate, sizeof(tmp));
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) l = mid + 1;
		else r = mid - 1;
		memcpy(gate, tmp, sizeof(gate));
	}
	return r < ski[0] ? 0 : r;
}
void Slalom::init() {
	memset(gate, 0, sizeof(gate));
	memset(ski, 0, sizeof(ski));
}
void Slalom::input() {
	scanf("%d%d%d", &W, &Vh, &N);
	for (int i = 0; i < N; i++) {
		scanf("%lf%lf", &gate[i].l, &gate[i].h);
		gate[i].r = gate[i].l + W;
	}
	scanf("%d", &S);
	for (int i = 0; i < S; i++) scanf("%d", &ski[i]);
}
void Slalom::solve() {
	sort(ski, ski + S);
	int tmp = binary_search();
	if (tmp) {
		int ans = 0;
		for (int i = 0; i < S; i++)
		if (ski[i] <= tmp) ans = max(ans, ski[i]);
		printf("%d\n", ans);
	} else puts("IMPOSSIBLE");
}

int main() {
	int nCase;
	Slalom S;
	scanf("%d", &nCase);
	while (nCase--) {
		S.init();
		S.input();
		S.solve();
	}
	return 0;
}
