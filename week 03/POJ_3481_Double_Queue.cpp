#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, int> list;
	map<int, int>::iterator it;

	int order;
	while (scanf("%d", &order) && order) {
		switch (order) {
		case 1:
			int k, p;
			scanf("%d %d", &k, &p);
			list[p] = k;
			break;
		case 2:
			if (list.empty()) {
				printf("0\n");
				continue;
			}
			it = list.end();
			it--;
			printf("%d\n", it->second);
			list.erase(it);
			break;
		case 3:
			if (list.empty()) {
				printf("0\n");
				continue;
			}
			it = list.begin();
			printf("%d\n", it->second);
			list.erase(it);
			break;
		}
	}
	return 0;
}