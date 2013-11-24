#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 12;
const int dx[8] = {-2, -2, -1, 1, 2,  2,  1, -1};
const int dy[8] = {-1,  1,  2, 2, 1, -1, -2, -2};

int visited[MAXN][MAXN];

int bfs(int a1,int a2, int b1, int b2) {
    queue< pair<int, int> > s;
    pair<int, int> start(a1, a2);
    s.push(start);

    visited[a1][a2] = 1;
    while (!s.empty()) {
        pair<int, int> top = s.front();
        s.pop();

        if (top.first == b1 && top.second == b2)
            return visited[b1][b2];  // found

        for (int i = 0; i < 8; i++) {
            int newX = top.first + dx[i];
			int newY = top.second + dy[i];
            if (visited[newX][newY] == 0 && newX < 9 && newX > 0 && newY < 9 && newY > 0) {  // haven't visited and on the chessboard
                visited[newX][newY] = visited[top.first][top.second] + 1;
                pair<int, int> node(newX, newY);
                s.push(node);
            }
        }
     }
}

int main()
{
	string a, b;
    int ax, ay, bx, by;
	while (cin >> a >> b) {
		ax = a[0] - 'a' + 1;
		ay = a[1] - '0';
		bx = b[0] - 'a' + 1;
		by = b[1] - '0';

    	memset(visited, 0, sizeof(visited));

		int result = bfs(ax, ay, bx, by) - 1;
        result = (result == -1) ? 0 : result;

        cout << "To get from " << a << " to " << b << " takes " << result << " knight moves." << endl;
    }
}