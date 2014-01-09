#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CleverNamingPatterns {
private:
	int numOfProblems;
	int numOfNames;
	vector <vector <int> > suitNames;
	vector <vector <string> > problemNames;
	vector <string> ans, maxAns;
private:
	vector <bool> visitedN;
	vector <int> pairNP;
	bool findPath(int);
public:
	void init();
	void input();
	void work();
	void output(int);
};
void CleverNamingPatterns::init() {
	numOfNames = 0;
	suitNames.clear();
	problemNames.clear();
	ans.clear();

	visitedN.clear();
	pairNP.clear();
}
void CleverNamingPatterns::input() {
	cin >> numOfProblems;
	suitNames.resize(numOfProblems);
	problemNames.resize(numOfProblems);
	for (int i = 0; i < numOfProblems; i++) {
		problemNames[i].clear();
		problemNames[i].resize(26);
		int numOfCandidateNames;
		cin >> numOfCandidateNames;
		for (int j = 0; j < numOfCandidateNames; j++) {
			string name;
			cin >> name;
			name[0] = toupper(name[0]);
			for (unsigned k = 1; k < name.length(); k++)
				name[k] = tolower(name[k]);
			problemNames[i][name[0] - 'A'] = name;
			suitNames[i].push_back(name[0] - 'A');
		}
		numOfNames += numOfCandidateNames;
	}
}
bool CleverNamingPatterns::findPath(int p) {
	for (unsigned i = 0; i < suitNames[p].size(); i++) {
		int n = suitNames[p][i];
		if (!visitedN[n]) {
			visitedN[n] = true;
			if ((pairNP[n] == -1) || (findPath(pairNP[n]) == true)) {
				pairNP[n] = p;
				ans[p] = problemNames[p][n];
				return true;
			}
		}
	}
	return false;
}
void CleverNamingPatterns::work() {
	for (int n = 0; n < 26; n++) {
		pairNP.push_back(-1);
	}
	ans.resize(numOfProblems);

	int matching = 0, maxMatching = 0;
	for (int p = numOfProblems - 1; p >= 0; p--) {
		visitedN.clear();
		visitedN.resize(26);
		if (findPath(p)) {
			matching++;
		}
		if (matching > maxMatching) {
			maxMatching = matching;
			maxAns = ans;
		}
	}
}
void CleverNamingPatterns::output(int nCase) {
	cout << "Case #" << nCase << ":" << endl;
	sort(maxAns.begin(), maxAns.end());
	for (unsigned i = 0; i < maxAns.size(); i++) {
		cout << maxAns[i] << endl;
	}
}

int main() {
	int nCase;
	CleverNamingPatterns cnp;
	cin >> nCase;
	for (int i = 1; i <= nCase; i++) {
		cnp.init();
		cnp.input();
		cnp.work();
		cnp.output(i);
	}
	return 0;
}
