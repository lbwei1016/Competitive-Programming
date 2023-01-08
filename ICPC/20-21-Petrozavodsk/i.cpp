#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int n;
ll S;
vector<ll> C, P, vec;

bool check(int k) {
    ll s = S;
    for (int i=0; i<n; ++i) {
        vec[i] = C[i] + (k-1) * 
    }
}

int main() {
    io;
    cin >> n >> S;
    C.resize(n+1);
    P.resize(n+1);
    vec.resize(n);
    for (int i=0; i<n; ++i) {
        cin >> C[i];
    }
    for (int i=0; i<n; ++i) {
        cin >> P[i];
    }

    int lb = 0, ub = n + 1;
    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (check(mid)) lb = mid;
        else ub = mid;
    }
    cout << lb << '\n';
    return 0;
}