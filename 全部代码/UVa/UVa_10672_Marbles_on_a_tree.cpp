#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 10010;
struct Node {
    int require, have;
} tree[MAXN];
int moves;
vector <int> graph[MAXN];
bool visited[MAXN];

int solve(int rt) {
    int sum;
    visited[rt] = true;
    sum = tree[rt].have - tree[rt].require;
    for (unsigned i = 0; i < graph[rt].size(); i++) {
        if (!visited[graph[rt][i]]) {
            int subsum = solve(graph[rt][i]);
            sum += subsum;
            moves += abs(subsum);
        }
    }
    return sum;
}

int main() {
    int n;
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++)
            graph[i].clear();
        for (int i = 0; i < n; i++) {
            int rt, have, sub;
            cin >> rt >> have >> sub;
            tree[rt].require = 1;
            tree[rt].have = have;
            for (int j = 0; j < sub; j++) {
                int subrt;
                cin >> subrt;
                graph[rt].push_back(subrt);
                graph[subrt].push_back(rt);
            }
        }
        memset(visited, false, sizeof(visited));
        moves = 0;
        solve(1);
        cout << moves << endl;
    }
    return 0;
}
