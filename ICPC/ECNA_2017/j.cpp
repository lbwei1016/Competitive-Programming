#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

struct P {
    ll usg, rec, st;
};

vector<P> jill, peo;

int main() {
    io;
    for (int i=0; i<10; ++i) {
        int u, r; cin >> u >> r;
        jill.push_back(P{u, r, 0});
    }
    for (int i=0; i<10; ++i) {
        int u, r, st;
        cin >> u >> r >> st;
        peo.push_back(P{u, r, st});
    }

    ll t = peo[0].st + peo[0].usg;
    for (int i=0; i<30; ++i) {
        // ll pt = t;
        if (i > 0) {
            t += jill[(i-1)%10].rec;
            ll per_cyc = (t-peo[i%10].st) / (peo[i%10].rec + peo[i%10].usg);
            ll rt = per_cyc * (peo[i%10].rec + peo[i%10].usg) + peo[i%10].st + peo[i%10].usg;
            // ll peo_left = (rt) % (peo[i%10].rec + peo[i%10].usg);

            // if (peo_left > peo[i%10].usg) peo_left = peo[i%10].usg;
            // t += peo[i%10].usg - peo_left;

            t = rt;
        }
        // t += peo_left;
        t += jill[i%10].usg;
    }
    cout << t-1-jill[0].rec << '\n';
    return 0;
}