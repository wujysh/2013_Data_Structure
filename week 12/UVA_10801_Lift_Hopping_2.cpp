#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

class LiftHopping {
private:
	int numOfElevators, endFloor;
	int timeOfElevator[5];
	int graph[100][100];
	int node[5][100], numOfNode;

public:
	void initial(int, int);
	void input();
	void work();
	void output();
};
void LiftHopping::initial(int n, int k) {
	numOfElevators = n;
	endFloor = k;
	memset(timeOfElevator, 0, sizeof(timeOfElevator));
	memset(graph, -1, sizeof(graph));
	memset(node, -1, sizeof(node));
	numOfNode = 0;
}
void LiftHopping::input() {
	for (int i = 0; i < numOfElevators; i++) {
		cin >> timeOfElevator[i];
	}
	getchar();
	for (int i = 0; i < numOfElevators; i++) {
		string line;
		getline(cin, line);
		for (int j = 0; j < line.length(); j++) {
			int k;
			for (k = j; line[k] != ' ' && k < line.length(); k++);
			string tmp = line.substr(j, k - j);
			node[i][stoi(tmp)] = numOfNode;
			numOfNode++;
			j = k;
		}
		for (int j = 0; j < 99; j++) {
			for (int k = j + 1; k < 100; k++) {
				if (node[i][j] != -1 && node[i][k] != -1) {
					graph[node[i][j]][node[i][k]] = (k - j) * timeOfElevator[i];
					graph[node[i][k]][node[i][j]] = (k - j) * timeOfElevator[i];
				}
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < numOfElevators - 1; j++) {
			if (node[j][i] != -1) {
				for (int k = j + 1; k < numOfElevators; k++) {
					if (node[k][i] != -1) {
						graph[node[j][i]][node[k][i]] = 60;
						graph[node[k][i]][node[j][i]] = 60;
					}
				}
			}
		}
	}

	// debug
	/*cout << "Node num:" << endl;
	for (int i = 0; i < numOfElevators; i++) {
		cout << "Elevator No." << i + 1 << ":";
		for (int j = 0; j < 100; j++) {
			if (node[i][j] != -1)
				cout << " " << node[i][j];
		}
		cout << endl;
	}
	cout << "Graph:" << endl;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}*/
}
void LiftHopping::work() {

}
void LiftHopping::output() {

}

int main() {
	LiftHopping lh;
	int n, k;
	while (cin >> n >> k) {
		lh.initial(n, k);
		lh.input();
		lh.work();
		lh.output();
	}
	return 0;
}
