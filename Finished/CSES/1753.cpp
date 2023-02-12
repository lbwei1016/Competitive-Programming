#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 1e6 + 5, P = 1e9 + 7, B = 31;
ll powB[N], pre_hash[N];

int main() {
    io;
    string s, t; 
    cin >> s >> t;
    powB[0] = 1;
    for (int i=1; i<N; ++i) powB[i] = powB[i - 1] * B % P;
    ll thash = 0;
    for (int i=0; i<t.size(); ++i) {
        thash += powB[i] * (t[i] - 'a' + 1);
        thash %= P;
    }
    // cout << thash << '\n';

    pre_hash[0] = 0;
    for (int i=0; i<s.size(); ++i) {
        pre_hash[i + 1] = pre_hash[i] + (s[i] - 'a' + 1) * powB[i];
        pre_hash[i + 1] %= P;
        // printf("pre_hash[%d]: %d\n", i + 1, pre_hash[i + 1]);   
    }

    ll par_hash = 0, cnt = 0;
    for (int i=0; t.size()+i <= s.size(); ++i) {
        par_hash = (pre_hash[t.size() + i] - pre_hash[i] + P) % P;
        // cout << "par_hash: " << par_hash << '\n';
        if (par_hash == thash) ++cnt;
        thash = thash * B % P;
    }
    cout << cnt << '\n';
    return 0;
}