#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct XY {
	double x;
	double y;
	XY(double a = 0, double b = 0) { x = a; y = b; }
	double distance(XY p) {
		return sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y));
	}
};
class GopherII {
private:
	int numberOfGophers;
	int numberOfHoles;
	int timeLimit;
	int velocity;
	vector < vector <int> > reachedHoles;
	int numberOfVulnerables;
private:
	vector <bool> visitedH;
	vector <int> pairHG;
	bool findPath(int);
public:
	void initial(int, int, int, int);
	void readCase();
	void computing();
	void outResult() { cout << numberOfVulnerables << endl; }
};
void GopherII::initial(int n, int m, int s, int v) {
	numberOfGophers = n;
	numberOfHoles = m;
	timeLimit = s;
	velocity = v;
	reachedHoles.clear();
	numberOfVulnerables = numberOfGophers;
	visitedH.clear();
	pairHG.clear();
	for (int h = 0; h < numberOfHoles; h++) {
		pairHG.push_back(-1); //begin with no matching
	}
}
void GopherII::readCase() {
	double x, y;
	vector <XY> posGopher, posHole;
	for (int i = 0; i < numberOfGophers; i++) {
		cin >> x >> y;
		posGopher.push_back(XY(x, y));
	}
	for (int i = 0; i < numberOfHoles; i++) {
		cin >> x >> y;
		posHole.push_back(XY(x, y));
	}
	const double eps = 1e-10;
	vector <int> holes;
	for (int g = 0; g < posGopher.size(); g++) {
		holes.clear();
		for (int h = 0; h < posHole.size(); h++) {
			if (double(velocity * timeLimit) - posGopher[g].distance(posHole[h]) > eps) {
				holes.push_back(h);
			}
		}
		reachedHoles.push_back(holes);
	}
}
bool GopherII::findPath(int g) {
	for (int i = 0; i < reachedHoles[g].size(); i++) {
		int h = reachedHoles[g][i];
		if (!visitedH[h]) {
			visitedH[h] = true;
			if ((pairHG[h] == -1) || (findPath(pairHG[h]) == true)) {
				pairHG[h] = g;
				return true;
			}
		}
	}
	return false;
}
void GopherII::computing() {
	int matching = 0;
	for (int g = 0; g < numberOfGophers; g++) {
		visitedH.clear();
		visitedH.resize(numberOfHoles);
		if (findPath(g)) {
			matching++;
		}
	}
	numberOfVulnerables = numberOfGophers - matching;
}

int main() {
	int n, m, s, v;
	GopherII gii;
	while (cin >> n >> m >> s >> v) {
		gii.initial(n, m, s, v);
		gii.readCase();
		gii.computing();
		gii.outResult();
	}
	return 0;
}
