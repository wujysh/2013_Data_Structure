#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 30;
const int INF = 100000;
int young[maxn][maxn], old[maxn][maxn];
int N;
char tmp[4], me, prof;
map <char, int> city;
vector <char> meeting;

int main() {
	int n, i, j, k, val, num, my_pos, prof_pos, mini, cur;

	while (cin >> n && n) {
		num = 0;
		city.clear();
		meeting.clear();
		for (i = 0; i < maxn; i++) {
			for (j = 0; j < maxn; j++) {
				if (i == j)
					young[i][j] = old[i][j] = 0;
				else
					young[i][j] = old[i][j] = INF;
			}
		}

		for (j = 0; j < n; j++) {
			for (i = 0; i < 4; i++)
				cin >> tmp[i];
			cin >> val;

			if (city.find(tmp[2]) == city.end())
				city.insert(pair<char, int>(tmp[2], num++));
			if (city.find(tmp[3]) == city.end())
				city.insert(pair<char, int>(tmp[3], num++));
			if (tmp[0] == 'Y') {
				if (tmp[1] == 'U')
					young[city[tmp[2]]][city[tmp[3]]] = min(young[city[tmp[2]]][city[tmp[3]]], val);
				else
					young[city[tmp[2]]][city[tmp[3]]] = young[city[tmp[3]]][city[tmp[2]]] = min(young[city[tmp[2]]][city[tmp[3]]], val);
			} else {
				if (tmp[1] == 'U')
					old[city[tmp[2]]][city[tmp[3]]] = min(old[city[tmp[2]]][city[tmp[3]]], val);
				else
					old[city[tmp[2]]][city[tmp[3]]] = old[city[tmp[3]]][city[tmp[2]]] = min(old[city[tmp[2]]][city[tmp[3]]], val);
			}
		}
		cin >> me >> prof;

		if (city.find(me) == city.end() || city.find(prof) == city.end()) {
			if (me == prof)
				cout << 0 << " " << me << endl;
			else
				cout << "You will never meet.\n";
			continue;
		}

		my_pos = city[me];
		prof_pos = city[prof];
		N = city.size();

		for (k = 0; k < N; k++) {
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					young[i][j] = min(young[i][j], young[i][k] + young[k][j]);
					old[i][j] = min(old[i][j], old[i][k] + old[k][j]);
				}
			}
		}

		mini = INF;
		map<char, int> ::iterator it;
		for (it = city.begin(); it != city.end(); it++) {
			cur = it->second;
			if (young[my_pos][cur] + old[prof_pos][cur] <= mini) {
				if (young[my_pos][cur] + old[prof_pos][cur] < mini) {
					mini = young[my_pos][cur] + old[prof_pos][cur];
					meeting.clear();
				}
				meeting.push_back(it->first);
			}
		}

		if (mini == INF)
			cout << "You will never meet.\n";
		else {
			sort(meeting.begin(), meeting.end());
			cout << mini;
			for (i = 0; i < meeting.size(); i++)
				cout << " " << meeting[i];
			cout << endl;
		}
	}

	return 0;
}