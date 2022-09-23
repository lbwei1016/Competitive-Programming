#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 1e4 + 5;

int n, V;
vector<int> G[N];
int subs[N];

ll fres1, fres2;

void dfs(int v, int p) {
    subs[v] = 1;
    int mxs[3] = {0};
    vector<ll> sub;
    for (auto u: G[v]) {
        if (u == p) continue;
        dfs(u, v);
        subs[v] += subs[u];

        sub.push_back(subs[u]);
        mxs[2] = subs[u];
        for (int i=2; i>0; --i) {
            if (mxs[i] > mxs[i-1]) {
                swap(mxs[i], mxs[i-1]);
            }
            else break;
        }
    }

    sub.push_back(V - subs[v]);
    mxs[2] = V - subs[v];
    for (int i=2; i>0; --i) {
        if (mxs[i] > mxs[i-1]) {
            swap(mxs[i], mxs[i-1]);
        }
        else break;
    }
    ll tot = 0;
    ll res1 = 0, res2 = 0;
    for (auto x: sub) tot += x;
    for (auto x: sub) {
        res1 += x * (tot - x);
    }   
    res1 /= 2;
    if (res1 > fres1) {
        fres1 = res1;
        fres2 = fres1 - mxs[0] * mxs[1];
    }
}

int main() {
    io;
    cin >> n;
    // bal_sz = 1e9;
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

    dfs(1, 0);

    cout << fres1 << ' ' << fres2;
    return 0;
}