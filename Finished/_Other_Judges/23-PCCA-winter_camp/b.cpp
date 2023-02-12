#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 1e5 + 5, M = 105;

int n, m;
vector<int> a(N), b(N);
ll dp[N][M];
ll rec(int d, int tok) {
    if (d == n) return 0;
    // ll res = max(rec(d + 1, min(m, tok + a[d])), rec(d + 1, tok - b[d]) + b[d]);
    if (dp[d][tok] > 0) return dp[d][tok];
    if (tok < b[d]) dp[d][tok] = rec(d + 1, min(m, tok + a[d]));
    else {
        dp[d][tok] = max(dp[d][tok], max(rec(d + 1, min(m, tok + a[d])), rec(d + 1, tok - b[d]) + b[d]));
    }
    return dp[d][tok];
}

int main() {
    io;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for (int i=0; i<n; ++i) cin >> a[i];
    for (int i=0; i<n; ++i) cin >> b[i];
    cout << rec(0, 0) << '\n';
    return 0;
}