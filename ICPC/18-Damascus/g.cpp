#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 1e5 + 5, INF = 1e9 + 7;

ll X, Y;
ll plcm[N], slcm[N]; // prefix and suffix LCM
ll pgcd[N], sgcd[N]; // prefix and suffix GCD

inline ll __lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
} 

void calc(vector<ll> &v) {
    int n = v.size();
    pgcd[0] = 0; plcm[0] = 1;
    for (int i=1; i<=n; ++i) {
        if (plcm[i-1] <= Y)
            plcm[i] = __lcm(plcm[i-1], v[i-1]);
        if (pgcd[i-1] >= X)
            pgcd[i] = __gcd(pgcd[i-1], v[i-1]);
        
    }
    sgcd[n-1] = 0; slcm[n-1] = 1;
    for (int i=n-2; i>=0; --i) {
        if (slcm[i+1] <= Y)
            slcm[i] = __lcm(slcm[i+1], v[i+1]);
        if (sgcd[i+1] >= X) 
            sgcd[i] = __gcd(sgcd[i+1], v[i+1]);
    }
}

int test(vector<ll> &v) {
    int n = v.size();
    for (int i=0; i<n; ++i) {
        ll LCM = __lcm(plcm[i], slcm[i]);
        ll GCD = __gcd(pgcd[i], sgcd[i]);
        if ((__gcd(GCD, X) == X) && (__lcm(LCM, X) == Y)) 
            return 1;
        if ((__gcd(GCD, Y) == X) && (__lcm(LCM, Y) == Y)) 
            return 1;
    }
    return 2;
}

int main() {
    io;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        fill(plcm, plcm + n, INF);
        fill(slcm, slcm + n, INF);
        memset(pgcd, 1, sizeof(pgcd));
        memset(sgcd, 1, sizeof(sgcd));
        cin >> X >> Y;
        vector<ll> v(n), err;
        int cnt = 0;

        for (int i=0; i<n; ++i) {
            cin >> v[i];
            if (v[i] % X != 0 || Y % v[i] != 0) {
                ++cnt;
                err.push_back(i);
            }
        }

        if (Y % X != 0 || X > Y || (n == 1 && X != Y)) {
            cout << "-1\n";
            continue;
        }

        int goal = 2;
        if (X == Y) --goal;
        if (cnt < goal) {
            int good = 0;
            ll LCM = 1, GCD = 0;
            for (int i=0; i<n; ++i) {
                if (err.size() && err.front() == i) 
                    continue;
                LCM = __lcm(LCM, v[i]);
                GCD = __gcd(GCD, v[i]);
            }
            if (cnt == 1) {
                good = max(good, (__gcd(GCD, X) == X) + (__lcm(LCM, X) == Y));
                good = max(good, (__gcd(GCD, Y) == X) + (__lcm(LCM, Y) == Y));
                if (good < 2) ++cnt;
            } 
            else {
                // cnt = 0;
                if (GCD == X) ++good;
                if (LCM == Y) ++good;
                if (good >= 1) cnt = max(0, goal - good);
                else {
                    cnt = min(goal, test(v));
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}

/*
1
4 3 24
3 6 8 12
ans: 1

1
8 12 96
12 18 48 36 40 12 12 12
ans: 3
*/