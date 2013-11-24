#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n, p, h[100], count=0;
		scanf("%d", &n);
		scanf("%d", &p);
		for (int j = 0; j < p; j++)
			scanf("%d", &h[j]);
		for (int j = 0; j < n; j++)
			if (j % 7 != 5 && j % 7 != 6)
				for (int k = 0; k < p; k++)
					if ((j+1) % h[k] == 0) {
						count++;
						break;
					}
		printf("%d\n", count);
	}
	return 0;
}