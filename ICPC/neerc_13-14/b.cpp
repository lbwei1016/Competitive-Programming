#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")
using namespace std;
using ll = long long;
using ld = double;

const int N = 3005;
ld dp[N][N];

int main() {
    // io;
    freopen("bonus.in", "r", stdin);
    freopen("bonus.out", "w", stdout);
    ll n, a, b;
    scanf("%lld %lld %lld", &n, &a, &b);
    if (n >= a + b + 1) {
        printf("1.0\n1.0\n");
        return 0;
    }
    ll s = 2;
    while (s >= 1) {
        memset(dp, 0, sizeof(dp));
        for (ll i=n-1; i>=0; --i) {
            for (ll j=min(i, a); j>=max(0LL, i-b); --j) {
                dp[i][j] = (s + 2*(a-j)*dp[i+1][j+1] + (b-i+j)*dp[i+1][j]) / (ld)(s + 2*(a-j) + (b-i+j));
            }
        }
        printf("%.10lf\n", dp[0][0]);
        --s;
    }

    return 0;
}