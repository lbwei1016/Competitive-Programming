#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    io;
    int n, k; cin >> n >> k;
    vector<int> bit(n);
    for (int i=0; i<n; ++i) {
        string s; cin >> s;
        for (int j=0; j<k; ++j) {
            bit[i] <<= 1;
            bit[i] += s[j] - '0';
        }
    }    

    sort(bit.begin(), bit.end());
    bit.resize(unique(bit.begin(), bit.end()) - bit.begin());
    
    queue<int> que;
    vector<int> d(1 << k, -1);
    for (int i=0; i<bit.size(); ++i) {
        que.push(bit[i]);
        d[bit[i]] = 0; // 把現有的都設為起點
    }

    int mx = 0, ans;
    while (que.size()) {
        int p = que.front(); que.pop();
        for (int i=0; i<k; ++i) {
            int q = p ^ (1 << i);
            if (d[q] == -1) {
                d[q] = d[p] + 1;
                if (d[q] > mx) ans = q;
                que.push(q);
            }
        }
    }
    for (int i=k-1; i>=0; --i) {
        cout << bool(ans & (1 << i));
    }
    return 0;
}