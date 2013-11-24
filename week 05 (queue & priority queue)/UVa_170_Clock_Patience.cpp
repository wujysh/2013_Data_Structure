#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;

struct card {
	char rank, suit;
};

int main()
{
	while (true) {
		queue <card> cards[13];

		for (int j = 0; j < 4; j++) {
			for (int i = 0; i < 13; i++) {
				card c;
				c.rank = getchar();
				if (c.rank == '#') return 0;
				c.suit = getchar();
				//cout << c.rank << c.suit << endl; // debug
				cards[i].push(c);
				getchar();
			}
			//getchar();
		}

		int cnt = 1;
		card nc = cards[0].front(), lastcard;
		if (!cards[0].empty()) cards[0].pop();
		while (true) {
			//cout << nc.rank << nc.suit << endl; // debug
			int nextpile;
			if (nc.rank == 'A') nextpile = 12;
            else if (nc.rank == 'T') nextpile = 3;
            else if (nc.rank == 'J') nextpile = 2;
            else if (nc.rank == 'Q') nextpile = 1;
            else if (nc.rank == 'K') nextpile = 0;
            else nextpile = 13 - (nc.rank - '0');

			if (cards[nextpile].empty()) {
				lastcard = nc;
				break;
			}
			else {
				nc = cards[nextpile].front();
				cards[nextpile].pop();
				cnt++;
			}
		}
		if (cnt < 10) cout << '0';
		cout << cnt << ',' << lastcard.rank << lastcard.suit << endl;
	}
	return 0;
}
