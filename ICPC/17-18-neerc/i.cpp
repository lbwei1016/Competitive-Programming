#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
    // io;
    freopen("intel.in", "r", stdin);
    freopen("intel.out", "w", stdout);
    int n;
    cin >> n;
    ll len = 0, prex, prey;
    cin >> prex >> prey;
    ll x1 = prex, y1 = prey;

    vector<ll> borx = {-INF, INF}, bory = {-INF, INF};
    for (int i=1; i<n; ++i) {
        ll x, y;
        cin >> x >> y;
        len += abs(x - prex) + abs(y - prey);
        prex = x;
        prey = y; 

        if (x > borx[0]) borx[0] = x;
        if (x < borx[1]) borx[1] = x;
        if (y > bory[0]) bory[0] = y;
        if (y < bory[1]) bory[1] = y;
    }
    len += abs(x1 - prex) + abs(y1 - prey);
    ll res = len - 2 * ((borx[0] - borx[1]) + (bory[0] - bory[1]));
    cout << res << '\n';
    return 0;
}