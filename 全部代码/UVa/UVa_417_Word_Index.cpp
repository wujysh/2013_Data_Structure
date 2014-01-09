#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

map <string, int> dict;

struct word {
	string str;
	int step;
};

void bfs()
{
	queue <word> pre;
	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		cnt++;
		word w;
		w.str += 'a' + i;
		w.step = 0;
		//cout << w.str << endl; // debug
		pre.push(w);
		dict[w.str] = cnt;
	}

	while (!pre.empty()) {
		word pw = pre.front();
		pw.step++;
		pre.pop();
		for (int i = pw.str[pw.str.length()-1]-'a'+1; i < 26; i++) {
			cnt++;
			word w = pw;
			w.str += 'a' + i;
			//cout << w.str << endl; //debug
			if (w.str.length() < 5) pre.push(w);
			dict[w.str] = cnt;
		}
	
	}
}


int main()
{
	bfs();
	string str;
	while (cin >> str && str != "") {
		map <string, int>::iterator it;
		it = dict.find(str);
		if (it != dict.end())
			cout << it->second << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}
