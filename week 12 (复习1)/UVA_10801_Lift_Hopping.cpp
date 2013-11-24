#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;

class LiftHopping {
private:
	int numOfElevators, endFloor;
	int time[5];
	int graph[N][N];
	int dis[N];
	bool visited[N];
public:
	void initial(int, int);
	void input();
	void work();
	void output();
};
void LiftHopping::initial(int n, int k) {
	numOfElevators = n;
	endFloor = k;
	memset(time, 0, sizeof(time));
	memset(visited, false, sizeof(visited));
	memset(graph, 0x3f, sizeof(graph));
	memset(dis, 0x3f, sizeof(dis));
	dis[0] = 0;
}
void LiftHopping::input() {
	for (int i = 0; i < numOfElevators; i++) {
		scanf("%d", &time[i]);
	}
	for (int i = 0; i < numOfElevators; i++) {
		char ch = '\0';
		int stop[N];
		for (int j = 0; ch != '\n'; j++) {
			scanf("%d%c", &stop[j], &ch);
			for (int k = 0; k < j; k++) {
				int a = stop[j], b = stop[k];
				int d = abs(b - a) * time[i];
				if (graph[a][b] > d)
					graph[a][b] = graph[b][a] = d;
			}
		}
	}
}
void LiftHopping::work() {
	for (int i = 0; i < 99; i++) {
		int x, max = INF;
		bool finished = true;
		for (int j = 0; j < 100; j++) {
			if (!visited[j] && dis[j] < max) {
				max = dis[j];
				x = j;
				finished = false;
			}
		}
		if (finished) return;
		visited[x] = true;
		for (int j = 0; j < 100; j++) {
			if (!visited[j] && dis[j] > dis[x] + graph[x][j] + 60)
				dis[j] = dis[x] + graph[x][j] + 60;
		}
	}
}
void LiftHopping::output() {
	if (endFloor == 0)
		printf("0\n");
	else if (dis[endFloor] != INF)
		printf("%d\n", dis[endFloor] - 60);
	else printf("IMPOSSIBLE\n");
}

int main() {
	LiftHopping lh;
	int n, k;
	while (scanf("%d%d", &n, &k) == 2) {
		lh.initial(n, k);
		lh.input();
		lh.work();
		lh.output();
	}
	return 0;
}
