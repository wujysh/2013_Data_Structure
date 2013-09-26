#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int dx[8] = {-2, -2, -1, 1, 2,  2,  1, -1};
const int dy[8] = {-1,  1,  2, 2, 1, -1, -2, -2};

class KnightMoves
{
private:
	vector<string> chessboard;
	int numberOfMoves, minNumberOfMoves;
	void dfs(int x, int y);
	string a, b;
public:
	void initial() {
		chessboard.clear();
		numberOfMoves = 0; 
		minNumberOfMoves = 100;
	}
	void readCase(string a, string b);
	void computing();
	void outResult() {
		cout << "To get from " << a << " to " << b << " takes " << minNumberOfMoves << " knight moves." << endl;
	}
};
void KnightMoves::readCase(string a, string b)
{
	chessboard.resize(12);
	for (int i = 0; i < 12; i++) {
		chessboard[0].push_back('0');
		chessboard[1].push_back('0');
		chessboard[10].push_back('0');
		chessboard[11].push_back('0');
	}
	for (int i = 2; i < 10; i++)
		for (int j = 2; j < 10; j++)
			chessboard[i][j] = '1';
	cout << b[0]-'a'+2 << b[1]-'0'+2 << endl;
	chessboard[b[0]-'a'+2][b[1]-'0'+2] = '2';
}
void KnightMoves::computing()
{
	int r = a[0]-'a'+2, c = a[1]-'0'+2;
	cout << r << ' ' << c << endl; // debug
	if (chessboard[r][c] == '2') {
		minNumberOfMoves = 0;
		return;
	}
	minNumberOfMoves = 100;
	for (int i = 0; i < 8; i++) {
		if (chessboard[r+dx[i]][c+dy[i]] == '1') {
			numberOfMoves = 1;
			dfs(r+dx[i], c+dy[i]);
			chessboard[r+dx[i]][c+dy[i]] = '1';  // recovery
		}
	}
}
void KnightMoves::dfs(int x, int y)
{
	if (chessboard[x][y] == '1') {
		chessboard[x][y] = '0';
		for (int i = 0; i < 8; i++) {
			numberOfMoves++;
			dfs(x + dx[i], y + dy[i]);
			numberOfMoves--;  // recovery
			chessboard[x+dx[i]][y+dy[i]] = '1';  // recovery
		}
	}
	if (chessboard[x][y] == '2') {
		if (numberOfMoves < minNumberOfMoves)
			minNumberOfMoves = numberOfMoves;
	}
}

int main()
{
    KnightMoves km;
    string a, b;
    while (cin >> a >> b) {
          km.initial();
          km.readCase(a, b);
          km.computing();
          km.outResult();
    }
    return 0;
}