#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;
using ld = long double;

const ld EPS = 1e-8;
ll n;
ld p, s, v, sdv;
ld lglgn, lgsdv, alpha, sq2, A;
ld k;
bool cal(ld c) {
    // ld x = c * sq2 * lglgn + 2 * log2(c);
    ld x = pow(k, c) * c * c;
    return (x * (ld(n) * lglgn * sq2 * v) - A) > EPS;
}

int main() {
    io;
    cin >> n >> p >> s >> v;
    // sdv = s / v;
    lgsdv = log2(s) - log2(v);
    // alpha = n / (p * 1e9);
    lglgn = log2(log2(n));
    cout << "lglgn: " << lglgn << '\n';
    sq2 = sqrt(2);
    // A = lgsdv - log2(alpha * sq2 * lglgn);
    k = pow(log2(n), sq2);
    A = s * p * 1e9;

    ld lb = 1e-7, ub = 40000.000000;
    ld mn = 1e60, cc = ub;
    for (int i=0; i<100; ++i) {
        ld mid = (lb + ub) * 0.5;
        // cout << fixed << setprecision(10) << "lb: " << lb << ' ' << "ub: " << ub << '\n';
        // cout << fixed << setprecision(10) << "mid: " << mid << '\n';
        if (cal(mid)) ub = mid;
        else lb = mid;
        // cout << "val: " << mid * sq2 << '\n';
        // ld val = alpha * pow(log2(n), mid * sq2) + sdv + sdv / mid;
        // if (val < mn) {
        //     mn = val;
        //     cc = mid;
        // }
        if ((v * cc * mid * n * (pow(k, cc) - pow(k, mid)) - p * 1e9 * s * (cc - mid)) > EPS) {
            cc = mid;
        }
    }
    // cout << fixed << setprecision(10) << mn << '\n';
    cout << fixed << setprecision(10) << cc << '\n';
    return 0;
}