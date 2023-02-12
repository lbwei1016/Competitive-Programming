#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

vector<int> primes;
vector<bool> is_prime(105, true);
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i=2; i<100; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j=2*i; j<100; j+=i) {
                is_prime[j] = false;
            }
        }
    }
}

void solve() {
    ll res = 1;
    for (auto x: primes) {
        cout << x << ' ';
        res *= x;
    }
    cout << '\n' << primes.size();
}

int main() {
    io;
    sieve();
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}