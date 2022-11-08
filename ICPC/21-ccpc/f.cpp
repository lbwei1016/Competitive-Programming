#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 22;
int n;
ll A[N];
ll X;
bool vis[N];
ll mx;

void rec(int at, int d, ll x) {
    if (x == 0) return;
    if (d == n) {
        mx = max(mx, x);
        return;
    }
    for (int i=at; i<n; ++i) {
        if (vis[i]) continue;
        if (A[i] > x) {
            // vis[i] = true;
            ++d;
            continue;
        }
        vis[i] = true;
        rec(i+1, i+1, x % A[i]);
        vis[i] = false;
    }
    if (d == n) mx = max(mx, x);
}

int main() {
    io;
    cin >> n;
    for (int i=0; i<n; ++i) cin >> A[i];
    cin >> X;

    sort(A, A+n, greater<ll>());
    rec(0, 0, X);
    cout << mx << '\n';
    return 0;
}