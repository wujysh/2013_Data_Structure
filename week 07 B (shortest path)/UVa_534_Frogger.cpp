#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;

struct stone {
    int x, y;
};

int main () {
    int n, cnt = 0;
    while (cin >> n && n) {
        cnt++;
        int x, y;
        float a[210][210];
        stone s[210];
        memset(a, 1, sizeof(a));
        for (int i = 0; i < n; i++)
            a[i][i] = 0;

        for (int i = 0; i < n; i++) {
            cin >> s[i].x >> s[i].y;
            for (int j = 0; j < i; j++)
                a[i][j] = a[j][i] = sqrt((s[i].x-s[j].x)*(s[i].x-s[j].x) + (s[i].y-s[j].y)*(s[i].y-s[j].y));
        }

        // Altered Floyd Algorithm
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    a[i][j] = min(a[i][j], max(a[i][k], a[k][j]));

        cout << "Scenario #" << cnt << endl;
        cout << "Frog Distance = ";
        cout << fixed << setprecision(3) << a[0][1] << endl << endl;
    }
    return 0;
}
