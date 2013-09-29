#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
using namespace std;

class StudentGrants
{
private:
	vector<int> student;
	queue<int> ATMqueue, leave;
	int numOfStudent, limitOfATM;
public:
	void init() {
		student.clear();
		while (!ATMqueue.empty())
			ATMqueue.pop();
		while (!leave.empty())
			leave.pop();
	}
	void read(int n, int k) {
		student.resize(n+1);
		numOfStudent = n;
		limitOfATM = k;
		for (int i = 1; i <= n; i++) {
			ATMqueue.push(i);
			student[i] = 0;
		}
	}
	void work();
	void print() {
		while (!leave.empty()) {
			cout << setw(3) << leave.front();
			leave.pop();
		}
		cout << endl;
	}
};
void StudentGrants::work()
{
	int curAmount = 1, outputStore = 1;
	while (!ATMqueue.empty()) {
		int curStudent = ATMqueue.front();
		if (student[curStudent] + outputStore <= 40) {
			student[curStudent] += outputStore;
			curAmount = 1 + (curAmount % limitOfATM);
			outputStore = curAmount;
		} else {
			outputStore -= 40 - student[curStudent];
			student[curStudent] = 40;
		}
		ATMqueue.pop();
		if (student[curStudent] == 40) {
			leave.push(curStudent);
		} else {
			ATMqueue.push(curStudent);
		}
	}
}

int main()
{
	StudentGrants sg;
	int n, k;
	while ((cin >> n >> k) && n || k) {
		sg.init();
		sg.read(n, k);
		sg.work();
		sg.print();
	}
	return 0;
}
