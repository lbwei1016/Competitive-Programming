#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 105;
int n, m;
int dp[N][N][2]; // dp[d][eat][pre]: 當下決定要不要吃 d-th 食物、已經連續吃 eat 個食物、上一次有沒有吃 = [pre == 1]
int fd[N], app[N];
int mx;

int rec(int d, int eat, int pre) {
    if (d == n) return 0;
    if (eat < 0) eat = 0;
    if (dp[d][eat][pre] != -1) return dp[d][eat][pre];

    // eat
    int res1 = min(fd[d], app[eat]) + rec(d+1, eat+1, 1);

    // don't eat
    int res2;
    if (pre == 0) {
        res2 = rec(d+1, 0, 0);
    }
    else {
        res2 = rec(d+1, eat-1, 0);
    }
    dp[d][eat][pre] = max(res1, res2);
    mx = max(mx, dp[d][eat][pre]);
    return dp[d][eat][pre];
}

int main() {
    io;
    cin >> n >> m;
    for (int i=0; i<n; ++i) cin >> fd[i];
    memset(dp, -1, sizeof(dp));
    app[0] = m;
    for (int i=1; i<n; ++i) app[i] = app[i-1]*2 / 3;

    rec(0, 0, 0);

    cout << mx << '\n';

    return 0;
}

/*
5 900
800 700 400 300 200

Ans: 2243

5 900
800 700 40 300 200

Ans: 1900
*/