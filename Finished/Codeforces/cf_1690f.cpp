/*
    Solution:
        Find sub-cycles, and determine the shortest lengths to restore to
        the original sub-sequence.
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}

int main() {
    io;
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> nxt(n+1);
        vector<char> s(n+1);
        for (int i=1; i<=n; ++i) cin >> s[i];
        for (int i=1; i<=n; ++i) {
            int at; cin >> at;
            nxt[at] = i;
        }
        vector<bool> vis(n+1);
        vector<vector<int> > cycs;
        for (int i=1; i<=n; ++i) {
            vector<int> cyc;
            while (!vis[i]) {
                vis[i] = true;
                cyc.push_back(i);
                i = nxt[i];
            }
            if (!cyc.empty())
                cycs.push_back(cyc);
        }

        ll all = 1;
        for (auto &v: cycs) {
            vector<char> init;
            for (auto &x: v) {
                init.push_back(s[x]);
            }
            int sz = init.size(), len = sz;
            for (int i=1; i<=sz; ++i) {
                bool good = true;
                for (int j=0; j<sz; ++j) {
                    if (init[j] != init[(j-i+sz)%sz]) {
                        good = false;
                        break;
                    }
                }
                if (good) {
                    len = i;
                    break;
                }
            }
            all = lcm(all, len);
        }
        cout << all << '\n';
    }
    return 0;
}