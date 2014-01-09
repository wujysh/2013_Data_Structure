#include <iostream>
#include <cstdio>
#include <sstream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class Ballot
{
private:
	queue<int> choices;
public:
	void init() {
		while (!choices.empty())
			choices.pop();
	}
	void read(int c1, int c2, int c3) {
		choices.push(c1);
		choices.push(c2);
		choices.push(c3);
	}
	int getChoice() {
		return choices.front();
	}
	void popChoice() {
		choices.pop();
	}
};

struct Candidate
{
	string name;
	int recvBallot;
	bool eliminated;
};

class AustralianVoting
{
private:
	vector<Candidate> ranking;
	Ballot ballot[1000];
	int intCandidate, intBallot, intWinnerCnt, intWinner, intValidCandidate;
public:
	void init()
	{
		ranking.clear();
		intCandidate = 0;
		intValidCandidate = 0;
		intBallot = 0;
		intWinner = 0;
	}
	void read()
	{
		cin >> intCandidate;
		//cout << intCandidate << endl;  //debug
		getchar();
		intValidCandidate = intCandidate;
		ranking.resize(intCandidate+1);
		for (int i = 1; i <= intCandidate; i++) {
			getline(cin, ranking[i].name);
			//cout << ranking[i].name << endl; // debug
			ranking[i].recvBallot = 0;
			ranking[i].eliminated = false;
		}
		
		string str;
		while (getline(cin, str) && str != "") {
			int c1 = 0, c2 = 0, c3 = 0;
			stringstream scin(str);
			scin >> c1 >> c2 >> c3;
			if (c1 == 0 || c2 == 0 || c3 == 0) break;
			//cout << c1 << c2 << c3 << endl; // debug
			ballot[intBallot].init();
			ballot[intBallot].read(c1, c2, c3);
			intBallot++;
		}
		//getline(cin, temp);  // ignore the blank line
	}
	void work();
	void print()
	{
		if (intWinnerCnt == 1) {
			cout << ranking[intWinner].name << endl;
		}
		if (intWinnerCnt == intValidCandidate) {
			for (int i = 1; i <= intCandidate; i++)
				if (!ranking[i].eliminated)
					cout << ranking[i].name << endl;
		}
		cout << endl;
	}
};
void AustralianVoting::work()
{
	bool DONE = false;
	while (!DONE) {
		int max = 0, maxc = 0, maxn = 0, min = 1000, minc = 0;
		// reset the count
		for (int i = 1; i <= intCandidate; i++) {
			ranking[i].recvBallot = 0;
		}

		// count the ballots
		for (int i = 0; i < intBallot; i++) {
			int choice = ballot[i].getChoice();
			ranking[choice].recvBallot++;
			if (ranking[choice].recvBallot > max) {
				max = ranking[choice].recvBallot;
				maxc = choice;
				maxn = 0;
			}
			if (ranking[choice].recvBallot < min) {
				min = ranking[choice].recvBallot;
				minc = choice;
			}
			if (ranking[choice].recvBallot == max) {  // record the number of candidates received the highest ballot
				maxn++;
			}

		}

		// judge whether the ballot has ended
		if (maxn == 1 && ranking[maxc].recvBallot * 2 >= intBallot) {
			intWinnerCnt = 1;
			intWinner = maxc;
			DONE = true;
			return;
		}
		if (maxn == intValidCandidate) {
			intWinnerCnt = intValidCandidate;
			DONE = true;
			return;
		}

		// eliminate the tied lowest candidates
		for (int i = 1; i <= intCandidate; i++) {
			if (!ranking[i].eliminated && ranking[i].recvBallot == min) {
				ranking[i].eliminated = true;
				for (int j = 0; j < intBallot; j++) {
					if (ballot[j].getChoice() == i) {
						ballot[j].popChoice();
					}
				}
				intValidCandidate--;
			}
		}
	}

}

int main()
{
	AustralianVoting av;
	int intCase;
	string temp;
	cin >> intCase;
	//cout << intCase; // debug
	getchar();
	getline(cin, temp);	  // ignore the blank line
	while (intCase--) {
		av.init();
		av.read();
		av.work();
		av.print();
	}
	return 0;
}
