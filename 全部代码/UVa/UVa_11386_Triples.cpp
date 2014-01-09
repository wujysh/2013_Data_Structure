#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int main() {
	long long n, num, ans;
	while (scanf("%lld", &n) != EOF) {
		map <long long, long long> m;
		m.clear();
		ans = 0;

		for (int i = 0; i < n; i++) {
			scanf("%lld", &num);
			m[num]++;
		}

		map <long long, long long>::iterator it, i, j;
		for (i = m.begin(); i != m.end(); i++) {
			for (j = i; j != m.end(); j++) {
				it = m.find(i->first + j->first);
				long long tmp = 0;
				if (i->first == j->first) {
					tmp += (i->second * (i->second - 1)) / 2;
				} else {
					tmp += (i->second * j->second);
				}
				if (it != m.end()) {
					ans += tmp * it->second;
				}
			}
		}

		printf("%lld\n", ans);
	}
	return 0;
}