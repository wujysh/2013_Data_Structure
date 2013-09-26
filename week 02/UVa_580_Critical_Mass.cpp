#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>

#include <cstdio>
#include <cmath>
using namespace std;

const int maxn = 500;

int main()
{
	long long danger[maxn], safe[maxn];
	safe[3] = 7;
	safe[4] = 13;
	safe[5] = 24;
	for (int i = 6; i < maxn; i++)
		safe[i] = safe[i-1] + safe[i-2] + safe[i-3];
	for (int i = 3; i < maxn; i++)
		danger[i] = (int)pow(2.0, i) - safe[i];

	int n;
	while (scanf("%d", &n) && n > 0)
		printf("%ld\n", danger[n]);
	
	system("pause");
	return 0;
	}