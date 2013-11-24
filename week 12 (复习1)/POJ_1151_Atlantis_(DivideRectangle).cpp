#include <cstdio>
#include <algorithm>
using namespace std;

double a1[122], b1[122], a2[122], b2[122];
double t1[222], t2[222];

int main() {
    int n, cnt, cas = 0;
    while (scanf("%d", &n) != EOF && n) {
        cnt = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf%lf%lf", &a1[i], &b1[i], &a2[i], &b2[i]);
            t1[cnt] = a1[i];
            t2[cnt] = b1[i];
            cnt++;
            t1[cnt] = a2[i];
            t2[cnt] = b2[i];
            cnt++;
        }
        sort(t1, t1 + cnt);
        sort(t2, t2 + cnt);
        double ans = 0;
        for (int i = 0; i < cnt - 1; i++) {
            for (int j = 0; j < cnt - 1; j++) {
                for (int k = 0; k < n; k++) {
                    if (t1[i] >= a1[k] && t2[j] >= b1[k] && t1[i + 1] <= a2[k] && t2[j + 1] <= b2[k]) {
                        ans += (t1[i + 1] - t1[i]) * (t2[j + 1] - t2[j]);
                        break;
                    }
                }
            }
        }
        printf ("Test case #%d\n", ++cas);
        printf ("Total explored area: %.2f\n\n", ans);
    }
    return 0;
}
