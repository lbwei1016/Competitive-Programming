#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 505;
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

struct P {
    bool is, has;
};

P G[N][N];

int main() {
    io;
    cin >> n >> m; cin.ignore();
    // memset(G, -1, sizeof(G));

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

        if (re[0] == 'i') {
            G[mp[a]][mp[b]].is = 1;
        }
        else {
            G[mp[a]][mp[b]].has = 1;
        }
    }

    for (int i=0; i<cnt; ++i) G[i][i].is = 1;
    for (int i=0; i<cnt; ++i) {
        for (int j=0; j<cnt; ++j) {
            if (!G[i][j].is && !G[i][j].has) continue;
            for (int k=0; k<cnt; ++k) {
                if (!G[j][k].is && !G[j][k].has) continue;
                G[i][k].is |= (G[i][j].is & G[j][k].is);

                G[i][k].has |= (G[i][j].has & G[j][k].has);
                G[i][k].has |= (G[i][j].is & G[j][k].has);
                G[i][k].has |= (G[i][j].has & G[j][k].is);
            }
        }
    }

    for (int i=1; i<=m; ++i) {
        string s, a, b, re;
        getline(cin, s);
        vector<string> v = strtok(s);
        a = v[0], b = v[2], re = v[1];

        bool res = false;
        if (re[0] == 'i') res = (G[mp[a]][mp[b]].is);
        else res = (G[mp[a]][mp[b]].has);

        cout << "Query " << i << ": ";  
        if (res) cout << "true\n";
        else cout << "false\n";
    }
    return 0;
}