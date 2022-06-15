#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

bool solve(map<int, int> &mp) {
    for (int i=0; i<10; ++i) {
        if (mp[i] == 0) continue;
        else mp[i]--;
        for (int j=0; j<10; ++j) {
            if (mp[j] == 0) continue;
            else mp[j]--;
            for (int k=0; k<10; ++k) {
                if (mp[k] == 0) continue;
                if ((i+j+k)%10 == 3) return true;
            }
            mp[j]++;
        }
        mp[i]++;
    }
    return false;
}

int main() {
    io;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        map<int, int> mp;
        for (int i=0; i<n; ++i) {
            cin >> v[i];
            mp[v[i]%10]++;
        }
        if (solve(mp)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}