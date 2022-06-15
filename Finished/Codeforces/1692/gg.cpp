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
        int cnt = 0, st = 0;
        for (int i=0; i<n; ++i) {
            while (i+1<n && v[i]/double(v[i+1]) < 2) {
                // cout << v[i]/double(v[i+1]) << '\n';
                ++i;
                if (i-st == k) {
                    ++cnt;
                    ++st;
                }
            }
            st = i+1;
        }
        cout << cnt << '\n';
    }
    return 0;
}