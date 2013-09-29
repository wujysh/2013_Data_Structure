#include <iostream>
#include <queue>
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
		queue.pop();
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
	int intCandidate, intBallot;
public:
	void init()
	{
		ranking.clear();
		ballot.init();
		intCandidate = 0;
		intBallot = 0;
		eliminated = false;
	}
	void read()
	{
		cin >> intCandidate;
		ranking.resize(intCandidate+1);
		for (int i = 1; i <= intCandidate; i++) {
			string strName;
			getline(strName);
			ranking[i].name = strName;
			ranking[i].recvBallot = 0;
		}
		int c1, c2, c3;
		while (cin >> c1 >> c2 >> c3 && c1 && c2 && c3) {
			ballot[intBallot].read(c1, c2, c3);
			intBallot++;
		}
		getline();			
	}
	void work();
	void print()
	{
		// TODO:
		cout << endl;
	}
};
void AustralianVoting::work()
{
	bool DONE = false;
	while (!DONE) {
		int max = 0, maxc = 0, min = 1000, minc = 0;
		// count the ballots
		for (int i = 0; i < intBallot; i++) {
			int choice = ballot[i].getChoice();
			ranking[choice].recvBallot++;
			if (ranking[choice].recvBallot > max) {
				max = ranking[choice].recvBallot;
				maxc = choice;
			}
			if (ranking[choice].recvBallot < min) {
				min = ranking[choice].recvBallot;
				minc = choice;
			}
		}
		// eliminate the tied lowest candidates
		for (int i = 1; i <= intCandidate; i++) {
			if (!ranking[i].eliminated && ranking[i].recvBallot == min) {
				ranking[i].eliminated = true;
				for (int j = 0; j < intBallot; j++) {
					if (ballot[j].getchoice() == i) {
						ballot[j].popChoice();
					}
				}
			}
		}
		// detect whether someone has won the voting
		// TODO:

	}
	

}

int main()
{
	AustralianVoting av;
	int intCase;
	cin >> intCase;
	getline();
	while (intCase--) {
		av.init();
		av.read();
		av.work();
		av.print();
	}
	return 0;
}
