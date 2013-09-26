#include <stdio.h>

int main()
{
	int n, num[50];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		int l, count=0, temp;
		scanf_s("%d", &l);
		for (int j = 0; j < l; j++)
			scanf_s("%d", &num[j]);
		for (int j = l-1; j > 0; j--)
			for (int k = j-1; k >= 0; k--)
				if (num[k] > num[j]) {
					count++;
					temp = num[k];
					num[k] = num[j];
					num[j] = temp;
				}
		printf("Optimal train swapping takes %d swaps.\n", count);
	}
	return 0;
}