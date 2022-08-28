#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const ll INF = 1e18;

struct P {
    ll l, r;
    bool operator<(const P &p) const {
        return r == p.r ? l < p.l : r < p.r;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    map<ll, ll> mp;
    vector<ll> v(n+1);
    for (int i=1; i<=n; ++i) {
        cin >> v[i];
        mp[v[i]]++;
    }

    set<P> S; // segments denoting where bits are "1"
    // build segments
    for (auto it=mp.begin(); it!=mp.end();) {
        ll car = it->second / 2; // carry

        if (car != 0) {
            auto itt = mp.find(it->first+1);
            if (itt == mp.end()) {
                mp.insert({it->first+1, car});
            }
            else {
                itt->second += car;
            }
        }
        if (!(it->second & 1)) 
            it = mp.erase(it);
        else ++it;
    }
    // merge neighboring segments
    for (auto it=mp.begin(); it!=mp.end();) {
        ll l = it->first, r = l;
        auto itt = mp.erase(it);
        while (itt != mp.end()) {
            if (itt->first != r+1) break;
            ++r; 
            itt = mp.erase(itt);
        }
        S.insert({l, r});
        it = itt;
    }

    // boundry
    S.insert({-INF, -INF});
    S.insert({INF, INF});
    while (q--) {
        ll a, b;
        cin >> a >> b;
        ll tar = v[a]; // 加上 tar
        auto it = S.lower_bound({0, tar});
        if (it->l >= tar) {
            P rp = {it->l+1, it->r};
            P lp = {tar, it->l-1};

            if (rp.l <= rp.r) S.insert(rp);
            if (lp.l <= lp.r) {
                // merge
                auto itt = next(it, -1);
                if (itt->r+1 == lp.l) {
                    S.insert({itt->l, lp.r});
                    S.erase(itt);
                }
                else S.insert(lp);
            }
            S.erase(it);
        }
        else {
            P rp = {tar+1, it->r};
            P lp = {it->l, tar-1};
            if (rp.l <= rp.r) S.insert(rp);
            if (lp.l <= lp.r) S.insert(lp);
            S.erase(it);            
        }

        tar = v[a] = b; // 減去 tar
        it = S.lower_bound({0, tar});
        if (it->l <= tar) {
            P lp = {it->l, tar-1};
            if (lp.l <= lp.r) S.insert(lp);
            auto itt = next(it, 1);
            if (itt != S.end() && itt->l-1 == it->r+1) {
                S.insert({itt->l-1, itt->r});
                S.erase(itt);
            }
            else S.insert({it->r+1, it->r+1});
            S.erase(it);
        }
        else {
            P rp = {tar, tar};
            auto itt = next(it, -1);
            if (tar+1 == it->l) {
                rp.r = it->r;
                S.erase(it);
            }
            if (itt->r+1 == tar) {
                S.insert({itt->l, rp.r});
                S.erase(itt);
            }
            else S.insert(rp);
        }    
        cout << next(S.rbegin(), 1)->r << '\n'; // leading 1
    }
}

int main() {
    io;
    solve();
    return 0;
}