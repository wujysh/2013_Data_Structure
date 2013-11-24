#include <iostream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

struct Message {
	string name;
	int parameter;
	int priority;
	int order;
	bool friend operator<(Message a, Message b) {
		if (a.priority == b.priority) return a.order > b.order;
		else return a.priority > b.priority;
	}
};

class WindowsMessageQueue {
private:
	priority_queue <Message> q;
	int count;
public:
	void init();
	void process(string);
	void get();
};
void WindowsMessageQueue::init() {
	while (!q.empty()) q.pop();
	count = 0;
}
void WindowsMessageQueue::process(string command) {
	string order = command.substr(0, 3);
	if (order == "GET") {
		get();
	} else {  // "PUT"
		stringstream scin(command.substr(4));
		Message m;
		scin >> m.name >> m.parameter >> m.priority;
		m.order = count;
		q.push(m);
		count++;
	}
}
void WindowsMessageQueue::get() {
	if (q.empty()) {
		cout << "EMPTY QUEUE!" << endl;
	} else {
		Message m = q.top();
		q.pop();
		cout << m.name << " " << m.parameter << endl;
	}
}

int main() {
	WindowsMessageQueue wmq;
	string command;
	wmq.init();
	while (getline(cin, command) && command != "") {
		wmq.process(command);
	}
	return 0;
}