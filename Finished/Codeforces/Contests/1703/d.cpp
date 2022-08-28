#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    // multiset<string> S;
    unordered_map<string, vector<int>> mp;
    for (int i=0; i<n; ++i) {
        string t; cin >> t;
        // S.insert(t);
        mp[t].push_back(i);
    }

    vector<bool> res(n);
    for (auto p: mp) {
        string s = p.first;
        bool good = false;
        for (int j=1; j<s.size(); ++j) {
            string hd(s.begin(), s.begin()+j);
            string ta(s.begin()+j, s.end());
            if (mp.count(hd) && mp.count(ta)) {
                for (auto &x: mp[s]) {
                    res[x] = 1;
                }
                good = true;
                break;
            }
        }
        if (!good) {
            for (auto &x: mp[s]) {
                res[x] = 0;
            }
        }
    } 
    for (auto x: res) cout << x;
    cout << '\n';
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}