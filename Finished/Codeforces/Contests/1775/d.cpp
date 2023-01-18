#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using ll = long long;

const int N = 3e5 + 5, INF = 1e9 + 7;

struct P {
    int val;
    vector<int> factor;
};

vector<P> a(N);

vector<int> prime;
vector<bool> isprime(N, true);
vector<int> mp[N];

vector<int> dis(N, INF), pre(N, -1);

void sieve() {
    isprime[0] = isprime[1] = false;
    for (int i=2; i<N; ++i) {
        if (isprime[i]) {
            prime.push_back(i);
            for (int j=2*i; j<N; j+=i) {
                isprime[j] = false;
            }
        }
    }
}

void fac(int id) {
    int x = a[id].val;
    int sq = sqrt(x);
    for (int i=0; prime[i]<=sq; ++i) {
        bool in = false;
        while (x % prime[i] == 0) {
            x /= prime[i];
            in |= 1;
        }
        if (in) {
            mp[prime[i]].push_back(id);
            a[id].factor.push_back(prime[i]);
        }
        if (x == 1) break;
    }
    if (isprime[x]) {
        mp[x].push_back(id);
        a[id].factor.push_back(x);
    }
}

void bfs(int s, int t) {
    queue<int> que;
    vector<bool> visprime(N, false);
    dis[s] = 0;
    que.push(s);
    while (que.size()) {
        int v = que.front(); que.pop();
        if (v == t) break;
        for (auto &x: a[v].factor) {
            if (visprime[x]) continue;
            visprime[x] = true;
            for (auto &y: mp[x]) {
                if (dis[y] == INF) {
                    dis[y] = dis[v] + 1;
                    pre[y] = v;
                    que.push(y);
                }
            }
        }
    }
}

int main() {
    io;
    sieve();
    int n; cin >> n;
    int s, t;
    for (int i=0; i<n; ++i) {
        cin >> a[i].val;     
        fac(i);   
    }
    cin >> s >> t;
    --s; --t;

    bfs(s, t);

    if (dis[t] == INF) {
        cout << "-1\n";
    }
    else {
        cout << dis[t] + 1 << '\n';
        vector<int> rou;
        for (int i=t; i!=-1; i=pre[i]) {
            rou.push_back(i);
        }
        reverse(rou.begin(), rou.end());
        for (auto x: rou) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}