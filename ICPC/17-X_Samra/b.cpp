#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

string s, ts;

int main() {
    io;
    cin >> s;
    int cnt = 0, at = 0;
    int a = 0, b = 1, pa, pb;
    while (true) {
        auto it = s.find("happiness", at);
        if (it == string::npos) break;
        else at = it + 9;
        pa = a, pb = b;
        a = it, b = a + 1;
        cnt++;
        if (cnt > 2) {
            break;
        }
    }
    if (cnt > 2) cout << "NO\n";
    else {
        cout << "YES\n";
        if (cnt == 0 && s.size() >= 9) {
            ts = s;
            swap(ts[a], ts[b]);
            if (ts.find("happiness") != string::npos) {
                a++; b++;
            }  
            cout << a + 1 << ' ' << b + 1 << '\n';
            return 0;
        }
        else if (cnt == 2) {
            a = pa;
        }
        cout << a + 1 << ' ' << b + 1 << '\n';
    }
    return 0;
}