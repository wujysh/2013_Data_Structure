#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main()
{
    long int n, female, male, total, Male, Female;
    while (1)
    {
        scanf("%ld",&n);
        if (n == -1) break;
        female = 1;
        Female = 0;
        total = 1;
        male = 0;
        for (long int i = 1; i <= n; i++) {
            male = total;
            Male = female;
            female += Female;
            total += female;
            Female = Male;
        }
        printf("%ld %ld\n", male, total);
    }
    return 0;
}