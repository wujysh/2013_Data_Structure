#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int dx[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
const int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

class SeasonalWar {
private:
    vector<string> land;
    int numberOfWarEagle, cnt;
    void dfs(int x, int y);
public:
	SeasonalWar() {cnt = 0;}
    void initial() {land.clear(); numberOfWarEagle = 0; cnt++;}
    void readCase(int n);
    void computing();
    void outResult() {
		cout << "Image number " << cnt << " contains " << numberOfWarEagle << " war eagles." << endl;
	}
};
void SeasonalWar::readCase(int n) {
    land.resize(n + 2);
    for (int i = 0; i < n + 2; i++) {
        land[0].push_back('0');   //add the top boundary
        land[n+1].push_back('0'); //add the bottom boundary
    }
    for (int i = 1; i <= n; i++) {
        cin >> land[i];
        land[i] = '0' + land[i] + '0'; //add the left and right boundaries
    }
}
void SeasonalWar::computing() {
    for (int r = 1; r < land.size() - 1; r++) {
        for (int c = 1; c < land[r].size() - 1; c++) {
            if (land[r][c] == '1'){
                numberOfWarEagle++;
                dfs(r, c);
            }
        }
    }
}
void SeasonalWar::dfs(int x, int y) {
    if (land[x][y] == '1') {
        land[x][y] = '0';
        for (int i = 0; i < 8; i++) {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

int main(){
    SeasonalWar sw;
    int n;
    while ((cin >> n) && n) {
        sw.initial();
        sw.readCase(n);
        sw.computing();
        sw.outResult();
    }
    return 0;
}