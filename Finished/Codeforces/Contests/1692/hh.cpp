/*
***DP***
    This is problem is equivalent to "Maximum Subarray Problem".
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

struct P {
    int val, l;
};

int main() {
    io;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, vector<int> > mp;
        for (int i=0; i<n; ++i) {
            int k; cin >> k;
            mp[k].push_back(i);
        }

        int mx = 0, a, l ,r;
        for (auto &p: mp) {
            auto &v = p.second;
            vector<P> dp(v.size());
            dp[0] = {.val=1, .l=v[0]};
            if (dp[0].val > mx) {
                mx = dp[0].val;
                a = p.first;
                l = dp[0].l + 1;
                r = v[0] + 1;
            }
            for (int i=1; i<v.size(); ++i) {
                if (dp[i-1].val - (v[i]-v[i-1]-1) + 1 > dp[i].val) {
                    dp[i] = {.val=dp[i-1].val - (v[i]-v[i-1]-1) + 1, .l=dp[i-1].l};
                }
                else dp[i] = {.val=1, .l=v[i]};
                if (dp[i].val > mx) {
                    mx = dp[i].val;
                    a = p.first;
                    l = dp[i].l + 1;
                    r = v[i] + 1;
                }
            }
        }
        cout << a << ' ' << l << ' ' << r << '\n';
    }
    return 0;
}