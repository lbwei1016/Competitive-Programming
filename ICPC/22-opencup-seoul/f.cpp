#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    io;
    int n; cin >> n;
    vector<ll> A(n), v;
    string S; cin >> S;
    for (int i=0; i<n; ++i) {
        cin >> A[i];
    }    
    
    int at = 0;
    while (at < n && S[at] == S[0]) at++;
    n = n - 1;
    while (n >= 0 && S[n] == S.back()) n--;

    // multiset<ll> mxs;
    char pre = S[at];
    ll mx = A[at];
    vector<ll> mxs;
    for (int i=at; i<=n + 1; ++i) {
        // ll mx = 0;
        while (i <= n && S[i] == pre) {
            mx = max(mx, A[i]);
            ++i;
        }
        mxs.push_back(mx);
        if (i > n) break;
        pre = S[i];
        mx = A[i];
    }


    sort(mxs.begin(), mxs.end());

    int cnt = (mxs.size() + 1) / 2;
    ll sum = 0;
    while (cnt > 0) {
        sum += mxs.back();
        mxs.pop_back();
        --cnt;
    }
    cout << sum << '\n';
    return 0;
}