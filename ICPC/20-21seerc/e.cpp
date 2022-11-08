#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int n;
vector<ll> vec;
int ans = 0;

pair<ll, ll> rec(int l, int r) {
    if (r - l == 1) return {0, vec[l]};
    int mid = (l + r) / 2;
    auto lsum = rec(l, mid);
    auto rsum = rec(mid, r);

    ll psum = 0;
    // ll lp = lsum.second, rp = rsum.second;
    ll lsqs = 0, rsqs = 0;
    printf("l: %d; r: %d\n", l, r);
    for (int i=mid; i<r; ++i) {
        psum += vec[i]; psum %= 3;
        // lp += vec[i]; lp %= 3;
        lsqs += vec[i] * vec[i]; lsqs %= 3;
        if ((lsum.first + lsum.second * psum + (psum*psum - lsqs)*2) % 3 == 0) {
            ans++;
        }
        if (i == r - 1) {
            cout << "l: " << (lsum.first + lsum.second * psum + (psum*psum - lsqs)*2) << '\n';
        }
    }

    psum = 0;
    for (int i=mid-1; i>l; --i) {
        psum += vec[i]; psum %= 3;
        // rp += vec[i]; rp %= 3;
        rsqs += vec[i] * vec[i]; rsqs %= 3;
        if ((rsum.first + rsum.second * psum + (psum*psum - rsqs)*2) % 3 == 0) 
            ++ans;
        if (i == l) {
            cout << "r: " << (rsum.first + rsum.second * psum + (psum*psum - rsqs)*2) % 3 << '\n';
        }
    }
    return {(lsum.first + rsum.first + lsum.second * rsum.second)%3, lsum.second + rsum.second};
}

int main() {
    // io;
    cin >> n;
    vec.resize(n);
    for (int i=0; i<n; ++i) {
        cin >> vec[i];
    }
    rec(0, n);
    cout << ans + n << '\n';
    return 0;
}