#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
#define FNAME ""
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 7;
const ll LLINF = 1e18 + 7;


int main() {
    io;
    // freopen(FNAME".in", "r", stdin);
    // freopend(FNAME".out", "w", stdout);
    int n; cin >> n;
    // map<string, ld> mp;
    vector<pii> v;
    int at;
    string s;
    int i = 0;
    map<string, int> mp;
    while (cin >> s) {
        int p1, p2, r1, r2, f;
        cin >> p1 >> p2 >> r1 >> r2 >> f;
        ld val = 0.56*r2 + 0.24*r1 + 0.14*p2 + 0.06*p1 + 0.3*f;

        v.push_back({val, i});
        mp[s] = i;
        ++i;
    }
    sort(v.begin(), v.end(), greater<pii>());
    for (int j=0; j<v.size(); ++j) {
        if (v[j].second == mp["Taiwan"]) at = j;
    }
    cout << (n/v.size()) + (at < n % v.size());
    return 0;
}
/*
17
Japan 500 95 40 30 5
Vietnam 400 50 150 40 20
Indonesia 700 25 80 35 20
Taiwan 200 30 100 35 1
Korea 600 100 100 70 0
Philippines 50 10 40 15 15

16
Japan 500 95 40 30 5
Taiwan 200 30 100 35 1
Indonesia 700 25 80 35 20
Philippines 50 10 40 15 15
Korea 600 100 100 70 0
Vietnam 400 50 150 40 20
*/