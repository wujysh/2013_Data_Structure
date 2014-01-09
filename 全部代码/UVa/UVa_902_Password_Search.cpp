#include <iostream>
#include <map>
#include <string>
using namespace std;

struct result {
    string s;
    int count;
    result() : count(0) {}
};

class PasswordSearch {
private:
    int n;
    string input;
    unsigned int hash;
    map <unsigned int, int> m;
    result best;
public:
    unsigned int jenkins_one_at_a_time_hash(const string&, int, int);
    void init(int, string);
    void work();
    void output();
};
unsigned int PasswordSearch::jenkins_one_at_a_time_hash(const string &input, int start, int n) {
    unsigned int hash = 0;
    for (int i = 0; i < n; i++) {
        hash += input[start + i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}
void PasswordSearch::init(int a, string b) {
    n = a;
    input = b;
    m.clear();
    best.count = 0;
}
void PasswordSearch::work() {
    for (int i = 0, sz = input.size(); i + n - 1 < sz; i++) {
        hash = jenkins_one_at_a_time_hash(input, i, n);
        if (m.find(hash) == m.end()) {
            m[hash] = 1;
        } else {
            m[hash] += 1;
        }
        if (m[hash] > best.count) {
            best.count = m[hash];
            best.s = string(input.begin() + i, input.begin() + i + n);
        }
    }
}
void PasswordSearch::output() {
    cout << best.s << endl;
}

int main(void) {
    int n;
    string input;
    PasswordSearch ps;
    while (cin >> n >> input) {
        ps.init(n, input);
        ps.work();
        ps.output();
    }
    return 0;
}
