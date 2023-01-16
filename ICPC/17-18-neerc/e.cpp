#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int M = 1e6 + 5, INF = 1e9 + 7;

int main() {
    // io;
    freopen("equal.in", "r", stdin);
    freopen("equal.out", "w", stdout);
    int n; cin >> n;
    map<int, int> mp;
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        mp[x]++;
    }

    vector<int> x, y;
    // O(N logM)
    for (auto p: mp) {
        x.push_back(p.second);
        // 看某數的倍數是否存在
        for (int i=2 * p.first; i<M; i+=p.first) {
            // a multiple exists
            if (mp.count(i)) {
                y.push_back(p.second);
                break;
            }
        }
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    vector<int> dp(n + 1, mp.size());
    int sum = 0, all = mp.size();
    // multiple
    for (int i=0; i<y.size(); ++i) {
        sum += y[i];
        dp[sum] = min(dp[sum], all - i - 1);
    }
    sum = 0;
    // multiple & no multiple
    for  (int i=0; i<x.size(); ++i) {
        sum += x[i];
        dp[sum] = min(dp[sum], all - i);
    }
    
    cout << dp[0] << ' ';
    for (int i=1; i<=n; ++i) {
        dp[i] = min(dp[i], dp[i-1]);
        cout << dp[i] << ' ';
    }
    return 0;
}