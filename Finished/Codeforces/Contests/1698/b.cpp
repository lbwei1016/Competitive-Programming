#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    io;
    int t; 
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i=0; i<n; ++i) cin >> v[i];
        int ans = 0;
        if (k == 1) ans = (n-1) / 2;
        else {
            for (int i=1; i<n-1; ++i) {
                if (v[i] > v[i-1]+v[i+1]) ++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}