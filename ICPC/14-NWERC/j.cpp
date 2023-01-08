#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    io;
    int n; cin >> n;
    map<string, int> mp1, mp2;
    for (int i=0; i<n; ++i) {
        string s; cin >> s;
        mp1[s]++;
    }
    for (int i=0; i<n; ++i) {
        string s; cin >> s;
        mp2[s]++;
    }
    
    int res = 0;
    for (auto p: mp1) {
        if (mp2.count(p.first)) {
            res += min(p.second, mp2[p.first]);
        }
    }
    cout << res << '\n';
    return 0;
}