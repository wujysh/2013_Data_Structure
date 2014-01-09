#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))
using namespace std;

const int MAXN = 30;
const int INF = 1 << 20;

class MeetingProfMiguel {
private:
	int numOfStreets, minimumEnergy;
	int gYoung[MAXN][MAXN], gOld[MAXN][MAXN];
	char posMe, posProf;
	map <char, int> city;
	vector <char> ans;
public:
	void init(int);
	void input();
	void process();
	void floyd();
};
void MeetingProfMiguel::init(int n) {
	numOfStreets = n;
	minimumEnergy = INF;
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			if (i == j) {
				gYoung[i][j] = gOld[i][j] = 0;
			} else {
				gYoung[i][j] = gOld[i][j] = INF;
			}
		}
	}
	ans.clear();
	city.clear();
}
void MeetingProfMiguel::input() {
	for (int i = 0; i < numOfStreets; i++) {
		char a, b, c, d;
		int e;
		cin >> a >> b >> c >> d >> e;
		if (city.find(c) == city.end()) city[c] = city.size();
		if (city.find(d) == city.end()) city[d] = city.size();
		if (a == 'Y') {
			if (b == 'U') {
				gYoung[city[c]][city[d]] = min(gYoung[city[c]][city[d]], e);
			} else if (b == 'B') {
				gYoung[city[c]][city[d]] = gYoung[city[d]][city[c]] = min(gYoung[city[c]][city[d]], e);
			}
		} else if (a == 'M') {
			if (b == 'U') {
				gOld[city[c]][city[d]] = min(gOld[city[c]][city[d]], e);
			} else if (b == 'B') {
				gOld[city[c]][city[d]] = gOld[city[d]][city[c]] = min(gOld[city[c]][city[d]], e);
			}
		}
	}
	cin >> posMe >> posProf;
	if (city.find(posMe) == city.end()) city[posMe] = city.size();
	if (city.find(posProf) == city.end()) city[posProf] = city.size();
}
void MeetingProfMiguel::floyd() {
	for (unsigned k = 0; k < city.size(); k++) {
		for (unsigned i = 0; i < city.size(); i++) {
			for (unsigned j = 0; j < city.size(); j++) {
				gYoung[i][j] = min(gYoung[i][j], gYoung[i][k] + gYoung[k][j]);
				gOld[i][j] = min(gOld[i][j], gOld[i][k] + gOld[k][j]);
			}
		}
	}
}
void MeetingProfMiguel::process() {
	if (city.find(posMe) == city.end() || city.find(posProf) == city.end()) {
		if (posMe == posProf)
			cout << 0 << " " << posMe << endl;
		else
			cout << "You will never meet." << endl;
		return;
	}

	floyd();

	map <char, int>::iterator it;
	for (it = city.begin(); it != city.end(); it++) {
		int totalEnergy = gYoung[city[posMe]][it->second] + gOld[city[posProf]][it->second];
		if (totalEnergy <= minimumEnergy) {
			if (totalEnergy < minimumEnergy) {
				minimumEnergy = totalEnergy;
				ans.clear();
			}
			ans.push_back(it->first);
		}
	}

	if (minimumEnergy == INF) {
		cout << "You will never meet." << endl;
	} else {
		cout << minimumEnergy;
		sort(ans.begin(), ans.end());
		for (unsigned i = 0; i < ans.size(); i++) {
			cout << " " << ans[i];
		}
		cout << endl;
	}
}

int main() {
	MeetingProfMiguel mpm;
	int n;
	while (cin >> n && n) {
		mpm.init(n);
		mpm.input();
		mpm.process();
	}
}