#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int next(int x) {
    return x + x % 10;
}

bool solve() {
    int n; cin >> n;
    vector<int> v(n);
    bool flag5 = false;
    for (int i=0; i<n; ++i) {
        cin >> v[i];
        if (v[i] % 5 == 0) {
            v[i] = next(v[i]);
            flag5 = true;
        }
    }
    if (flag5) {
        return (*min_element(v.begin(), v.end()) == *max_element(v.begin(), v.end()));
    }
    else {
        bool flag2 = false, flag12 = false;
        for (int i=0; i<n; ++i) {
            int x = v[i];
            while (x % 10 != 2) x = next(x);
            if (x % 20 == 2) flag2 = true;
            else flag12 = true;
        }
        return !(flag2 && flag12);
    }
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        bool ans = solve();
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}