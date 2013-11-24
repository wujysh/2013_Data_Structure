#include <iostream>
#include <cmath>
using namespace std;
 
unsigned int s[31270];
 
void init()
{
    unsigned int a = 1;
    s[1] = 1;
    for(int i = 2; i < 31270; i++)
    {
        a += (int)log10((double)i) + 1;
        s[i] = s[i-1] + a;
    }
}
 
int search(int n)
{
    int i = 1, length = 0;
 
    while (s[i] < n) i++;
 
    int pos = n - s[i-1];
 
    for (i = 1; length < pos; i++) {
        length += (int)log10((double)i) + 1;
    }

    return ((i-1) / (int)pow((double)10, length - pos)) % 10;
}
 
int main()
{
    unsigned int n;
    init();
    int t;
	cin >> t;
    while (t--) {
        cin >> n;
        cout << search(n) << endl;
    }
    system("pause");
    return 0;
}