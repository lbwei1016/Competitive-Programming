#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 505;
struct P {
    int at, flag;
};
int n, m;
map<string, int> mp;
int cnt;

vector<P> G[N];
bool rela[N][N][2];

void bfs(int st) {
    rela[st][st][0] = 1; // i is-a i
    queue<P> que;
    que.push(P{st, 0});
    while (que.size()) {
        auto p = que.front();
        que.pop();
        for (auto v: G[p.at]) {
            if (rela[st][v.at][p.flag | v.flag]) continue;
            rela[st][v.at][p.flag | v.flag] = 1;
            que.push(P{v.at, p.flag | v.flag});
        }
    }
}

int main() {
    io;
    cin >> n >> m; cin.ignore();
    // memset(G, -1, sizeof(G));

    for (int i=0; i<n; ++i) {
        string a, re, b;
        cin >> a >> re >> b;
        if (mp.find(a) == mp.end()) mp[a] = cnt++;
        if (mp.find(b) == mp.end()) mp[b] = cnt++;
        int st = (re[0] == 'h');
        G[mp[a]].push_back(P{mp[b], st});
    }

    for (int i=0; i<cnt; ++i) {
        bfs(i);
    }

    for (int i=1; i<=m; ++i) {
        string s, a, b, re;
        cin >> a >> re >> b;

        bool res = false;
        if (re[0] == 'i') res = (rela[mp[a]][mp[b]][0]);
        else res = (rela[mp[a]][mp[b]][1]);

        cout << "Query " << i << ": ";  
        if (res) cout << "true\n";
        else cout << "false\n";
    }
    return 0;
}