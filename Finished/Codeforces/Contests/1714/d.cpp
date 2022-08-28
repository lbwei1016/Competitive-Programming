#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

struct P {
    string s;
    int id;
    bool operator<(P p) const {
        return s.size() > p.s.size();
    }
};

bool find(int st, string s, string sub) {
    if (st + sub.size() > s.size()) return 0;
    string ss(s.begin()+st, s.begin()+st+sub.size());
    return (sub == ss);
}

vector<pair<int, int>> res;

bool solve() {
    res.clear();
    string s; cin >> s;
    int n; cin >> n;
    vector<P> v(n);
    for (int i=0; i<n; ++i) {
        cin >> v[i].s;
        v[i].id = i;
    }
    sort(v.begin(), v.end());
    int at = 0;
    while (true) {
        int mx = 0, who, from;
        for (auto x: v) {
            for (int i=0; i<=at; ++i) {
                int k = find(i, s, x.s);
                if (k && i+x.s.size() > mx) {
                    mx = i + x.s.size();
                    who = x.id;
                    from = i;
                }
            }
        }
        if (mx <= at) return false;
        at = mx;
        res.push_back({who+1, from+1});
        if (at == s.size()) break;
    }
    return true;
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        bool ans =  solve();
        if (!ans) cout << "-1\n";
        else {
            cout << res.size() << '\n';
            for (auto p: res) {
                cout << p.first << ' ' << p.second << '\n';
            }
        }
    }
    return 0;
}