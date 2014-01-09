#include <cstdio>
#include <cstdlib>
using namespace std;

int buf[10000];

int cmp (const void *a, const void *b) 
{ 
	return *(int *)a - *(int *)b;
} 

int main()
{
	int i = 0;
	while (scanf_s("%d", &buf[i]) != EOF)
	{
		qsort(buf, i+1, sizeof(buf[0]), cmp);
		if ((i+1) % 2 == 1)
			printf("%d\n", buf[i/2]);
		else
			printf("%d\n", (buf[i/2] + buf[i/2+1]) / 2);
		i++;
	}
	return 0;
}