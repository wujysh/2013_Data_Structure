#include <iostream>
#include <sstream>
#include <string>
#include <queue>
//#include <vector>
using namespace std;
#define MAXN 1010

int n, m;
struct Node {
    int x, y;
} node;
struct Sheet {
    int value, InDegree;
    queue <Node> depend;
} sheet[MAXN][MAXN];
//vector < vector <Sheet> > sheet;

void TopologicalSort() {
    queue <Node> Zero;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!sheet[i][j].InDegree) {
                node.x = i;  node.y = j;
                Zero.push(node);
            }
        }
    }
    while (!Zero.empty()) {
        Node cur = Zero.front();
        Zero.pop();
        while (!sheet[cur.x][cur.y].depend.empty()) {
            Node suc = sheet[cur.x][cur.y].depend.front();
            sheet[cur.x][cur.y].depend.pop();
            sheet[suc.x][suc.y].value += sheet[cur.x][cur.y].value;
            if (!(--sheet[suc.x][suc.y].InDegree)) {
                Zero.push(suc);
            }
        }
    }
}

int main() {
    int nCase;
    cin >> nCase;
    while (nCase--) {
        cin >> m >> n;
        //sheet.clear();
        //sheet.resize(n + 2);
        for (int i = 1; i <= n; i++) {
            //sheet[i].clear();
            //sheet[i].resize(m + 2);
            for (int j = 1 ; j <= m; j++) {
                string str;
                cin >> str;
                if (str[0] == '=') {
                    int r = 0, c = 0;
                    node.x = i;  node.y = j;
                    str.push_back('+');
                    for (unsigned k = 1; k < str.length(); k++) {
                        if (str[k] >= 'A' && str[k] <= 'Z') {
                            c = c * 26 + str[k] - 'A' + 1;
                        } else if (str[k] >= '0' && str[k] <= '9') {
                            r = r * 10 + str[k] - '0';
                        } else {  // '+'
                            sheet[r][c].depend.push(node);
                            sheet[i][j].InDegree++;
                            sheet[i][j].value = 0;
                            r = c = 0;
                        }
                    }
                } else {
                    sheet[i][j].InDegree = 0;
                    stringstream scin(str);
                    scin >> sheet[i][j].value;
                }
            }
        }

        TopologicalSort();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (j > 1) cout << ' ';
                cout << sheet[i][j].value;
            }
            cout << endl;
        }
    }
    return 0;
}
