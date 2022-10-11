#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    io;
    int n; cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; ++i) cin >> v[i];
    int s[2] = {0};
    sort(v.begin(), v.end());
    for (int i=0; i<n; ++i) {
        s[i&1] += v.back();
        v.pop_back();
    }
    cout << s[0] << ' ' << s[1];
    return 0;
}