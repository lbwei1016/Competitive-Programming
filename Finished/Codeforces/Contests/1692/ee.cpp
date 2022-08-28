#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    io;
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> v(n);
        for (int i=0; i<n; ++i) cin >> v[i];

        int l = -1, r = 0, sum = 0, mx = 0;
        while (l<r) {
            while (r<n && sum<=s) {
                if (sum == s && v[r] == 1) break;
                sum += v[r++];
            }
            if (sum == s)
                mx = max(mx, r-l-1);
            sum -= v[++l];
        }
        if (mx == 0) mx = n+1;
        cout << n-mx << '\n';
    }
    return 0;
}