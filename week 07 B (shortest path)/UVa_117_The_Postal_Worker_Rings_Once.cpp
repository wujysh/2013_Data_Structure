#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    string st;
    int n = 0, sum = 0, a[30][30], b[30];
    memset(a, 1, sizeof(a));
    memset(b, 0, sizeof(b));
    while (cin >> st && st != "") {
        if (st != "deadend") {
            n++;
            int len = st.length();
            int x = st[0] - 'a';
            int y = st[len-1] - 'a';
            a[x][y] = a[y][x] = len;
            b[x]++;
            b[y]++;
            sum += len;
        } else {
            bool euler = true;
            int odd1, odd2;
            for (int i = 0; i < 26; i++)
                if (b[i] % 2 != 0) {
                    odd1 = i;
                    euler = false;
                    break;
                }
            if (euler) {
                cout << sum << endl;
            } else {
                // find out the other odd node
                for (int i = odd1+1; i < 26; i++)
                    if (b[i] % 2 != 0) {
                        odd2 = i;
                        break;
                    }
                // Floyd_Warshell Algorithm
                for (int i = 0; i < 26; i++) {
                    a[i][i] = 0;
                }

                for (int k = 0; k < 26; k++)
                    for (int i = 0; i < 26; i++)
                        for (int j = 0; j < 26; j++)
                            a[i][j] = min(a[i][j], a[i][k]+a[k][j]);

                cout << sum + a[odd1][odd2] << endl;
            }
            memset(a, 1, sizeof(a));
            memset(b, 0, sizeof(b));
            n = 0;
            sum = 0;
        }
    }
    return 0;
}
