#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 16, K = 16;
struct P {
    ll w, h, q;
};

ll dp[K][1 << N];

int main() {
    io;
    int n, k; cin >> n >> k;
    vector<P> cards(n);
    for (int i=0; i<n; ++i) {
        int w, h, q;
        cin >> w >> h >> q;
        cards[i] = P{w, h, q};
    }

    vector<ll> cost(1 << n);
    for (int S=1; S<(1<<n); ++S) {
        ll wmx = 0, hmx = 0;
        ll Q = 0, sum = 0;
        for (int i=0; i<n; ++i) {
            if ((S >> i) & 1) {
                wmx = max(wmx, cards[i].w);
                hmx = max(hmx, cards[i].h);
                Q += cards[i].q;
                sum += cards[i].w * cards[i].h * cards[i].q;
            }
        }
        cost[S] = wmx * hmx * Q - sum;
    }

    memset(dp, 0x7f, sizeof(dp));
    dp[0][0] = 0;

    for (int i=1; i<=k; ++i) {
        for (int S=1; S<(1<<n); ++S) {
            for (int ss=S; ss; ss=(ss-1)&S) {
                dp[i][S] = min(dp[i][S], dp[i-1][S^ss] + cost[ss]);
            }
        }
    }

    ll res = 0x7fffffff7fffffff;
    for (int i=1; i<=k; ++i) {
        res = min(res, dp[i][(1<<n) - 1]);
    }
    cout << res << '\n';
    return 0;
}