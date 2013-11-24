#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <cstdio>
using namespace std;

const int maxn = 100000;

int main()
{
	long long int ans[maxn];
	ans[1] = 2;
	ans[2] = 3;
	for (int i = 3; i < maxn; i++)
		ans[i] = ans[i-1] + ans[i-2];

	int n, bit;
	scanf("%d", &n);
	for (int j = 0; j < n; j++) {
		scanf("%d", &bit);
		printf("Scenario #%d:\n", j+1);
		printf("%ld\n\n", ans[bit]);
	}

	system("pause");
	return 0;
}