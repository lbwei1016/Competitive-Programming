#include <bits/stdc++.h>
// #define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

ll pow(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}

int main() {
    // io;
    freopen("boolean.in", "r", stdin);
    freopen("boolean.out", "w", stdout);
    // string s;
    // cin >> s;
    char s[2000];
    scanf("%s", s);

    ll dual = 0, els = 0;
    int mp[1000] = {0}, pos = 0, n = strlen(s);
    for (int i=0; i<n; ++i) {
        char c = s[i];
        if (c == '~') {
            pos = 300;
            continue;
        }
        else if (c == '|') continue;
        mp[pos + (int)c] = 1;
        pos = 0;
    }

    ll k = 1;
    string tab;
    for (int i=0; i<26; ++i) {
        tab += ('a' + i);
        tab += ('A' + i);
    }
    for (int i=0; i<52; ++i) {
        int r = (int)tab[i];
        if (mp[r] && mp[300+r]) {
            k *= 2;
            dual++;
        }
        else if (mp[r] || mp[300+r]) els++;
    }

    // if (els > 0) {
        if (k == 1)
            k *= (pow(2LL, els) - 1);
        else k *= pow(2LL, els);
    // }
    printf("%lld", k);
    // cout << dual << ' ' << els;

    return 0;
}