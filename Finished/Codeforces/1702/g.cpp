/*
***LCA***
    Description:
        給一樹。每一 query 給一點集合 S，判斷 S 是否為樹上任一一條路徑所含點的子集合
    Solution:
        首先，路徑只有兩種可能: "直線" 型或 "轉彎" 型。"直線" 路徑中，存在一點排列使得
        所有點的深度嚴格遞增；"轉彎" 路徑中則非，且存在一 LCA 為 "轉折點": 以此轉
        折點拆分的兩條子路徑皆是 "直線" 型。由於 "轉彎" 型包含 "直線" 型，因此我們
        優先討論 "轉彎" 型。

        對給定的點集合 S，先將他們依照預先計算的深度排列。因為 "直線" 中所有點的深
        度嚴格遞增，並且其他點必然是最深點的祖先，於是透過祖先判斷(透過 LCA)，我們可以在 S 中
        找出第一條 "直線" 子路徑，並將其他點標記起來。被標記的點重複祖先判斷，若當中
        有任一一點不符合(即祖先關係不成立)，則答案為否。成功找出兩條子路徑後，要確認他們
        是否可能交會在 "轉折點"，亦即 S 中最淺的點是否比兩子路徑中最深點的 LCA 還深；
        若是，代表可以交會，反之則否。

        若 S 是直線型，只需做第一次祖先判斷即可。

    Time Comlexity:
        O(q * klogk)
        雖然 n <= 2e5, k <= n, and q <= 1e5，但這解可以過 !!!
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 2e5+5, lgN = 21;
int n, lgn;
int anc[N][lgN];
int tme, in[N], out[N];
vector<vector<int>> G;
vector<int> dep;

void dfs(int at, int p) {
    dep[at] = dep[p] + 1;
    in[at] = ++tme;
    anc[at][0] = p;
    for (int i=1; i<lgn; ++i) {
        anc[at][i] = anc[anc[at][i-1]][i-1];
    }

    for (auto to: G[at]) {
        if (to == p) continue;
        dfs(to, at);
    }
    out[at] = ++tme;
}

bool isanc(int x, int y) {
    return in[x] <= in[y] && out[x] >= out[y];
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i=lgn; i>=0; --i) {
        if (!isanc(anc[x][i], y))
            x = anc[x][i];
    }
    return anc[x][0];
}

void solve() {
    cin >> n;
    lgn = 0;
    while ((1 << lgn) < n) lgn++;
    dep.assign(n+1, -1);
    G.assign(n+1, vector<int>());

    for (int i=0; i<n-1; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    in[0] = -1; out[0] = 1e9+7;
    tme = 0;

    dfs(1, 0);

    int q; cin >> q;
    while (q--) {
        bool good = true;
        int k; cin >> k;

        vector<int> vv(k), mark;
        for (int i=0; i<k; ++i) cin >> vv[i];
        sort(vv.begin(), vv.end(), [](int a, int b) {
            return dep[a] > dep[b];
        });

        int deepest = *vv.begin();
        for (int i=1; i<k; ++i) {
            // 祖先判斷
            if (lca(deepest, vv[i]) != vv[i])
                mark.push_back(vv[i]);
        }
        if (mark.size()) {
            // 祖先判斷
            deepest = *mark.begin();
            for (int i=1; i<mark.size(); ++i) {
                if (lca(deepest, mark[i]) != mark[i]) {
                    good = false;
                    break;
                }   
            }
            // check intersection
            if (dep[lca(vv[0], mark[0])] > dep[vv.back()]) 
                good = false;
        }

        if (good) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    io;
    solve();
    return 0;
}