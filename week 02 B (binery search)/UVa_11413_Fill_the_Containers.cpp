#include <iostream>
 
using namespace std;
 
int n, m, c[1100];
 
bool simul(int cap)
{
    int tot = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] > cap) return false;
        if (cur + c[i] > cap) cur = 0;
        if (cur == 0) tot++;
        cur += c[i];
        if (tot > m) return false;
    }
    return true;
}
 
int main()
{
	while (cin >> n >> m) {
        for (int i = 0; i < n; i++)
			cin >> c[i];
 
        int high = 1000000000, low = 0;
        while (high - low > 0) {
            if (simul(high)) {
                high = low + (high - low) / 2;
            } else {
                low = high;
                high = high + high / 2;
            }
        }
		cout << high+1 << endl;
    }
    return 0;
}