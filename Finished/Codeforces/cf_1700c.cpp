#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    io;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i=0; i<n; ++i) cin >> a[i];
        ll sum = 0, diff = 0;
        for (int i=1; i<n; ++i) {
            ll d = a[i] - a[i-1];
            if (d > 0) {
                diff -= d;
            }
            sum += abs(d);
        }
        sum += abs(a.back() + diff);
        cout << sum << '\n';
    }
    return 0;
}