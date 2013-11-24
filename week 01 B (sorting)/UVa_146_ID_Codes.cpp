#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    char str[100];
    while (gets(str)) {
        if (str[0] == '#')
			break;

        int len = strlen(str);

        if (next_permutation(str, str+len))
			puts(str);
        else
			printf("No Successor\n");
    }
    return 0;
}