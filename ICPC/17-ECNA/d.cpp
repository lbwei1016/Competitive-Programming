#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int n, k;

int main() {
    io;
    cin >> n >> k;

    int at = 0;
    vector<int> v(1);
    for (int i=0; i<k; ++i) {
        string s; cin >> s;
        if (s[0] == 'u') {
            int u; cin >> u;
            for (int j=0; j<=u; ++j) {
                at = v.back();
                v.pop_back();
            }
            v.push_back(at);
        }
        else {
            int a = stoi(s);
            at += a;
            if (at < 0) at += ((-at)/n + 1)*n;
            at %= n;
            v.push_back(at);
        }
    }
    cout << at << '\n';
    return 0;
}