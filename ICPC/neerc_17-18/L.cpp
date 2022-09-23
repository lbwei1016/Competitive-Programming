#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    io;
    ll n; cin >> n;
    ll t = n, cnt = 0;
    int at = 1;
    vector<pair<int, vector<int>>> v;
    while (t > 2) {
        ll tmp = n;
        vector<int> fac;
        
        for (int i=t; i>1; --i) {
            if (n % i != 0) break;
            while (n % i == 0) {
                fac.push_back(i);
                n /= t;
            }
        }

        for (int i=t+1; i<=n; ++i) {
            if (n % i != 0) break;
            while (n % i == 0) {
                fac.push_back(i);
                n /= t;
            }        
        }

        if (n == 1) {
            v.push_back(make_pair(at, fac));
            ++cnt;
        }
        ++at;
        n = tmp;
        t = pow(n, 1.0/at);
        cout << "t: " << t << '\n';
    }
    cout << cnt << '\n';
    for (auto x: v) {
        cout << x.first << ' ';
        for (auto y: x.second) cout << y << ' ';
        cout << '\n';
    }
    return 0;
}