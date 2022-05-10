#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

// const int N = 1005;
// int bit[N];

void add(int i, vector<int> &bit) {
    while (i < bit.size()) {
        ++bit[i];
        i += i & -i;
    }
}

ll query(int i, vector<int> &bit) {
    ll sum = 0;
    while (i > 0) {
        sum += bit[i];
        i -= i & -i;
    }
    return sum;
}

int main() {
    io;
    int t;
    cin >> t;
    while (t--) {
        // memset(bit, 0, sizeof(bit));
        int n;
        cin >> n;
        vector<int> v(n+1), bit(n+1, 0);
        for (int i=1; i<=n; ++i) cin >> v[i];
        ll sum = 0;
        for (int i=n; i>=1; --i) {
            sum += query(v[i], bit);
            add(v[i], bit);
        }
        cout << sum << '\n';
    }
    return 0;
}