#include <stdio.h>

int main()
{
	int n, num[1000];
	while (scanf_s("%d", &n) != EOF) {
		int count = 0, temp;
		for (int i = 0; i < n; i++)
			scanf_s("%d", &num[i]);
		for (int i = n-1; i > 0; i--)
			for (int j = i-1; j >= 0; j--)
				if (num[j] > num[i]) {
					count++;
				}
		printf("Minimum exchange operations : %d\n", count);
	}
	return 0;
}