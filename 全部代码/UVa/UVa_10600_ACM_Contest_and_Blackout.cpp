#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 110;
const int INF = 1 << 30;

struct edge {
    int a, b, len, no;
    bool enabled;
    friend bool operator < (const edge a, const edge b) {
        return a.len > b.len;
    }
};

class ACMContestAndBlackout {
private:
    int root[MAXN], used[MAXN];
    int ans1, ans2;
    int n, m;
    priority_queue <edge> q;
    edge M[MAXN*MAXN];
public:
    void init();
    void input();
    void work();
    int findroot(int x) {
        return root[x] == x ? x : root[x] = findroot(root[x]);
    }
    int MST();
    void output();
};
void ACMContestAndBlackout::init() {
    ans1 = ans2 = 0;
    while (!q.empty()) q.pop();
}
void ACMContestAndBlackout::input() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        edge e;
        cin >> e.a >> e.b >> e.len;
        e.enabled = true;
        e.no = i;
        q.push(e);
        M[i] = e;
    }
}
int ACMContestAndBlackout::MST() {
    int sum = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        root[i] = i;
    }
    while (!q.empty()) {
        edge e = q.top();
        q.pop();
        if (e.enabled && findroot(e.a) != findroot(e.b)) {
            root[findroot(e.a)] = findroot(e.b);
            sum += e.len;
            used[cnt] = e.no;
            cnt++;
        }
    }
    if (cnt < n - 1) return INF;
    else return sum;
}
void ACMContestAndBlackout::work() {
    ans1 = MST();

    int min = INF;
    int eageOnMST[MAXN];
    for (int i = 0; i < n - 1; i++) {
        eageOnMST[i] = used[i];
    }
    for (int i = 0; i < n - 1; i++) {
        M[eageOnMST[i]].enabled = false;
        while (!q.empty()) q.pop();
        for (int j = 0; j < m; j++) {
            q.push(M[j]);
        }
        int secondMST = MST();
        if (secondMST < min) {
            min = secondMST;
        }
        M[eageOnMST[i]].enabled = true;
    }
    ans2 = min;
}
void ACMContestAndBlackout::output() {
    cout << ans1 << " " << ans2 << endl;
}

int main() {
    int nCase;
    ACMContestAndBlackout acab;
    cin >> nCase;
    while (nCase--) {
        acab.init();
        acab.input();
        acab.work();
        acab.output();
    }
    return 0;
}
