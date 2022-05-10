#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int KMAX = 1e6+5, MOD = 998244353;
ll dp[KMAX][2][2]; // 1: 與 x0 (y0) 同
int dx[] = {0, 1, 0, 1}, dy[] = {1, 0, 0, 1};

ll fpow(ll x, ll n) {
    x %= MOD;
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res *= x;
            res %= MOD;
        }
        n >>= 1;
        x *= x;
        x %= MOD;
    }
    return res;
}
ll mod_inv (ll num) {
    return fpow(num, MOD-2);
}

int main() {
    // io;
    ll R, C, K;
    cin >> R >> C >> K;
    int x[2], y[2];
    cin >> x[0] >> y[0] >> x[1] >> y[1];

    // use matrix exp. to speed up
    dp[0][1][1] = 1;
    for (int k=1; k<=K; ++k) {
        dp[k][0][0] = 
            (((dp[k-1][0][1] * (C-1))%MOD + (dp[k-1][1][0] * (R-1))%MOD)%MOD + (dp[k-1][0][0]*(R-2 + C-2))%MOD)%MOD;
        dp[k][0][1] = 
            ((dp[k-1][0][0] + (dp[k-1][1][1] * (R-1))%MOD)%MOD + (dp[k-1][0][1] * (R-2))%MOD)%MOD;
        dp[k][1][0] += 
            ((dp[k-1][0][0] + (dp[k-1][1][1] * (C-1))%MOD)%MOD +( dp[k-1][1][0] * (C-2))%MOD)%MOD;
        dp[k][1][1] += 
            (dp[k-1][0][1] + dp[k-1][1][0])%MOD;
        for (int i=0; i<4; ++i) {
            dp[k][dx[i]][dy[i]] %= MOD;
        }
            
    }

    bool sx = x[0] == x[1], sy = y[0] == y[1];
    ll res;
    if (sx && sy) {
        res = dp[K][1][1];
    }
    else if (sx && !sy) {
        res = dp[K][1][0] * mod_inv(C-1);
    }
    else if (!sx && sy) {
        res = dp[K][0][1] * mod_inv(R-1);
    }
    else {
        res = dp[K][0][0] * mod_inv((R-1)*(C-1));
    }
    cout << res%MOD << '\n';
    return 0;
}