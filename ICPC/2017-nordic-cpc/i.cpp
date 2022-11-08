#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 505, INF = 1e9+7;
int G[N][N], mid[N][N];
map<string, int> mp;
map<int, string> rmp;
int n; 

vector<int> path;

void findPath(int fr, int to) {
    if (mid[fr][to] == -1) return;
    int k = mid[fr][to];
    findPath(fr, k); 
    path.push_back(k);
    findPath(k, to);
}

int main() {
    io;
    cin >> n;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            G[i][j] = INF;
            mid[i][j] = -1;
        }
    }
    for (int i=0; i<n; ++i) {
        string s; cin >> s;
        mp[s] = i;
        rmp[i] = s;
    }
    for (int i=0; i<n; ++i) {
        string s; 
        int k, at;
        cin >> s >> k;
        at = mp[s];
        for (int j=0; j<k; ++j) {
            cin >> s; cin.ignore(); // eat import
            getline(cin, s);
            s += ", "; // for consistency of the following loop
            int pos = 0;
            while((pos = s.find(',')) != string::npos) {
                string to = s.substr(0, pos);
                G[at][mp[to]] = 1;
                s.erase(0, pos + 2);
            }
        }
    }

    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            for (int k=0; k<n; ++k) {
                if (G[i][k] + G[k][j] < G[i][j]) {
                    G[i][j] = G[i][k] + G[k][j];
                    mid[i][j] = k;
                }
            }
        }
    }

    int mn = INF, who;
    for (int i=0; i<n; ++i) {
        if (G[i][i] < mn) {
            mn = G[i][i];
            who = i;
        }
    }

    if (mn == INF) {
        cout << "SHIP IT\n";
        return 0;
    }

    findPath(who, who);

    cout << rmp[who] << ' ';
    for (auto x: path) {
        cout << rmp[x] << ' ';
    }

    return 0;
}