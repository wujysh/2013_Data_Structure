#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

char arr[10000000/8+100];
int table[100100];

int sod(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int fun(int a) {
    for (int i = max(1, a - 80); i <= a; i++) {
        if (i + sod(i) == a) {
            return i;
        }
    }
    return -1;
}

int g(int n) {
    int ans = table[n/128];
    for (int i = (n/128) * 128; i <= n; i++) {
        ans += 1 - (((arr[i>>3]) >> (i & 7)) & 1);
    }
    return ans;
}

void genTable() {
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i <= 10000000; i++) {
        int k = i + sod(i);
        for (int j = 0; j < 10; j++) {
            arr[k >> 3] |= 1U << (k & 7);
        }
    }

    table[0] = 0;
    for (int i = 0, j = 1; i <= 10000000; i += 128, j++) {
        table[j] = table[j-1];
        for (int k = 0; k < 128; k++) {
            table[j] += 1 - (((arr[(i+k)>>3]) >> ((i+k) & 7)) & 1);
        }
    }
}

int main() {
    genTable();

    char buf[1024];
    int nCase, n, m;
    scanf("%d", &nCase);
    for (int i = 1; i <= nCase; i++) {
        while (gets(buf) && sscanf(buf, "%d", &n) != 1);
        printf("Case %d: ", i);
        if (sscanf(buf, "%d %d", &n, &m) == 2)
            printf("%d\n", (n <= m) ? (g(m) - g(n-1)) : 0);
        else
            printf("%d\n", fun(n));
    }
    return 0;
}
