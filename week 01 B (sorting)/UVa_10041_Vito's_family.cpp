#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int num[500];

int cmp (const void *a, const void *b) 
{ 
	return *(int *)a - *(int *)b;
} 

int main()
{
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		int r, index, d=0;
		scanf_s("%d", &r);
		memset(num, 0, 500*sizeof(int));
		for (int j = 0; j < r; j++)
			scanf_s("%d", &num[j]);
		qsort(num, r, sizeof(num[0]), cmp);
		if (r % 2 == 1)
			index = r / 2;
		else
			index = r / 2 - 1;
		for (int j = 0; j < r; j++)
			if (j != index)
				d += abs(num[index] - num[j]);
		printf("%d\n", d);
	}
	return 0;
}