#include <iostream>
#include <cmath>
#define eps 1e-8
using namespace std;

int main() {
	int H, num, m, N;
	while (cin >> H >> num && (H || num)) {
		if (H == 1 && num == 1) {
			cout << "0 1" << endl;
			continue;
		}

		m = 1;
		while (H != int(pow(pow(num, 1.0/m) + 1.0, m) + eps)) m++;
		N = int(pow(num, 1.0/m) + eps);
		if (N != 1)
			cout << (1-num) / (1-N) << ' ' << (H-num) * (N+1) + num << endl;
		else
			cout << m << ' ' << (H-num) * (N+1) + num << endl;
	}
	return 0;
}
