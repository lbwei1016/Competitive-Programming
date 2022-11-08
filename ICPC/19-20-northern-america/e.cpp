#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const ll MOD = 11092019;

string s;

int main() {
    io;
    cin >> s;
    map<char, ll> mp;
    for (auto c: s) {
        mp[c]++;
    }
    ll res = 1;
    for (auto p: mp) {
        // cout << p.second << '\n';
        // res *= (1LL + p.second);
        // res %= MOD;
        res = (res % MOD) * ((1LL + p.second) % MOD) % MOD;
    }
    cout << res;
    return 0;
}