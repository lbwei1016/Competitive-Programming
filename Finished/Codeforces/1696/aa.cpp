#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    io;
    int t;
    cin >> t;
    while (t--) {
        int n, z;
        cin >> n >> z;
        vector<int> v(n+1);
        int sum = 0;
        for (int i=1; i<=n; ++i) {
            cin >> v[i];
            v[i] |= z;
            sum = max(sum, v[i]);
        }
        // sum |= z;
        cout << sum << '\n';
    }    
    return 0;
}