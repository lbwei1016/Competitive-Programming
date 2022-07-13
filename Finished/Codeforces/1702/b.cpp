#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    string s; cin >> s;
    int cnt = 0;
    for (int i=0; i<s.size();) {    
        set<char> S;
        while (i<s.size() && S.size() <= 3) {
            if (S.size() == 3 && !S.count(s[i])) 
                break;
            S.insert(s[i]);
            ++i;
        }
        cnt++;
    }
    cout << cnt << '\n';
}

int main() {
    io;
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}