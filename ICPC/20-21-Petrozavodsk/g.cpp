#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int n;
vector<ll> vec;

int main() {
    io;
    cin >> n;
    vec.resize(n);
    for (int i=0; i<n; ++i) {
        cin >> vec[i];
    }

    ll sum = 0;
    ll pre = 1;
    for (int i=0; i<n; ++i) {
        ll GCD = 0;
        for (int j=i; j<n; ++j) {
            GCD = __gcd(GCD, vec[j]);
            ll rat = pre / GCD;
            if (GCD == 1) break;

            // ll cnt = 0, tmp = GCD;
            // for (ll p=2, sq=sqrt(tmp); p<=sq; ++p) {
            //     while (tmp % p) {
            //         tmp /= p;
            //     }
            //     ++cnt;
            // }
            // sum += cnt;
        }
    }

    if ()
    return 0;
}