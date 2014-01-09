#include <iostream>
#include <cmath>
using namespace std;

bool prime[1000000], almost[1000000];

bool isPrime(int p)
{      
	if (p == 0 || p == 1) return false;
	for (int i = 2; i <= sqrt((double)p); i++)
		if (p % i == 0)
			return false;
	return true;      
}

void init()
{
	for (int i = 0; i < 1000000; i++)
		prime[i] = isPrime(i);
}

int main()
{
	init();
	int N, low[600], high[600], lowest = 1000000, highest = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> low[i] >> high[i];
		if (high[i] > highest) highest = high[i];
		if (low[i] < lowest) lowest = low[i];
	}

	for (int i = lowest; i <= highest; i++)
		if (!prime[i]) {
			bool flag = true;
			int count = 0;
			for (int j = 2; j < i; j++)
				if (prime[j])
					if (i % j == 0) {
						count++;
						if (count > 1) {
							flag = false;
							break;
						}
					}
			almost[i] = flag;
		}
	almost[0] = false;
	almost[1] = false;
	for (int i = 0; i < N; i++) {
		int count = 0;
		for (int j = low[i]; j <= high[i]; j++)
			if (almost[j])
				count++;
		cout << count << endl;
	}
	system("pause");
	return 0;
}