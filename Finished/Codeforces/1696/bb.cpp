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
        vector<int> v(n+1);
        for (int i=1; i<=n; ++i) cin >> v[i];
        v.push_back(0);
        int pre = v[1], cnt = 0;
        for (int i=2; i<=n+1; ++i) {
            // int s; cin >> s;
            if (pre != 0 && v[i] == 0) {
                cnt++;
            }
            pre = v[i];
        }
        // if (n == 1 && pre != 0) cnt = 1;
        cout << min(cnt, 2) << '\n';
    }    
    return 0;
}