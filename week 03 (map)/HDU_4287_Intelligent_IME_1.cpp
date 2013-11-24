#include <iostream>
#include <string>
#include <map>
using namespace std;
#define MAXN 5010

int t, n, m;
char ch[26] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', 
	'5', '5', '5', '6', '6', '6', '7', '7', '7', '7', '8', '8', '8',
	'9', '9', '9', '9'};
string word[MAXN];
string str[MAXN];
map<string , int>mp;

void solve() {
	map<string , int>::iterator it;
	for (int i = 0; i < m; i++) {
		cin >> word[i];
		string s = "";
		for(int j = 0 ; j < word[i].size() ; j++)
			s += ch[word[i][j]-'a'];
		it = mp.find(s);
		if(it != mp.end())
			mp[s]++;
		else 
			mp[s] = 1;
	}
	for(int i = 0 ; i < n ; i++)
		printf("%d\n" , mp[str[i]]-1);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		mp.clear();
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++){
			cin>>str[i];
			mp[str[i]] = 1;
		}
		solve();
	}
}