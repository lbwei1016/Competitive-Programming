#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    io;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        ll sum = 0;
        for (int i=0; i<n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum!=0 || a[0]<0 || a.back()>0) {
            cout << "No\n";
            continue;
        }

        bool good = true;
        int end = 0;
        for (auto it=a.rbegin(); it!=a.rend(); ++it) {
            if (*it != 0) {
                end = a.rend() - it;
                break;
            }
        }

        ll plus = a[0];
        if (end != 0 && a[0] == 0) good = false;

        for (int i=1; i<end; ++i) {
            if (good == false) break;
            plus = plus + a[i];
            if ((i != end-1 && plus < 1) || (i == end-1 && plus != 0)) {
                good = false;
            }
        }

        if (good)
            cout << "Yes\n";
        else 
            cout << "No\n";
    }
    return 0;
}