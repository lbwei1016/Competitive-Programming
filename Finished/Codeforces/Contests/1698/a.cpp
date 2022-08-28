#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    io;
    int t; 
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; ++i) cin >> a[i];

        bool good = false;
        for (int i=0; i<n; ++i) {
            int x = 0;
            for (int j=0; j<n; ++j) {
                if (i == j) continue;
                x ^= a[j];
            }
            if (x == a[i]) {
                cout << x << '\n';
                break;
            }
        }
    }
    return 0;
}