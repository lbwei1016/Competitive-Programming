#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int INF = 2e9+5;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> A(n+1), add(n), miu(n);
    for (int i=0; i<n; ++i) {
        int p ,q;
        cin >> A[i];
        p = A[i] + x;
        q = A[i] - x;
        add[i] = p, miu[i] = q;
    }

    int mn = -INF, mx = INF;
    // int pmx = -INF, pmn = INF;
    int res = 0;
    for (int i=0; i<n; ++i) {
        mx = min(mx, add[i]);
        mn = max(mn, miu[i]);
        if (mx < mn) {
            res++;
            mx = add[i]; mn = miu[i];
        }
    }
    // if (mx < mn) ++res;
    cout << res << '\n';
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
/*
ai+x: 6 11 8 9 10
ai-x: 0 5 2 3 4
5 6

6 13 12 11 10
0 7 6 5 4

4 9 10 11 8 15 23 30
0 5 6 7 4 11 19 26

16 9 18 28 12 15 10 
*/