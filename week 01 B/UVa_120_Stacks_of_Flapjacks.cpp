#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  

int cmp (const void *a, const void *b) 
{ 
	return *(int *)a - *(int *)b;
}  

void flip(int a[], int i, int j, int n)
{
	printf("%d ", n-j);
	while (i < j) {  
        int tmp = a[i];  
        a[i] = a[j];  
        a[j] = tmp;  
        i++;  
        j--;  
    }  
}
  
int main()
{  
    int a[35], b[35], n;  
  
    while (scanf("%d", &a[0]) != EOF) {   
        n = 1;  
        if (getchar() != '\n')  
            while (scanf("%d", &a[n++]))  
                if (getchar() == '\n')  break;  
  
        for (int i = 0; i < n; i++) {  
            b[i] = a[i];  
            printf("%d ", a[i]);  
        }  
        printf("\n");  
  
        qsort(b, n, sizeof(int), cmp);  
    
        for (int i = n-1; i >= 0; i--) {  
            if (a[i] == b[i])   continue;  
            for (int j = i-1; j >= 0; j--) {  
                if (b[i] == a[j]) {  
                    if (j == 0) {  
						flip(a, 0, i, n);
                    }  
                    else {  
						flip(a, 0, j, n);
						flip(a, 0, i, n);
                    }  
                }  
            }  
        }  
        printf("0\n");  
    }  
    return 0;  
}  