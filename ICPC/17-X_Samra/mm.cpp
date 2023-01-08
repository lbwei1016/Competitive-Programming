#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;
int nums[1005][1005];

struct node{
    int x, y, val;
};

static bool cmp(node a, node b){
    return a.val < b.val;
};

int main(){
    io;
    int m, n, x_max, y_max, cnt, max_val, min_x = 0, min_y = 0;
    cin >> m >> n;
    vector<node> ranks;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> nums[i][j];
            ranks.push_back({i, j, nums[i][j]});
        }
    }
    // for(auto vec : ranks){
    //     cout << vec.x << " " << vec.y << " " << vec.val << endl;
    // }
    sort(ranks.begin(), ranks.end(), cmp);
    vector<int> mp(m * n, 0);
    cnt = 0;
    nums[ranks[0].x][ranks[0].y] = 0;
    mp[cnt]++;
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
    for(int i = 0; i < n; i++){
        mp[nums[x_max][i]]--;
    }

    max_val = cnt;
    while(!mp[max_val]){
        max_val--;
    }
    int max_idx;
    for(int i = 0; i < n; i++){
        max_idx = cnt;
        for(int j = 0; j < m; j++){
            if(j != x_max){
                mp[nums[j][i]]--;
            }
        }
        while(!mp[max_idx]){
            max_idx--;
        }
        if(max_val >= max_idx){
            max_val = max_idx;
            min_y = i;
        }
        //printf("max_val is %d, now_col is %d\n", max_val, max_idx);
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
    }

    int max_val2 = cnt;
    while(!mp[max_val2]){
        max_val2--;
    }

    // if (max_val > max_idx) {
    //     max_val = max_idx;
    // }
    
    // bool flag = false;
    for(int i = 0; i < m; i++){
        max_idx = cnt;
        for(int j = 0; j < n; j++){
            if(j != y_max){
                mp[nums[i][j]]--;
            }
        }
        while(!mp[max_idx]){
            max_idx--;
        }
        if(max_val2 >= max_idx){
            max_val2 = max_idx;
            min_x = i;
            // flag = true;
        }
        //printf("max_val is %d, now_row is %d\n", max_val, max_idx);
        for(int j = 0; j < n; j++){
            if(j != y_max){
                mp[nums[i][j]]++;
            }
        }
    }
    if(max_val2 > max_val){
        cout << x_max + 1 << " " << min_y + 1;
    }
    else{
        cout << min_x + 1 << " " << y_max + 1;
    }
    return 0;
}