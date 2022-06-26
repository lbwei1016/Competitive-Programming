#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 2e5+5;
ll dp[N][2];

int main() {
    // io;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> s(n);
        for (int i=0; i<n; ++i) scanf("%1d", &s[i]);
        memset(dp, 0, sizeof(dp));
        ll cnt = ++dp[0][s[0]];
        for (int i=1; i<n; ++i) {
            dp[i][s[i]] = dp[i-1][s[i]];
            dp[i][s[i]]++;
            if (s[i-1] ^ s[i]) {
                dp[i][s[i]] += dp[i-1][s[i]^1];
                cnt += dp[i][s[i]];
            }
            else cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}