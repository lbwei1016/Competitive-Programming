#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    io;
    int n; cin >> n;
    ll mn = 1e18, who = 0;
    for (int i=1; i<=n; ++i) {
        ll c; string s;
        cin >> c >> s;
        map<int, int> mmp;
        for (auto x: s) {
            mmp[x]++;
        }
        if (mmp['0'] >= 1 && mmp['1'] >= 1 && mmp['2'] >= 2) {
            if (c < mn) {
                mn = c;
                who = i;
            }
        }
    }
    cout << who;
    return 0;
}