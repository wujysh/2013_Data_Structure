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

class DogTask {
private:
	int numberOfMeetingPoints;
	int numberOfInterestingPlaces;
	int numberOfMatchedInterestingPlaces;
	vector < vector <int> > reachedInterestingPlaces;
	vector <XY> posMeetingPoint, posInterestingPlace;
private:
	vector <bool> visitedI;
	vector <int> pairIM;
	bool findPath(int);
public:
	void initial(int, int);
	void readCase();
	void computing();
	void outResult() {
		cout << numberOfMatchedInterestingPlaces + numberOfMeetingPoints << endl;
		vector <int> result;
		for (int i = 0; i < numberOfMeetingPoints; i++) {
			result.push_back(-1);
		}
		for (int i = 0; i < numberOfInterestingPlaces; i++) {
			if (pairIM[i] != -1) {
				result[pairIM[i]] = i;
			}
		}
		for (int i = 0; i < numberOfMeetingPoints - 1; i++) {
			cout << posMeetingPoint[i].x << " " << posMeetingPoint[i].y << " ";
			if (result[i] != -1) {
				cout << posInterestingPlace[result[i]].x << " " << posInterestingPlace[result[i]].y << " ";
			}
		}
		cout << posMeetingPoint[numberOfMeetingPoints - 1].x << " " << posMeetingPoint[numberOfMeetingPoints - 1].y << endl;
	}
};
void DogTask::initial(int n, int m) {
	numberOfMeetingPoints = n;
	numberOfInterestingPlaces = m;
	numberOfMatchedInterestingPlaces = 0;
	reachedInterestingPlaces.clear();
	visitedI.clear();
	pairIM.clear();
	posMeetingPoint.clear();
	posInterestingPlace.clear();
	for (int i = 0; i < numberOfInterestingPlaces; i++) {
		pairIM.push_back(-1);
	}
}
void DogTask::readCase() {
	double x, y;
	for (int i = 0; i < numberOfMeetingPoints; i++) {
		cin >> x >> y;
		posMeetingPoint.push_back(XY(x, y));
	}
	for (int i = 0; i < numberOfInterestingPlaces; i++) {
		cin >> x >> y;
		posInterestingPlace.push_back(XY(x, y));
	}
	const double eps = 1e-20;
	vector <int> InterestingPlaces;
	for (int m = 0; m < posMeetingPoint.size() - 1; m++) {
		InterestingPlaces.clear();
		for (int i = 0; i < posInterestingPlace.size(); i++) {
			if (2 * posMeetingPoint[m].distance(posMeetingPoint[m + 1])
				- posMeetingPoint[m].distance(posInterestingPlace[i])
				- posMeetingPoint[m + 1].distance(posInterestingPlace[i]) > eps) {
				InterestingPlaces.push_back(i);
			}
		}
		reachedInterestingPlaces.push_back(InterestingPlaces);
	}
}
bool DogTask::findPath(int m) {
	for (int i = 0; i < reachedInterestingPlaces[m].size(); i++) {
		int h = reachedInterestingPlaces[m][i];
		if (!visitedI[h]) {
			visitedI[h] = true;
			if ((pairIM[h] == -1) || (findPath(pairIM[h]) == true)) {
				pairIM[h] = m;
				return true;
			}
		}
	}
	return false;
}
void DogTask::computing() {
	int matching = 0;
	for (int m = 0; m < numberOfMeetingPoints - 1; m++) {
		visitedI.clear();
		visitedI.resize(numberOfInterestingPlaces);
		if (findPath(m)) {
			matching++;
		}
	}
	numberOfMatchedInterestingPlaces = matching;
}

int main() {
	int L;
	DogTask dt;
	cin >> L;
	while (L--) {
		int N, M;
		cin >> N >> M;
		dt.initial(N, M);
		dt.readCase();
		dt.computing();
		dt.outResult();
		if (L) cout << endl;
	}
	return 0;
}
