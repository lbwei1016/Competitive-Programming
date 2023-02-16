#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

// do double hash
const int N = 5005;
unordered_map<ll, ll> S;
ll powB[N], preHash[N], powINV[N];
ll powB2[N], preHash2[N], powINV2[N];
ll dp[N];

void precalc(string &s, ll pow[], ll pre[], ll INV[], const int &P, const int &B) {
    pow[0] = INV[0] = 1;
    for (int i=1; i<N; ++i) pow[i] = pow[i - 1] * B % P;
    for (int i=2; i<N; ++i) INV[i] = INV[i - 1] * INV[1] % P;

    int len = s.size();
    for (int i=0; i<len; ++i) {
        pre[i + 1] = pre[i] + (s[i] - 'a' + 1) * pow[i];
        pre[i + 1] %= P;
    }
}

ll strHash(string &s, const int &P, ll pow[]) {
    ll sh = 0;
    for (int i=0; i<s.size(); ++i) {
        sh += (s[i] - 'a' + 1) * pow[i];
        sh %= P;
    }
    return sh;
}

// [st, ed)
ll rec(int st, int ed, const int &P1, const int &P2) {
    if (st == ed) return 1;
    if (dp[st] != -1) return dp[st];

    dp[st] = 0;
    int len = ed - st;
    for (int i=1; i<=len; ++i) {
        ll shh = (preHash[ed] - preHash[st + i] + P1) * powINV[st + i] % P1;
        ll sh = (preHash[st + i] - preHash[st] + P1) * powINV[st] % P1;

        auto it = S.find(sh);
        if (it != S.end()) {
            ll sh2 = (preHash2[st + i] - preHash2[st] + P2) * powINV2[st] % P2;
            if (it->second != sh2) continue;
            dp[st] += rec(st + i, ed, P1, P2);
            dp[st] %= P1;
        }
    }
    return dp[st];
}

int main() {
    io;
    const int P1 = 1e9 + 7, B1 = 37; powINV[1] = 621621626;
    const int P2 = 998244353, B2 = 31; powINV2[1] = 128805723;

    string str;
    int k;
    cin >> str >> k;

    precalc(str, powB, preHash, powINV, P1, B1);
    precalc(str, powB2, preHash2, powINV2, P2, B2);

    for (int i=0; i<k; ++i) {
        string s; cin >> s;
        S.insert({strHash(s, P1, powB), strHash(s, P2, powB2)});
    }

    memset(dp, -1, sizeof(dp));
    rec(0, str.size(), P1, P2);
    cout << dp[0] << '\n';
    return 0;
}