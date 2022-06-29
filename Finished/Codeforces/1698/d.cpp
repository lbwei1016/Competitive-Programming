#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

bool calc(int l, int r, vector<int> &v) {
    int cnt = 0;
    for (int i=1; i<=r-l; ++i) {
        if (l <= v[i] && v[i] < r) cnt ^= 1;
    }
    return cnt;
}

int main() {
    io;
    int t; 
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int l = 1, r = n + 1;
        while (r-l > 1) {
            vector<int> v(r-l+1);
            int mid = (r+l) / 2;
            cout << "? " << l << ' ' << mid-1 << endl;

            for (int i=1; i<=mid-l; ++i) cin >> v[i];


            if (calc(l, mid, v)) r = mid;
            else l = mid;
        }
        cout << "! " << l << endl;
    }
    return 0;
}

/*
5 3 2 4 1 7 6
11 8 4 3 7 6 5 2 10 9 1 
17 23 7 6 21 4 3 18 11 24 9 19 25 22 15 20 1 8 12 16 5 14 2 10 13 
19 24 21 23 5 16 10 17 18 7 15 25 22 20 11 6 8 9 1 14 3 13 4 2 12 
*/