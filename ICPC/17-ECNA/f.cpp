#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 1e4 + 5;
int n, V;
vector<int> G[N];
int subs[N];
int bal_sz, cent;
vector<int> cents;

void find_cent(int v, int p) {
    subs[v] = 1;
    int mx_sub = 0;
    for (auto u: G[v]) {
        if (u == p) continue;
        find_cent(u, v);
        subs[v] += subs[u];
        mx_sub = max(mx_sub, subs[u]);
    }
    mx_sub = max(mx_sub, V - subs[v]);
    if (mx_sub < bal_sz) {
        cent = v;
        bal_sz = mx_sub;
        cents.clear(); cents.push_back(v);
    }
    else if (mx_sub == bal_sz) {
        cents.push_back(v);
    }
}

vector<int> cent_sub;
int mxs[3];

void dfs(int v, int p) {
    subs[v] = 1;
    for (auto u: G[v]) {
        if (u == p) continue;
        dfs(u, v);
        subs[v] += subs[u];
        if (v == cent) {
            cent_sub.push_back(subs[u]);
        }
        mxs[2] = subs[u];
        for (int i=2; i>0; --i) {
            if (mxs[i] > mxs[i-1]) {
                swap(mxs[i], mxs[i-1]);
            }
            else break;
        }
    }
}

int main() {
    io;
    cin >> n;
    bal_sz = 1e9;
    set<int> Vs;
    for (int i=0; i<n; ++i) {
        int u, v;
        cin >> u >> v;
        ++u, ++v;
        G[u].push_back(v);
        G[v].push_back(u);
        Vs.insert(u); Vs.insert(v);
    }
    V = Vs.size();
    find_cent(1, 0);

    ll fres1 = 0, fres2 = 0;
    for (auto c: cents) {
        memset(mxs, 0, sizeof(mxs));
        dfs(c, 0);
        // cout << "cent: " << cent << '\n';
        int tot = 0;
        ll res1 = 0;
        for (auto x: cent_sub) tot += x;
        for (auto x: cent_sub) {
            res1 += x * (tot - x);
        }
        res1 /= 2;
        // ll res2 = res1 - mxs[0] * mxs[1];
        if (res1 > fres1) {
            fres1 = res1;
            fres2 = fres1 - mxs[0] * mxs[1];
        }
    }

    cout << fres1 << ' ' << fres2;
    return 0;
}