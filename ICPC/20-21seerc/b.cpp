#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

string s;

int main() {
    io;
    cin >> s;
    reverse(s.begin(), s.end());
    int zcnt = 0;
    ll sum = 0;
    // int pre = 0;
    for (int i=0; i<s.size(); ++i) {
        if (s[i] == '0') zcnt++;
        else {
            sum += zcnt;
        }
    }
    if (sum % 3 != 0) cout << "Alice\n";
    else cout << "Bob\n";
    return 0;
}