#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 100010;

struct Calf {
    int score;
    int aid;
    friend bool operator<(Calf c1, Calf c2) {
        return c1.score > c2.score;
    }
};

class MooUniversityFinancialAid {
private:
    int numOfAdmit, numOfCalves, totalMoney, maxMedianScore;
    int aidOfHighScore[MAXN], aidOfLowScore[MAXN];
    vector <Calf> calf;
public:
    void init(int, int, int);
    void input();
    void genAidOfHighScore();
    void genAidOfLowScore();
    void work();
    void output();
};
void MooUniversityFinancialAid::init(int n, int c, int f) {
    numOfAdmit = n;
    numOfCalves = c;
    totalMoney = f;
    maxMedianScore = -1;
    calf.clear();
}
void MooUniversityFinancialAid::input() {
    for (int i = 0; i < numOfCalves; i++) {
        Calf c;
        scanf("%d%d", &c.score, &c.aid);
        calf.push_back(c);
    }
}
void MooUniversityFinancialAid::genAidOfHighScore() {
    priority_queue <int> qHigh;
    int sum = 0, aid;
    for (int i = 0; i < numOfAdmit/2; i++) {
        aidOfHighScore[i] = sum;
        aid = calf[i].aid;
        qHigh.push(aid);
        sum += aid;
    }
    for (int i = numOfAdmit/2; i < numOfCalves; i++) {
        aidOfHighScore[i] = sum;
        aid = calf[i].aid;
        if (aid < qHigh.top()) {
            sum += aid - qHigh.top();
            qHigh.pop();
            qHigh.push(aid);
        }
    }
}
void MooUniversityFinancialAid::genAidOfLowScore() {
    priority_queue <int> qLow;
    int sum = 0, aid;
    for (int i = 0; i < numOfAdmit/2; i++) {
        aidOfLowScore[numOfCalves - 1 - i] = sum;
        aid = calf[numOfCalves - 1 - i].aid;
        qLow.push(aid);
        sum += aid;
    }
    for (int i = numOfAdmit/2; i < numOfCalves; i++) {
        aidOfLowScore[numOfCalves - 1 - i] = sum;
        aid = calf[numOfCalves - 1 - i].aid;
        if (aid < qLow.top()) {
            sum += aid - qLow.top();
            qLow.pop();
            qLow.push(aid);
        }
    }
}
void MooUniversityFinancialAid::work() {
    sort(calf.begin(), calf.end());
    genAidOfHighScore();
    genAidOfLowScore();
    int sum = 0;
    for (int i = numOfAdmit/2; i < numOfCalves-numOfAdmit/2; i++) {
        sum = calf[i].aid + aidOfHighScore[i] + aidOfLowScore[i];
        if (sum <= totalMoney) {
            maxMedianScore = calf[i].score;
            break;
        }
    }
}
void MooUniversityFinancialAid::output() {
    printf("%d\n", maxMedianScore);
}

int main() {
    MooUniversityFinancialAid mufa;
    int n, c, f;
    while (scanf("%d%d%d", &n, &c, &f) != EOF) {
        mufa.init(n, c, f);
        mufa.input();
        mufa.work();
        mufa.output();
    }
    return 0;
}
