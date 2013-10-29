#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
#define MAXN 30010

int main() {
	int nCase;
	scanf("%d", &nCase);
	while (nCase--) {
		int n, m;
		scanf("%d %d", &n, &m);

		int numOfSet[MAXN], nSet = 0;
		map <int, int> set;
		set.clear();
		memset(numOfSet, 0, sizeof(numOfSet));

		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);

			map <int, int>::iterator ita = set.find(a);
			map <int, int>::iterator itb = set.find(b);
			if (ita == set.end() && itb == set.end()) {  // create set
				nSet++;
				set.insert(make_pair(a, nSet));
				set.insert(make_pair(b, nSet));
				numOfSet[nSet] += 2;
			} else if (ita != set.end() && itb != set.end() && ita != itb) {  // union sets
				int min = ita->second < itb->second ? ita->second : itb->second;
				int max = ita->second > itb->second ? ita->second : itb->second;		
				int cnt = 0;
				map <int, int>::iterator iter;
				for (iter = set.begin(); iter != set.end(); iter++) {
					if (iter->second == max) {
						iter->second = min;
						cnt++;
					}
				}
				numOfSet[max] = 0;
				numOfSet[min] += cnt;
			} else if (ita == set.end() && itb != set.end()) {  // insert a into set of b
				set.insert(make_pair(a, itb->second));
				numOfSet[itb->second]++;
			} else if (ita != set.end() && itb == set.end()) {  // insert b into set of a
				set.insert(make_pair(b, ita->second));
				numOfSet[ita->second]++;
			}
		}

		int max = 0;
		for (int i = 1; i <= nSet; i++) {
			if (numOfSet[i] > max)
				max = numOfSet[i];
		}
		printf("%d\n", max);
	}
	return 0;
}