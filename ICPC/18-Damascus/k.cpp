/*
額外紀錄多出來的那條邊，query 時再 check 走經過和不經過那條邊的 cost
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define io ios::sync_with_stdio(0), cin.tie(0);
ll eu = 0, ev = 0, ew = 0; // cycle edge
const int maxn = 1e5 + 5;
const int level = 17;
map<pair<ll, ll>, ll> edge;
vector<vector<ll>> adj;
vector<ll> depth;
vector<int> par;//用來找形成cycle的edge
vector<vector<pair<ll, ll>>> parent;

void dfs(ll v, ll prev){
    depth[v] = depth[prev] + 1;
    parent[v][0].first = prev;
    parent[v][0].second = edge[{v, prev}];
    //printf("v is %lld, prev is %lld, dis is %lld\n", v, prev, edge[{v, prev}]);
    for(ll i : adj[v]){
        if(i != prev){
            dfs(i, v);
        }
    }
}

ll lca(ll u, ll v){
    //printf("v now is %lld   ", v);
    if(depth[u] > depth[v]){
        swap(u, v);
    }
    ll diff = depth[v] - depth[u];
    ll dis = 0;
    for(int i = 0; i < level; i++){
        if((diff >> i) & 1){
            dis += parent[v][i].second;
            //printf("dis is %lld     ", dis);
            v = parent[v][i].first;
        }
    }
    if(u == v){
        return dis;
    }
    for(int i = level - 1; i >= 0; i--){
        if(parent[u][i].first != parent[v][i].first){
            dis += parent[u][i].second;
            dis += parent[v][i].second;
            u = parent[u][i].first;
            v = parent[v][i].first;
        }
    }
    //return depth[parent[u][0]];
    return dis + edge[{u, parent[u][0].first}] + edge[{v, parent[v][0].first}];
}

ll query(ll u, ll v){
    //cout << lca(u, v) << endl;
    return min(lca(u, v), min(lca(u, eu) + lca(v, ev), lca(u, ev) + lca(v, eu)) + ew);
}

void compute(ll n){
    for(ll i = 1; i < level; i++){
        for(ll node = 1; node <= n; node++){
            if(parent[node][i - 1].first != -1){
                parent[node][i].first = parent[parent[node][i - 1].first][i - 1].first;
                parent[node][i].second = parent[node][i - 1].second + parent[parent[node][i - 1].first][i - 1].second;
            }
        }
    }
}

ll find(ll x){
    if(par[x] == -1){
        return x;
    }
    return par[x] = find(par[x]);
}

int main(){
    io;
    ll t, n, q, u, v, w;
    bool flag;
    cin >> t;
    while(t--){
        cin >> n >> q;
        flag = false;
        adj = vector<vector<ll>>(n + 1);
        parent = vector<vector<pair<ll, ll>>>(n + 1, vector<pair<ll, ll>>(level, {-1, -1}));
        depth = vector<ll>(n + 1);
        par = vector<int>(n + 1, -1);
        for(int i = 0; i < n; i++){
            cin >> u >> v >> w;
            if(!flag){
                ll x = find(u);
                ll y = find(v);
                if(x == y){
                    eu = u;
                    ev = v;
                    ew = w;
                    flag = true;
                }
                else{
                    par[x] = y;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
            else{
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            pair<ll, ll> temp1 = {u, v};
            pair<ll, ll> temp2 = {v, u};
            edge[temp1] = edge[temp2] = w;
        }
        // cout << "adj is " << endl;
        // for(int i = 1; i <= n; i++){
        //     for(int j = 0; j < adj[i].size(); j++){
        //         cout << adj[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        dfs(1, 0);
        compute(n);
        // cout << "depth is   ";
        // for(int i = 0; i <= n; i++){
        //     cout << depth[i] << " ";
        // }
        // cout << endl;

        for(int i = 0; i < q; i++){
            cin >> u >> v;
            cout << query(u, v) << "\n";
        }
    }
    
    return 0;
}