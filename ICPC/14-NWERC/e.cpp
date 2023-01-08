#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;
using ld = long double;

ll n;
ld p, s, v;
ld c, tt, mn;
bool cal(ld t) {
    c = s / (v * t - s);
    tt = n * pow(__lg(n), c * sqrt(2));
    if (t + tt / (p * 1e9) < mn) {
        mn = t + tt / (p * 1e9);
        return true;
    }
    else return false;
}

int main() {
    io;
    cin >> n >> p >> s >> v;

    ld lb = s / v, ub = 1e60;
    ld cc;
    mn = ub;
    for (int i=0; i<1000; ++i) {
        ld mid = (lb + ub) / 2;
        if (cal(mid)) {
            ub = mid;
            cc = c;
        }
        else lb = mid;
    }
    cout << mn << '\n';
    cout << cc << '\n';
    return 0;
}