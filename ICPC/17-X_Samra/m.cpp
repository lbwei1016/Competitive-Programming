#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)

using namespace std;
using ll = long long;
ll r, g, un, r_max, g_max;

struct node{
    int x, y, val;
};

static bool cmp(node a, node b){
    return a.val < b.val;
};

const int N = 1005;
int nums[N][N];

int main(){
    io;
    int m, n, x_max, y_max, cnt, max_val, min_x, min_y;
    cin >> m >> n;
    vector<node> ranks(m * n);
    // vector<vector<int>> nums(m, vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> nums[i][j];
            // ranks.push_back({i, j, nums[i][j]});
            ranks[i*n + j] = {i, j, nums[i][j]};
        }
    }
    sort(ranks.begin(), ranks.end(), cmp);
    map<int, int> mp;
    cnt = 0;
    nums[ranks[0].x][ranks[0].y] = 0;
    for(int i = 1; i < ranks.size(); i++){
        if(ranks[i].val == ranks[i - 1].val){
            nums[ranks[i].x][ranks[i].y] = cnt;
        }
        else{
            nums[ranks[i].x][ranks[i].y] = ++cnt;
        }
        mp[cnt]++;
    }
    // cout << "test" << endl;
    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << nums[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    x_max = ranks[ranks.size() - 1].x;
    y_max = ranks[ranks.size() - 1].y;
    //printf("x_max is %d, y_max is %d\n", x_max, y_max);
    
    //deal with column
    //cout << "delete ";
    for(int i = 0; i < n; i++){
        //cout << nums[x_max][i] << " ";
        mp[nums[x_max][i]]--;
        if(mp[nums[x_max][i]] == 0){
            mp.erase(nums[x_max][i]);
        }
    }
    //cout << endl;
    // for(auto it = mp.begin(); it != mp.end(); it++){
    //     cout << it -> first << ", " << it -> second << endl;
    // }
    max_val = mp.rbegin() -> first;
    //printf("max_val is %d\n", max_val);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(j != x_max){
                mp[nums[j][i]]--;
                if(mp[nums[j][i]] == 0){
                    mp.erase(nums[j][i]);
                }
            }
        }
        //printf("max_val is %d, now_col is %d\n", max_val, mp.rbegin() -> first);
        if(max_val >= mp.rbegin() -> first){
            min_y = i;
            max_val = mp.rbegin() -> first;
        }
        for(int j = 0; j < m; j++){
            if(j != x_max){
                mp[nums[j][i]]++;
            }
        }
    }

    for(int i = 0; i < n; i++){
        mp[nums[x_max][i]]++;
    }
    for(int i = 0; i < m; i++){
        mp[nums[i][y_max]]--;
        if(mp[nums[i][y_max]] == 0){
            mp.erase(nums[i][y_max]);
        }
    }
    max_val = min(max_val, mp.rbegin() -> first);
    
    bool flag = false;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(j != y_max){
                mp[nums[i][j]]--;
                if(mp[nums[i][j]] == 0){
                    mp.erase(nums[i][j]);
                }
            }
        }
        //printf("max_val is %d, now_row is %d\n", max_val, mp.rbegin() -> first);
        if(max_val >= mp.rbegin() -> first){
            min_x = i;
            max_val = mp.rbegin() -> first;
            flag = true;
        }
        for(int j = 0; j < n; j++){
            if(j != y_max){
                mp[nums[i][j]]++;
            }
        }
    }
    if(!flag){
        cout << x_max + 1 << " " << min_y + 1;
    }
    else{
        cout << min_x + 1 << " " << y_max + 1;
    }
    return 0;
}