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
const ld EPS = 1e-8;

string S;
int dig = 100;
char z = '0';

int main() {
    io;
    // freopen(FNAME".in", "r", stdin);
    // freopend(FNAME".out", "w", stdout);
    cin >> S;
    if (S[0] == z) {
        cout << "1";
        return 0;
    } 
    dig = min(dig, (int)S.size());
    ld val6 = 0, cnt = 1;
    for (int i=0; i<dig; ++i) {
        val6 += (S[i] - z) * cnt;
        cnt /= 10.0;
    }
    ld lg6 = log10(val6);
    // cout << lg6 << endl;
    ld res = (S.size() + lg6 - 1)/ log10(6);
    // cout << "origi: " << res << '\n';
    ld ans = ceil(res);
    // cout << "ceil: " << res << '\n';
    
    if (ans - res < EPS) ans += 1.0;
    cout << (ll)ans;
    // cout << ((ll)res);
    // cout << val6;
    return 0;
}