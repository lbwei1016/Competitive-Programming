#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

ll dist(int n, vector<ll> &v) {
    sort(v.begin(), v.end());
    ll sum = 0;
    for (int i=0; i<n; ++i) {
        sum += ll(-(n - 1) + 2*i) * v[i];
    }
    return sum;
}

int main() {
    io;
    int n; cin >> n;
    vector<ll> p(n), q(n), ppq(n), pmq(n);
    for (int i=0; i<n; ++i) {
        cin >> p[i];
        ppq[i] = pmq[i] = p[i];
    }
    for (int i=0; i<n; ++i) {
        cin >> q[i];
        ppq[i] += q[i];
        pmq[i] -= q[i];
    }
    ll d1 = 2 * (dist(n, p) + dist(n, q));
    ll d2 = dist(n, ppq) + dist(n, pmq);
    // printf("d1: %d\nd2: %d\n", d1, d2);
    cout << d1 - d2 << '\n';
    return 0;
}