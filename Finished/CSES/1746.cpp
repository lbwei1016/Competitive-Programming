#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 1e5 + 5, M = 105;
const int MOD = 1e9 + 7;
int n, m;
vector<int> v;
ll dp[N][M];

ll rec(int d, int pre) {
    if (pre > m && d > 0) return 0;
    if (d == n) return 1;
    if (v[d] != 0) {
        if (abs(pre - v[d]) > 1) return 0;

        if (dp[d][v[d]] == -1) dp[d][v[d]] = rec(d + 1, v[d]);
        return dp[d][v[d]];
    }

    ll res = 0;
    if (pre > 1) {
        if (dp[d][pre - 1] == -1) dp[d][pre - 1] = rec(d + 1, pre - 1);
        res += dp[d][pre - 1];
        res %= MOD;
    }

    if (dp[d][pre] == -1) dp[d][pre] = rec(d + 1, pre);
    res += dp[d][pre];    
    res %= MOD;

    if (dp[d][pre + 1] == -1) dp[d][pre + 1] = rec(d + 1, pre + 1);
    res += dp[d][pre + 1];
    res %= MOD;

    return res;
}

int main() {
    io;
    cin >> n >> m;
    v.resize(n);
    memset(dp, -1, sizeof(dp));
    for (int i=0; i<n; ++i) cin >> v[i];    
    ll res = 0;
    if (v[0] == 0) {
        if (m == 1) res = rec(0, 1);
        else {
            for (int i=2; i<m+2; i+=3) {
                res += rec(0, i);
            }
        }
        res %= MOD;
    }
    else res = rec(0, v[0]);
    cout << res << '\n';
    return 0;
}