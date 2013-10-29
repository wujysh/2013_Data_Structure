#include <iostream>
#include <cstring>
#define MAXN 55
using namespace std;

const int dx[4] = {-1, 0, 1,  0};
const int dy[4] = { 0, 1, 0, -1};

int main() {
    int nCase;
    cin >> nCase;
    while (nCase--) {
        int n, r;
        bool map[MAXN][MAXN];
        memset(map, false, sizeof(map));

        cin >> n >> r;
        for (int i = 0; i < r; i++) {
            int x, y;
            cin >> x >> y;
            map[x][y] = true;  // mark the right-turners
        }

        int x, y, orientation = 0;
        cin >> x >> y;  // read the position of laser

        // go into the map
        if (x > n) { x--; orientation = 0; }
        if (y < 1) { y++; orientation = 1; }
        if (x < 1) { x++; orientation = 2; }
        if (y > n) { y--; orientation = 3; }

        // traverse in the map, and turn right when meeting right-turner
        while (x > 0 && x < n+1 && y > 0 && y < n+1) {
            //cout << "(" << x << "," << y << ")" << orientation << endl; // debug
            if (map[x][y]) {
                orientation++;
                orientation %= 4;
            }
            x += dx[orientation];
            y += dy[orientation];
        }

        cout << x << ' ' << y << endl;
    }
    return 0;
}
