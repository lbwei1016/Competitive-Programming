#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

struct P {
    int id, time;
    bool operator<(const P &p) const {
        return time == p.time ? id > p.id : time > p.time;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    // vector<int> a(m+1);
    map<int, int> tab;
    priority_queue<P, vector<P> > worker;
    set<pair<int, int>, greater<pair<int, int> > > S, SS; // tasks, who

    for (int i=1; i<=n; ++i) tab[i] = 0;
    for (int i=1; i<=m; ++i) {
        int x; cin >> x;
        tab[x]++;
    }

    int mn = 1e9, who;
    for (auto p: tab) {
        // S.insert({p.second.size(), p.first});
        if (p.second < mn) {
            mn = p.second;
            who = p.first;
        }
    }

    for (auto &p: tab) {
        int num = p.second - mn;
        if (num > 0) {
            S.insert({num, p.first});
        }
        p.second = num;
    }

    // re-number
    int no = 1;
    for (auto p: S) {
        SS.insert({p.first, no});
        tab[no] = p.first;
        ++no;
    }
    for (int i=no; i<=n; ++i) tab[i] = 0;

    for (int i=1; i<=n; ++i) {
        worker.push({i, mn});
    }

    while (SS.size()) {
        auto wor = worker.top(); worker.pop();
        auto &ta = tab[wor.id];
        // auto dem = S.begin()->second;
        int cnt = 0;
        while (ta && cnt < 2) {
            wor.time++;
            ++cnt;            
            ta--;
        }     

        if (cnt != 0) {
            auto it = SS.find({ta+cnt, wor.id});
            if (it->first-cnt > 0) 
                SS.insert({it->first-cnt, it->second});
            SS.erase(it);
        }       
        else {
            auto it = SS.begin();
            wor.time += 2;
            tab[it->second]--;
            if (it->first-1 > 0) 
                SS.insert({it->first-1, it->second});
            SS.erase(it);
        }
        worker.push(wor);
    }

    while (worker.size() > 1) {
        worker.pop();
    }
    cout << worker.top().time << '\n';
}

int main() {
    io;
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}