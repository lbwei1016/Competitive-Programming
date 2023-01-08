/*
***Solution***
    將時間想成是前閉後開 [) 的區段
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

struct P {
    ll usg, rec, st;
};

vector<P> jill, peo;

int main() {
    // io;
    for (int i=0; i<10; ++i) {
        int u, r; cin >> u >> r;
        jill.push_back(P{u, r, 0});
    }
    for (int i=0; i<10; ++i) {
        int u, r, st;
        cin >> u >> r >> st;
        peo.push_back(P{u, r, st});
    }

    ll t = 0;
    for (int i=0; i<30; ++i) {
        if (i > 0) {
            t += jill[(i-1)%10].rec;
            // printf("i: %d; t: %d\n",i%10, t);
        }
        if (t >= peo[i%10].st) { 
            ll per_cyc = (t-peo[i%10].st) / (peo[i%10].rec + peo[i%10].usg);
            ll rt = per_cyc * (peo[i%10].rec + peo[i%10].usg) + peo[i%10].st + peo[i%10].usg;
            // if (rt == t) rt++;
            // printf("cyc: %d; cyc*c: %d; rt: %d\n", per_cyc, per_cyc * (peo[i%10].rec + peo[i%10].usg), rt);
            // puts("------------------------------");
            t = max(t, rt);
            peo[i%10].st = rt + peo[i%10].rec;
        }
        t += jill[i%10].usg;
        peo[i%10].st = max(t, peo[i%10].st);
    }
    cout << t << '\n';
    return 0;
}