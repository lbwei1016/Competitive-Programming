#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

bool cmp(pair<char, int> p1, pair<char, int> p2) {
    return p1.second < p2.second;
}

void solve() {
    string s; 
    ll p, sum = 0; 
    cin >> s >> p;

    int n = s.size();
    vector<pair<char, int>> v(n);
    for (int i=0; i<n; ++i) {
        v[i] = {s[i], i};
        sum += s[i] - 'a' + 1;
    }

    sort(v.begin(), v.end());

    while (sum > p) {
        sum -= (v.back().first-'a' + 1);
        v.pop_back();
    }

    sort(v.begin(), v.end(), cmp);
    for (auto x: v) {
        cout << x.first;
    }
    cout << '\n';
}

int main() {
    io;
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}