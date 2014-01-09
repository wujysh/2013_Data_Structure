#include <iostream>
using namespace std;

#define N 50000
int phi[50001], result[50001];

void init()
{
	memset(phi, 0, sizeof(phi));
	phi[1] = 1;
	for (int i = 2; i <= N; i++)
		if (!phi[i])
			for (int j = i; j <= N; j += i) {
				if (!phi[j])
					phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
	result[0] = 0;
	for (int i = 1; i <= N; i++)
		result[i] = result[i-1] + phi[i];
}

int main()
{
	init();
	int n;
	while (cin >> n) {
		if (n == 0) break;
		cout << 2 * result[n] - 1 << endl;
	}
	system("pause");
	return 0;
}