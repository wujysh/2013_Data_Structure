#include <iostream>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
#define MAXN 210
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

map <string, int> city;
int graph[MAXN][MAXN];

int main() {
	int n, r, cnt = 0;
	while (cin >> n >> r && n && r) {
		cnt++;
		memset(graph, 0, sizeof(graph));
		city.clear();

		for (int i = 0; i < r; i++) {
			string city1, city2;
			int limit;
			cin >> city1 >> city2 >> limit;
			if (city.find(city1) == city.end()) city.insert(make_pair(city1, city.size()));
			if (city.find(city2) == city.end()) city.insert(make_pair(city2, city.size()));
			graph[city[city1]][city[city2]] = graph[city[city2]][city[city1]] = limit;
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					graph[i][j] = max(graph[i][j], min(graph[i][k], graph[k][j]));
				}
			}
		}

		string start, destination;
		cin >> start >> destination;

		cout << "Scenario #" << cnt << endl;
		cout << graph[city[start]][city[destination]] << " tons" << endl << endl;
	}
	return 0;
}