#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int INF = 2e9 + 7;

int main() {
    io;
    int n, m;
    cin >> n >> m;
    vector<ll> tel(n), bon(m);
    for (int i=0; i<n; ++i) {
        cin >> tel[i];
    }
    for (int i=0; i<m; ++i) {
        cin >> bon[i];
    }

    tel.resize(unique(tel.begin(), tel.end()) - tel.begin());
    bon.resize(unique(bon.begin(), bon.end()) - bon.begin());
    n = tel.size();
    m = bon.size();

    ll res = 0;
    ll l, r = tel[0];
    for (int i=1; i<n; ++i) {
        l = r; r = tel[i];
        ll mid = (l + r) / 2;
        int bonat = upper_bound(bon.begin(), bon.end(), mid) - bon.begin();
        // if (bon[bonat] == mid) {
        //     if (bonat < m-1) bonat++;
        // }
        ll val1 = 0;
        if (bonat < m)
            val1 += max(0LL, 2 * (r - bon[bonat]));
        if (bonat > 0) val1 += max(0LL, 2 * (bon[bonat - 1] - l));

        val1 = min(val1, r - l);
        res += val1;
    }

    if (bon[0] < tel[0]) res += 2 * (tel[0] - bon[0]);
    if (bon.back() > tel.back()) res += 2 * (bon.back() - tel.back());

    cout << res << '\n';
    return 0;
}

/*
4 9
0 10 22 30
-5 -2 1 7 9 15 18 33 36

2 2
30 41
35 42
*/