#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    int m, n;
    double r;
    cin >> m >> n >> r;
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    if (sy < ty) {
        swap(sx, tx);
        swap(sy, ty);
    }

    double seg = r / double(n);

    int dx = abs(sx - tx), dy = abs(sy - ty);

    double unitcur = 2.0*seg * dx / double(m) * (3.14159265358979323846 / 2);
    double ans = unitcur * (sy - dy) + seg * dy;

    for (int i=dy+1; i<=sy; ++i) {
        ans = min(unitcur * (sy-i) + seg * (2.0*(i-dy)+dy), ans);
    }
    printf("%.10lf", ans);

    return 0;
}