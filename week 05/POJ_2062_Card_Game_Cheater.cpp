#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Card {
private:
	int value, suit, cmpValue;
public:
	void initial() {value = 0;  suit = 0;  cmpValue = 0;}
	void setValue(int v) {value = v;}
	void setSuit(int s) {suit = s;}
	void setCmpValue(int c) {cmpValue = c;}
	int getCmpValue () const {return cmpValue;}
	friend bool operator< (const Card a, const Card b) {
		return (a.cmpValue < b.cmpValue);
	}
};

class CardGameCheater {
private:
	int k, points;
	priority_queue <Card> qAdam, qEve;
public:
	void initial() {
		points = 0;
		while (!qAdam.empty()) qAdam.pop();
		while (!qEve.empty()) qEve.pop();
	}
	void input();
	void work();
	void output() {cout << points << endl;}
	int ConvertValue(char ch);
	int ConvertSuit(char ch);
};
void CardGameCheater::input() {
	Card Adam, Eve;
	string st;
	cin >> k;
	for (int i = 0; i < k; i++) {  // Adam
		cin >> st;
		int v, s, c;
		v = ConvertValue(st[0]);
		s = ConvertSuit(st[1]);
		c = v * 10 + s;
		Adam.initial();
		Adam.setValue(v);
		Adam.setSuit(s);
		Adam.setCmpValue(c);
		qAdam.push(Adam);
	}
	for (int i = 0; i < k; i++) {  // Eve
		cin >> st;
		int v, s, c;
		v = ConvertValue(st[0]);
		s = ConvertSuit(st[1]);
		c = v * 10 + s;
		Eve.initial();
		Eve.setValue(v);
		Eve.setSuit(s);
		Eve.setCmpValue(c);
		qEve.push(Eve);
	}
}
void CardGameCheater::work() {
	while (!qAdam.empty()) {
		if (qEve.top().getCmpValue() > qAdam.top().getCmpValue()) {
			points++;
			qAdam.pop();
			qEve.pop();
		} else {
			qAdam.pop();
		}
	}
}
int CardGameCheater::ConvertValue(char ch) {
	switch (ch) {
		case 'T': return 10;
		case 'J': return 11;
		case 'Q': return 12;
		case 'K': return 13;
		case 'A': return 14;  // Ace is the biggest
		default: return ch - '0';
	}
	return 0;
}
int CardGameCheater::ConvertSuit(char ch) {
	switch (ch) {
		case 'C': return 1;
		case 'D': return 2;
		case 'S': return 3;
		case 'H': return 4;
	}
	return 0;
}

int main() {
	CardGameCheater cgc;
	int n;
	cin >> n;
	while (n--) {
		cgc.initial();
		cgc.input();
		cgc.work();
		cgc.output();
	}
	return 0;
}