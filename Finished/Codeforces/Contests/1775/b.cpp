#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int P = 2e5 + 5, N = 1e5 + 5;    
vector<int> C[N];
// int all[P];
bitset<P> cnt, all;

inline bool solve() {
    int n; cin >> n;
    // memset(all, 0, sizeof(all));
    cnt.reset(); all.reset();
    for (int i=0; i<n; ++i) {
        int k; cin >> k;
        C[i].resize(k);
        for (int j=0; j<k; ++j) {
            int p; cin >> p;
            C[i][j] = p;
            if (!cnt[p]) cnt[p] = 1;
            else all[p] = 1;
        }
    }
    
    for (int i=0; i<n; ++i) {
        bool good = true;
        for (auto x: C[i]) {
            if (!all[x]) {
                good = false;
                break;
            } 
        }
        if (good) return true;
    }
    return false;
}

int main() {
    io;
    int t; cin >> t;
    while (t--) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}