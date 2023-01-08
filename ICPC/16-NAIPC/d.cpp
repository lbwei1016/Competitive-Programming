#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const double INF = 1e60;
struct P {
    ll s, p, par;
};

int main() {
    io;
    int n, k; cin >> k >> n;
    vector<P> emp(n + 1);
    for (int i=1; i<=n; ++i) {
        ll s, p, par;
        cin >> s >> p >> par;
        emp[i] = P{s, p, par};
    }

    // dp[u][j]: rooted at 'u', choose 'j' events
    vector<vector<double>> dp(n + 1);
    double lb = 0, ub = 2.5e7;
    // do sufficient many times
    for (int t=0; t<50; ++t) {
        auto check = [&](double mid)->bool {
            vector<int> sz(n + 1, 1);
            // init
            for (int i=0; i<=n; ++i) {
                auto &e = emp[i];
                dp[i] = vector<double>(2);
                dp[i][0] = 0;
                dp[i][1] = e.p - mid * e.s;
            }

            // from 'n' to '1'
            for (int v=n; v>=1; --v) {
                auto &e = emp[v];
                // 'f' is for calculating
                vector<double> f(sz[e.par] + sz[v] + 1, -INF);
                f[0] = 0;
                // DP on a tree 
                // 父節點編號保證較小，所以可以直接跑迴圈，而不建樹
                for (int i=1; i<=sz[e.par]; ++i) {
                    for (int j=0; j<=sz[v]; ++j) {
                        f[i + j] = max(f[i + j], dp[e.par][i] + dp[v][j]);
                    }
                }
                dp[e.par].swap(f); // update
                // add up subtree size
                sz[e.par] += sz[v];
            }
            // "0" plus "k" employees => "k+1" in total
            return dp[0][k + 1] >= 0;
        };

        double mid = (lb + ub) / 2;
        if (check(mid)) {
            lb = mid;
        }
        else ub = mid;
    }

    cout << fixed << setprecision(3) << lb << '\n';
    return 0;
}