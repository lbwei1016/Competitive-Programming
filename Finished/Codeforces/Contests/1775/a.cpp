#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    io;
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        bool good = false;
        for (int i=1; i<=s.size()-2; ++i) {
            for (int j=2; j<s.size(); ++j) {
                string a = s.substr(0, i);
                string b = s.substr(i, j - i);
                string c = s.substr(j);
                // cout << a + ' ' + b + ' ' + c + '\n';
                if ((a <= b && c <= b) || (b <= a && b <= c)) {
                    cout << a + ' ' + b + ' ' + c + '\n';
                    good = true;
                    break;
                }
            }
            if (good) break;
        }
        if (!good) cout << ":(\n";
    }
    return 0;
}