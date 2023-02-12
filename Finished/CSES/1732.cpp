#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int P = 1e9 + 7, B = 31, N = 1e6 + 5;
string s;
ll ppow[N];

int main() {
    io;
    cin >> s;
    ppow[0] = 1;
    for (int i = 1; i < N; ++i) ppow[i] = ppow[i - 1] * B % P;

    ll pre = 0, suf = 0;
    vector<int> res;
    for (int len = 1, i = 0, j = s.size() - 1; len < s.size(); ++len, ++i, --j) {
        pre += (s[i] - 'a' + 1) * ppow[i]; pre %= P;
        suf *= B; suf %= P; 
        suf += (s[j] - 'a' + 1); suf %= P;
        // cout << pre << ' ' << suf << '\n';
        if (pre == suf) res.push_back(len);
    }
    for (auto x: res) cout << x << ' ';
    return 0;
}