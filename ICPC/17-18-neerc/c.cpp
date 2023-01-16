#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 19;
string con = "bcdfghjklmnpqrstvxz";
int tab[N][N];

int main() {
    // io;
    freopen("consonant.in", "r", stdin);
    freopen("consonant.out", "w", stdout);

    string s;
    cin >> s;
    for (int i=1; i<s.size(); ++i) {
        int u = con.find(s[i]), v = con.find(s[i-1]);
        if (u == string::npos || v == string::npos) continue;
        tab[u][v]++;
        tab[v][u]++;
    }

    int mx = 0, stat;
    for (int S=0; S<(1 << N); ++S) {
        int cnt = 0;
        for (int u=0; u<N; ++u) {
            for (int v=u+1; v<N; ++v) {
                int ub = (S >> u) & 1;
                int vb = (S >> v) & 1;
                if (ub ^ vb) {
                    cnt += tab[u][v];
                }
            }
        }
        if (cnt > mx) {
            mx = cnt;
            stat = S;
        }
    }
    
    for (int i=0; i<s.size(); ++i) {
        char c = s[i];
        if (con.find(c) == string::npos) {
            cout << c;
            continue;
        }
        int num = con.find(c);
        if ((stat >> num) & 1) {
            cout << char('A' + (c - 'a'));
        }
        else cout << c;
    }
    return 0;
}