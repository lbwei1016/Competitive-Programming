#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

string vow = "aeiou";

bool solve() {
    string s; cin >> s;
    int n = s.size();
    for (int len=2; len<=(n-1)/2; ++len) {
        for (int p1=0; p1<n-2*len; ++p1) {
            for (int p2=p1+len+1; p2<n-len+1; ++p2) {
                int l = len, vowcnt = 0;
                auto h1 = p1; auto h2 = p2;
                while (l--)  {
                    if (s[h1] != s[h2]) break;
                    if (vow.find(s[h1]) != std::string::npos) 
                        vowcnt++;
                    h1++; h2++;
                }
                if (l >= 0 || vowcnt < 2) continue;

                for (int i=h1; i<p2; ++i) {
                    if (vow.find(s[i]) != std::string::npos) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    io;
    int t; cin >> t;
    for (int i=1; i<=t; ++i) {
        bool ans = solve();
        cout << "Case #" << i << ": ";
        if (ans) cout << "Spell!\n";
        else cout << "Nothing.\n";
    }
    return 0;
}