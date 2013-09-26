#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//typedef pair<string, int> PAIR;
//int cmp(const PAIR& x, const PAIR& y)
//{
//    if (x.second == y.second)
//		if (x.first == "Li Ming")
//			return 1;
//		else
//			return 0;
//	return x.second > y.second;
//}
 
int main()
{
	map<string, int> student;

	int n, m;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		string name;
		getline(cin, name);
		student[name] = 0;
	}
	
	cin >> m;

	while (m--) {
		int value = 0, num[10010], count = 0, ans = 0;

		for (int i = 0; i < n; i++) {
			string name;
			int score;
			scanf("%d", &score);
			getchar();
			getline(cin, name);
			student[name] += score;
			if (name == "Li Ming")
				value = student[name];
		}
		
		for (map<string, int>::iterator it = student.begin(); it != student.end(); ++it) {  
			num[count++] = it->second;
		}
		for (int i = 0; i < count; i++) {
			if (num[i] > value)
				ans++;
		}
		ans++;
		printf("%d\n", ans);
		/*vector<PAIR> vec;
		for (map<string, int>::iterator it = student.begin(); it != student.end(); ++it) {  
			vec.push_back(make_pair(it->first, it->second));
		}
		sort(vec.begin(), vec.end(), cmp);

		int count = 0;
		for(vector<PAIR>::iterator it = vec.begin(); it != vec.end(); ++it) {  
			count++;
			if (it->first == "Li Ming") {
				printf("%d\n", count);
				break;
			}
		} */

	}
	return 0;
}