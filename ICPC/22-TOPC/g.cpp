#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
#define FNAME ""
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 7;
const ll LLINF = 1e18 + 7;

const int N = 205, M = 1005;
ll dp[N][M];
vector<ll> A, B;

inline ll cc(int i, int k) {
    return max(A[i] - (k-1)*B[i], 0LL);
    // return 1;
}

int main() {
    io;
    // freopen(FNAME".in", "r", stdin);
    // freopend(FNAME".out", "w", stdout);
    int n, m; cin >> n >> m;
    A.resize(n+5); B.resize(n+5);
    for (int i=0; i<n; ++i) {
        cin >> A[i];
    }
    for (int i=0; i<n; ++i) {
        cin >> B[i];
    }

    for (int i=1; i<n; ++i) {
        int x = abs(i - 1);
        for (int j=0; j<=x; ++j) {
            dp[i][j] = -INF;
        }
    }

    ll mx = 0;
    for (int j=1; j<=m; ++j) {
        for (int i=0; i<n; ++i) {
            int pre = (i - 1 + n) % n;
            int nxt = (i + 1) % n;
            dp[i][j] = max(dp[pre][j-1], max(dp[nxt][j-1], dp[i][j-1] + cc(i, j)));
            mx = max(mx, dp[i][j]);
        }
    }
    cout << mx << '\n';
    return 0;
}
/*
3 10
10 10 10
5 3 1
*/