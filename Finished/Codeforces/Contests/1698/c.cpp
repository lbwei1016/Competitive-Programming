#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

bool solve(int n) {
    vector<ll> cnt(3), v;
    bool good = true;
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        if (x < 0) cnt[0]++;
        else if (x == 0) cnt[1]++;
        else cnt[2]++;
        
        if (x != 0) v.push_back(x);
        if (cnt[0] > 2 || cnt[2] > 2) good = false;
    }

    if (!good) return false;

    for (int i=0; i<min(2LL, cnt[1]); ++i) v.push_back(0);

    int sz = v.size();
    for (int i=0; i<sz; ++i) {
        for (int j=i+1; j<sz; ++j) {
            for (int k=j+1; k<sz; ++k) {
                ll val = v[i]+v[j]+v[k];
                if (find(v.begin(), v.end(), val) == v.end())
                    return false;
            }
        }
    }
    return true;
}

int main() {
    io;
    int t; 
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (solve(n)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}