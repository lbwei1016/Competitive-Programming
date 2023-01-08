#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define INF 1e6
using ll = long long;

int get_max(long long int a, long long int b){
    return a > b ? a : b;
}

long long int check(vector<vector<long long int>>& dp, int k, int idx, int dark){
    if(idx < 0){
        return 0;
    }
    if(idx == 0){
        return dp[idx][dark] = dark ? 0 : 1;
    }
    if(dp[idx][dark] != -1){
        return dp[idx][dark];
    }
    long long int ans = 0;
    //現在是黑色
    if(dark){
        ans += get_max(0, check(dp, k, idx - 1, 0)) + get_max(0, check(dp, k, idx - k, 0));
        // int p = get_max(0, check(dp, k, idx - 1, 0));
        // int q = get_max(0, check(dp, k, idx - k, 0));
        // printf("p is %d, q is %d\n", p, q);
        // ans += p + q;
    }
    else{
        ans += get_max(0, check(dp, k, idx - 1, 1));
    }
    return dp[idx][dark] = ans;
}

int main(){
    int l, k;
    cin >> l >> k;
    ll sum = 0;
    vector<vector<long long int>> dp(l + 1, vector<long long int>(2, -1));
    for(int i = 1; i <= l; i++){
        for (auto &v: dp) for (auto &x: v) x = -1;
        check(dp, k, i, 1);
        for (auto &v: dp) for (auto &x: v) sum += max(x, 0LL);   
    }
    // for(int i = 1; i <= l; i++){
    //     for(int j = 0; j < 2; j++){
    //         // cout << dp[i][j] << " ";
    //         if (dp[i][j] < 0) {
    //             printf("i: %d, j: %d, dp: %d\n", i, j, dp[i][j]);
    //         }
    //     }
    //     cout << endl;
    // }
    // long long int sum = 0;
    // // for(int i = 0; i <= l; i++){
    // //     sum += get_max(dp[i][1], 0);
    // // }
    cout << sum;
    return 0;
}
