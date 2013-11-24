#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 405;

class AntennaPlacement {
private:
    int numOfPoints, numOfAntennas, height, weight;
    int graph[MAXN][MAXN], number[MAXN][MAXN];
private:
    bool visited[MAXN];
    int pairs[MAXN];
    bool findpath(int);
public:
    void hungray();
    void init();
    void input();
    void output();
};
void AntennaPlacement::init() {
    memset(graph, 0, sizeof(graph));
    memset(number, 0, sizeof(number));
    memset(pairs, 0, sizeof(pairs));
    numOfPoints = 0;
    numOfAntennas = 0;
}
void AntennaPlacement::input() {
    scanf("%d%d", &height, &weight);

    int cnt = 0;
    for (int i = 0; i < height; i++) {
        for(int j = 0; j < weight; j++) {
            char s;
            cin >> s;
            if (s == '*') {
                cnt++;
                number[i][j] = cnt;
            }
        }
    }
    numOfPoints = cnt;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < weight; j++) {
            if (number[i][j] != 0) {
                if (i > 0 && number[i - 1][j] != 0)
                    graph[number[i][j]][number[i - 1][j]] = 1;
                if (i < height - 1 && number[i + 1][j] != 0)
                    graph[number[i][j]][number[i + 1][j]] = 1;
                if (j > 0 && number[i][j - 1] != 0)
                    graph[number[i][j]][number[i][j - 1]] = 1;
                if (j < weight - 1 && number[i][j + 1] != 0)
                    graph[number[i][j]][number[i][j + 1]] = 1;
            }
        }
    }
}
bool AntennaPlacement::findpath(int x) {
    for (int y = 1; y <= numOfPoints; y++) {
        if (graph[x][y] && !visited[y]) {
            visited[y] = true;
            if (pairs[y] == 0 || findpath(pairs[y])) {
                pairs[y] = x;
                return true;
            }
        }
    }
    return false;
}
void AntennaPlacement::hungray() {
    int match = 0;
    for (int i = 1; i <= numOfPoints; i++) {
        memset(visited, false, sizeof(visited));
        if (findpath(i)) {
            match++;
        }
    }
    numOfAntennas = numOfPoints - match / 2;
}
void AntennaPlacement::output() {
    printf("%d\n", numOfAntennas);
}

int main() {
    int nCase;
    AntennaPlacement ap;
    scanf("%d", &nCase);
    while (nCase--) {
        ap.init();
        ap.input();
        ap.hungray();
        ap.output();
    }
    return 0;
}
