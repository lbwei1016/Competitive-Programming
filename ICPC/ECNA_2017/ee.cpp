#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 505;

struct node {
    vector<int> ischl, haschl;
} tree[N];

int n, m;
map<string, int> mp;
int cnt;

vector<string> strtok(string s) {
    s += ' ';
    int pos = 0;
    vector<string> slice;
    while((pos = s.find(" ")) != string::npos) {
        slice.push_back(s.substr(0, pos));
        s.erase(0, pos+1);
    }
    return slice;
}

bool vis[N];

bool istrav(int v, int p, int tar) {
    if (v == tar) return true;
    if (vis[v]) return false;
    vis[v] = true;
    bool res = false;
    for (auto u: tree[v].ischl) {
        if (u == p) continue;
        res |= istrav(u, v, tar);
        if (res) return true;
    }
    return false;
}

bool hastrav(int v, int p, int tar, int st) {
    if (v == tar) {
        return st > 0;
    }
    // if (vis[v]) return false;
    // vis[v] = true;
    bool res = false;
    for (auto u: tree[v].ischl) {
        if (u == p || vis[u]) continue;
        vis[u] = true;
        res |= hastrav(u, v, tar, st);
        if (res) return true;
        vis[u] = false;
    }
    for (auto u: tree[v].haschl) {
        if (u == p || vis[u]) continue;
        vis[u] = true;
        res |= hastrav(u, v, tar, 1);
        if (res) return true;
        vis[u] = false;
    }
    return false;
}

int main() {
    io;
    cin >> n >> m; cin.ignore();

    for (int i=0; i<n; ++i) {
        string s;
        getline(cin, s);
        auto v = strtok(s);
        string a = v[0], b = v[2], re = v[1];
        if (mp.find(a) == mp.end()) {
            mp[a] = cnt++;
        }
        if (mp.find(b) == mp.end()) {
            mp[b] = cnt++;
        }

        if (re[0] == 'i')
            tree[mp[a]].ischl.push_back(mp[b]);
        else 
            tree[mp[a]].haschl.push_back(mp[b]);
    }

    for (int i=1; i<=m; ++i) {
        string s, a, b, re;
        getline(cin, s);
        vector<string> v = strtok(s);
        a = v[0], b = v[2], re = v[1];

        memset(vis, 0, sizeof(vis));
        bool res = false;
        int fr = mp[a], tar = mp[b];
        if (re[0] == 'i') {
            res = istrav(fr, -1, tar);
        }
        else {
            vis[fr] = true;
            res = hastrav(fr, -1, tar, 0);
        }
        cout << "Query " << i << ": ";  
        if (res) cout << "true\n";
        else cout << "false\n";
    }
    return 0;
}