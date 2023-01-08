#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define io ios::sync_with_stdio(0), cin.tie(0);
const ll inf = 2000 * 10000 + 5;
vector<ll> price(2005);
vector<ll> pre(2005);
// vector<vector<ll>> dp(2005, vector<ll>(25, -1));
ll dp[2005][25];

ll suf[2005];

ll round_(ll x){
    return x % 10 <= 4 ? x - (x % 10) : x - (x % 10) + 10;
}

ll check(int idx, int d, ll count){
    if(d < 0 || idx < 0){
        return inf;
    }
    if(d == 0){
        dp[idx][d] = round_(suf[0] - suf[idx + 1]);
        return round_(suf[0] - suf[idx + 1]);
    }
    if(dp[idx][d] != -1){
        return dp[idx][d];
    }
    ll a = round_(price[idx]) + check(idx - 1, d - 1, price[idx]);
    ll b = check(idx - 1, d, count + price[idx]);
    //ll ans = min(round_(count) + check(idx + 1, d - 1, n, price[idx]), check(idx + 1, d, n, count + price[idx]));
    ll ans = min(a, b);
    printf("idx is %d, d is %d, ans is %lld, count is %lld, a is %lld, b is %lld\n", idx, d, ans, count, a, b);
    return dp[idx][d] = ans;
}

int main(){
    io;
    int n, d;
    cin >> n >> d;
    cin >> price[0];
    pre[0] = price[0];
    for(int i = 1; i < n; i++){
        cin >> price[i];
        pre[i] = pre[i - 1] + price[i];
    }
    memset(dp, -1, sizeof(dp));
    suf[n] = 0;
    suf[n-1] = price[n-1];
    for (int i=n-2; i>=0; --i) {
        suf[i] = suf[i + 1] + price[i];
    }
    dp[0][0] = 0;
    cout << check(n - 1, d, price[n-1]) << '\n';
    return 0;
}

/*
5 2
3 3 3 3 3
*/