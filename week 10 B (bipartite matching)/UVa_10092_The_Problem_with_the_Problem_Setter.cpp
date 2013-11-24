#include <iostream>
#include <vector>
#include <map>
using namespace std;

class ProblemSetter {
private:
	int numberOfCategories;
	int numberOfCategoriesAll;
	int numberOfProblems;
	int numberOfUnmatchedCategories;
	vector < vector <int> > suitCategories;
	vector < vector <int> > result;
	map <int, int> categoryNo;
	map <int, int> noCategory;
private:
	vector <bool> visitedP;
	vector <int> pairPC;
	bool findPath(int);
public:
	void initial(int, int);
	void readCase();
	void computing();
	void outResult();
};
void ProblemSetter::initial(int nk, int np) {
	numberOfCategories = nk;
	numberOfProblems = np;
	numberOfCategoriesAll = 0;
	suitCategories.clear();
	visitedP.clear();
	pairPC.clear();
	categoryNo.clear();
	noCategory.clear();
	result.clear();
	for (int p = 0; p < numberOfProblems; p++) {
		pairPC.push_back(-1);
	}
}
void ProblemSetter::readCase() {
	for (int i = 0; i < numberOfCategories; i++) {
		int x;
		cin >> x;
		if (categoryNo.find(i) == categoryNo.end()) {
			categoryNo[i] = numberOfCategoriesAll;
		}
		numberOfCategoriesAll += x;
	}
	categoryNo[numberOfCategories] = numberOfCategoriesAll;
	numberOfUnmatchedCategories = numberOfCategoriesAll;
	suitCategories.resize(numberOfCategoriesAll);

	for (int i = 0; i < numberOfProblems; i++) {
		int numberOfCategoriesOfProblem;
		cin >> numberOfCategoriesOfProblem;
		for (int j = 0; j < numberOfCategoriesOfProblem; j++) {
			int category;
			cin >> category;
			category--;
			for (int k = categoryNo[category]; k < categoryNo[category + 1]; k++) {
				suitCategories[k].push_back(i);
				if (noCategory.find(k) == noCategory.end()) {
					noCategory[k] = category;
				}
			}
		}
	}
}
bool ProblemSetter::findPath(int c) {
	for (int i = 0; i < suitCategories[c].size(); i++) {
		int p = suitCategories[c][i];
		if (!visitedP[p]) {
			visitedP[p] = true;
			if ((pairPC[p] == -1) || (findPath(pairPC[p]) == true)) {
				pairPC[p] = c;
				return true;
			}
		}
	}
	return false;
}
void ProblemSetter::computing() {
	int matching = 0;
	for (int c = 0; c < numberOfCategoriesAll; c++) {
		visitedP.clear();
		visitedP.resize(numberOfProblems);
		if (findPath(c)) {
			matching++;
		}
	}
	numberOfUnmatchedCategories = numberOfCategoriesAll - matching;
}
void ProblemSetter::outResult() {
	if (numberOfUnmatchedCategories) {
		cout << "0" << endl;
	} else {
		cout << "1" << endl;
		result.resize(numberOfCategories);
		for (int i = 0; i < numberOfProblems; i++) {
			if (pairPC[i] != -1) {
				result[noCategory[pairPC[i]]].push_back(i + 1);
			}
		}
		for (int i = 0; i < numberOfCategories; i++) {
			for (int j = 0; j < result[i].size(); j++) {
				if (j) cout << " ";
				cout << result[i][j];
			}
			cout << endl;
		}
	}
}

int main() {
	int nk, np;
	ProblemSetter ps;
	while (cin >> nk >> np && (nk || np)) {
		ps.initial(nk, np);
		ps.readCase();
		ps.computing();
		ps.outResult();
	}
	return 0;
}
