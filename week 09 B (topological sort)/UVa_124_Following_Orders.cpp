#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define MAXN 26

bool Graph[MAXN][MAXN], Exist[MAXN], Visited[MAXN];
int InDegree[MAXN], N;
char Result[MAXN];

void TopologicalSortAll(int step) {
    if (step == N) {
        Result[step] = '\0';
        cout << Result << endl;
    } else {
        for (int i = 0; i < MAXN; i++) {
            if (Exist[i] && !Visited[i] && !InDegree[i]) {
                for (int j = 0; j < MAXN; j++) {
                    if (Exist[j] && Graph[i][j]) InDegree[j]--;
                }
                Visited[i] = true;
                Result[step] = char('a' + i);

                TopologicalSortAll(step + 1);

                for (int j = 0; j < MAXN; j++) {
                    if (Exist[j] && Graph[i][j]) InDegree[j]++;
                }
                Visited[i] = false;
            }
        }
    }
}

int main() {
    string st;
    int cnt = 0;
    while (getline(cin, st) && st[0]) {
        if (cnt) cout << endl;
        else cnt++;

        memset(Graph, 0, sizeof(Graph));
        memset(Exist, 0, sizeof(Exist));
        memset(InDegree, 0, sizeof(InDegree));
        memset(Visited, 0, sizeof(Visited));
        N = 0;

        for (int i = 0; i < st.length(); i++) {
            if (st[i] != ' ') {
                Exist[st[i]-'a'] = true;
                N++;
            }
        }

        getline(cin, st);
        for (int i = 0; i < st.length()-2; i+=4) {
            int x = st[i] - 'a', y = st[i+2] - 'a';
            if (!Graph[x][y]) {
                Graph[x][y] = true;
                InDegree[y]++;
            }
        }

        TopologicalSortAll(0);
    }
    return 0;
}
