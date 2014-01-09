#include <iostream>
#include <map>
#include <queue>
#include <cstring>
using namespace std;

map <int, int> node;
int connection[35][35];
bool visited[35];
queue <int> q;
int nc, ttl, casecnt;

void dfs(int x, int step)
{
	if (step > ttl) return;
	else {
		visited[x] = true;
		/*cout << x << endl;*/
		for (int i = 1; i <= node.size(); i++)
			if (!visited[i] && connection[x][i] == 1) {
				dfs(i, step+1);
			}
	}
}

int main()
{
	while (cin >> nc && nc) {
		memset(connection, 0, sizeof(connection));
		node.clear();

		for (int i = 0; i < nc; i++) {
			int a, b;
			cin >> a >> b;
			if (node.find(a) == node.end()) node[a] = node.size();
			if (node.find(b) == node.end()) node[b] = node.size();
			connection[node[a]][node[b]] = 1;
			connection[node[b]][node[a]] = 1;
		}

		/*map <int, int>::iterator it;
		for (it = node.begin(); it != node.end(); ++it)
			cout << it->first << " -> " << it->second << endl;*/

		int initial;
		while (cin >> initial >> ttl && initial && ttl) {
			casecnt++;
			memset(visited, false, sizeof(visited));
			q.push(node[initial]);

			dfs(node[initial], 0);

			int cnt = 0;
			for (int i = 1; i <= node.size(); i++)
				if (!visited[i])
					cnt++;
			cout << "Case " << casecnt << ": " << cnt << " nodes not reachable from node " << initial << " with TTL = " << ttl << "." << endl;
		}
	}
	return 0;
}
