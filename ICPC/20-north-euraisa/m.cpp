#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int main() {
    io;
    int n; cin >> n;
    int cnt = 0;

    vector<int> tab(N);
    int pre = 0;
    for (int i=0; i<n; ++i) {
        int m; cin >> m;
        int mx = 0;
        vector<int> peo(m);
        for (int j=0; j<m; ++j) {
            int who; cin >> who;
            peo[j] = who;
            mx = max(mx, tab[who] + 1); 
        }

        if (mx > pre) ++cnt;
        // else mx = pre;
        for (auto x: peo) {
            tab[x] = mx;
        }
        pre = max(pre, mx);
    }
    cout << cnt << '\n';
    return 0;
}
/*
11
1 1
2 2 3
1 4
2 1 2
2 3 4
2 1 2
2 1 3
2 1 4
1 2
1 2
1 1
*/