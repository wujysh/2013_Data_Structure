#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

map <string, int> sizeNo;

class Tshirt {
private:
	int numberOfTshirts;
	int numberOfEachSizeTshirt;
	int numberOfVolunteers;
	int numberOfUnmatchedVolunteers;
	vector < vector <int> > suitSizes;
private:
	vector <bool> visitedT;
	vector <int> pairTV;
	bool findPath(int);
public:
	void initial(int, int);
	void readCase();
	void computing();
	void outResult() { cout << (numberOfUnmatchedVolunteers ? "NO" : "YES") << endl; }
};
void Tshirt::initial(int n, int m) {
	numberOfTshirts = n;
	numberOfEachSizeTshirt = n / 6;
	numberOfVolunteers = m;
	numberOfUnmatchedVolunteers = numberOfVolunteers;
	suitSizes.clear();
	visitedT.clear();
	pairTV.clear();
	for (int t = 0; t < numberOfTshirts; t++) {
		pairTV.push_back(-1);
	}
}
void Tshirt::readCase() {
	vector <int> sizes;
	for (int i = 0; i < numberOfVolunteers; i++) {
		sizes.clear();
		string size1, size2;
		cin >> size1 >> size2;
		for (int j = sizeNo[size1] * numberOfEachSizeTshirt; j < (sizeNo[size1] + 1) * numberOfEachSizeTshirt; j++) {
			sizes.push_back(j);
		}
		for (int j = sizeNo[size2] * numberOfEachSizeTshirt; j < (sizeNo[size2] + 1) * numberOfEachSizeTshirt; j++) {
			sizes.push_back(j);
		}
		suitSizes.push_back(sizes);
	}
}
bool Tshirt::findPath(int v) {
	for (int i = 0; i < suitSizes[v].size(); i++) {
		int t = suitSizes[v][i];
		if (!visitedT[t]) {
			visitedT[t] = true;
			if ((pairTV[t] == -1) || (findPath(pairTV[t]) == true)) {
				pairTV[t] = v;
				return true;
			}
		}
	}
	return false;
}
void Tshirt::computing() {
	int matching = 0;
	for (int v = 0; v < numberOfVolunteers; v++) {
		visitedT.clear();
		visitedT.resize(numberOfTshirts);
		if (findPath(v)) {
			matching++;
		}
	}
	numberOfUnmatchedVolunteers = numberOfVolunteers - matching;
}

int main() {
	int nCase;
	Tshirt ts;
	sizeNo["XXL"] = 0;  sizeNo["XL"] = 1;  sizeNo["L"] = 2;
	sizeNo["M"] = 3;  sizeNo["S"] = 4;  sizeNo["XS"] = 5;

	cin >> nCase;
	while (nCase--) {
		int n, m;
		cin >> n >> m;
		ts.initial(n, m);
		ts.readCase();
		ts.computing();
		ts.outResult();
	}
	return 0;
}
