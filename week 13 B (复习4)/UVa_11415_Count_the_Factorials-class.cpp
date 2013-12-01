#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 3000000;

class CountTheFactorials {
private:
    bitset <MAXN> prime;
    vector <int> facts;
    int n, ans;
public:
    void genPrime();
    void init();
    void process();
};
void CountTheFactorials::init() {
    facts.resize(MAXN);
    prime.set();
    prime[0] = 0;
    prime[1] = 0;
    genPrime();  // generate prime numbers
    for (int i = 2; i < MAXN; i++)
        facts[i] += facts[i - 1];
}
void CountTheFactorials::genPrime() {
    for (int i = 2; i < MAXN; i++) {
        if (prime[i]) {
            facts[i] = 1;
            for (int j = i << 1; j < MAXN; j += i) {
                prime[j] = 0;
                for (int k = j; k % i == 0; k /= i)
                    facts[j]++;
            }
        }
    }
}
void CountTheFactorials::process() {
    cin >> n;
    ans = (int)(upper_bound(facts.begin(), facts.end(), n) - facts.begin());
    cout << ans << endl;
}

int main() {
    CountTheFactorials ctf;
    int nCase;
    ctf.init();
    cin >> nCase;
    while (nCase--) {
        ctf.process();
    }
    return 0;
}
