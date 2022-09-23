#include <bits/stdc++.h>
// #define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int mp[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int mmp[10] = {0, 0, 1, 7, 4, 8, 14, 11, 15, 21};

ll solve(ll n) {
    // if (n < 10) return mmp[n];
    int t = n % 3;
    ll k = 0;
    // n -= t;
    if (t == 1) k -= 3;
    else if (t == 2) k += 1;
    return k + (n/3LL)*7LL;
}

int main() {
    freopen("auxiliary.in", "r", stdin);
    freopen("auxiliary.out", "w", stdout);
    ll n; 
    scanf("%lld", &n);
    printf("%lld", solve(n));
    // }
    return 0;
}