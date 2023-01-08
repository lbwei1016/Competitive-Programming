#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int H = 105, N = 1e4 + 5;
const ll MOD = 1e9 + 7;
ll dp[H][N];

int main() {
    io;
    int n, h, w;
    cin >> n >> w >> h;
    dp[0][0] = 1;
    for (int i=1; i<=w; ++i) {
        for (int nn=0; nn<=n; ++nn) {
            for (int j=0; j<=h; ++j) {
                if (nn + j <= n) {
                    dp[i][nn + j] += dp[i - 1][nn];
                    dp[i][nn + j] %= MOD;
                }
                else break;
            }
        }
    }

    ll res = 0;
    for (int i=0; i<=n; ++i) {
        res += dp[w][i];
        res %= MOD;
    }
    res -= min(h, n / w) + 1;
    cout << res << '\n';
    return 0;
}