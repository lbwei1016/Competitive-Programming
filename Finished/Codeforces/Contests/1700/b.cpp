#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve(vector<int> &p, vector<int> &res, int n) {
    set<int> S;
    for (int i=1; i<=n; ++i) S.insert(i);
    for (int i=1; i<=n; ++i) {
        if (p[i] != *S.begin()) {
            res[i] = *S.begin();
            S.erase(S.begin());
        }
        else {
            if (S.size() > 1) {
                auto it = ++S.begin();
                res[i] = *it;
                S.erase(it);
            }
            else {
                res[i] = res[i-1];
                res[i-1] = *S.begin();
            }
        }
    }
}

int main() {
    io;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> p(n+1), res(n+1);
        for (int i=1; i<=n; ++i) cin >> p[i];
        if (n == 1) {
            cout << "-1\n";
            continue;
        }
        solve(p, res, n) ;
        for (int i=1; i<=n; ++i) {
            cout << res[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}