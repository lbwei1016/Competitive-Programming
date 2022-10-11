#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    // io;
    int n, t;
    cin >> n >> t;
    vector<ll> h(n+1), ans(n+1);
    ll cul = 0, diffcul = 0, pmx = 0;
    ll ppmx = 0;
    for (int i=1; i<=n; ++i) cin >> h[i];
    h[0] = h[1];
    for (int i=1; i<=n; ++i) {
        int tt = t - cul;
        // cout  << "tt: " << tt << '\n';
        if (tt <= 0) {
            cout << "1\n";
            // cul += h[i];
            continue;
        }

        pmx = max(pmx, h[i]);
        int at = tt / (pmx);

        if (h[i] <= tt % pmx) at++;

        ++at;
        // ans[i] = at;
        cout << at << '\n';
        // printf("at: %lld,  mm: %d\n", at, tt % pmx);
        cul += h[i];   
    }
    return 0;
}
/*
5 1000000000
5553
2186
3472
2605
1790

*/