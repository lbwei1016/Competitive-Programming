/*
sol2: 看最大左界和最小右界
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 55;

bool solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> L(N, 0);
    for (int i=0; i<n; ++i) {
        int l, r; cin >> l >> r;
        if (l <= k && k <= r) {
            for (int j=l; j<=r; ++j) {
                L[j]++;
            }
            // if (l == r) L[l]--;
        }
    }
    int mx = L[k], who = k;
    for (int i=1; i<N; ++i) {
        if (i == k) continue;
        if (L[i] >= mx) {
            mx = L[i];
            who = i;
        }
    }
    // cout << "who: " << who << '\n';
    return (who == k);
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
/*
1
5 5
1 6
2 6
3 7
4 8
5 10
*/