#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    io;
    int n; cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    ll res = 0;
    int at = 0;
    set<int> S;
    for (int i=0; i<n; ++i) {
        if (!S.count(v[i])) {
            S.insert(v[i]);
            at = v[i];
            continue;
        }
        // at = v[i];
        while (S.count(at)) ++at;
        S.insert(at);
        res += at - v[i];
    }
    cout << res << '\n';

    return 0;
}