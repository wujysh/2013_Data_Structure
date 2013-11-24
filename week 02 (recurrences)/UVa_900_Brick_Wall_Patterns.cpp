#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	int n[1000], i=0, max=0;
	while (scanf("%d", &n[i]) != EOF) {
		if (n[i] == 0) break;
		if (n[i] > max) max = n[i]; 
		i++;
	}
	int count=i;
	long long int fib[100000];
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i <= max; i++)
		fib[i] = fib[i-1] + fib[i-2];
	for (int i = 0; i < count; i++)
		printf("%d\n", fib[n[i]]);
	return 0;
}