#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 505;

struct node {
    // vector<int> ischl, haschl;
    set<int> is, has;
} tree[N];

int n, m;
map<string, int> mp;
int cnt;

vector<string> strtok(string s) {
    s += ' ';
    int pos = 0;
    vector<string> slice;
    while((pos = s.find(" ")) != string::npos) {
        slice.push_back(s.substr(0, pos));
        s.erase(0, pos+1);
    }
    return slice;
}

int main() {
    io;
    cin >> n >> m; cin.ignore();

    for (int i=0; i<N; ++i) {
        tree[i].is.insert(i);
        tree[i].has.insert(i);
    }

    for (int i=0; i<n; ++i) {
        string s;
        getline(cin, s);
        auto v = strtok(s);
        string a = v[0], b = v[2], re = v[1];
        if (mp.find(a) == mp.end()) {
            mp[a] = cnt++;
        }
        if (mp.find(b) == mp.end()) {
            mp[b] = cnt++;
        }
        
        if (re[0] == 'i') {
            auto &ta = tree[mp[a]].is;
            auto &tb1 = tree[mp[b]].is, &tb2 = tree[mp[b]].has;
            auto ita1 = ta.begin(), ita2 = ta.end();
            auto itb11 = tb1.begin(), itb12 = tb1.end();
            auto itb21 = tb2.begin(), itb22 = tb2.end();
            set_union(ita1, ita2, itb11, itb12, inserter(ta, ita1));
            set_union(ita1, ita2, itb21, itb22, inserter(ta, ita1));
        }
        else {
            auto &ta = tree[mp[a]].has;
            auto &tb1 = tree[mp[b]].is, &tb2 = tree[mp[b]].has;
            auto ita1 = ta.begin(), ita2 = ta.end();
            auto itb11 = tb1.begin(), itb12 = tb1.end();
            auto itb21 = tb2.begin(), itb22 = tb2.end();
            set_union(ita1, ita2, itb11, itb12, inserter(ta, ita1));
            set_union(ita1, ita2, itb21, itb22, inserter(ta, ita1));
        }
    }
    for (int i=1; i<=m; ++i) {
        string s, a, b, re;
        getline(cin, s);
        vector<string> v = strtok(s);
        a = v[0], b = v[2], re = v[1];

        bool res;
        if (re[0] == 'i') {
            res = (tree[mp[a]].is.find(mp[b]) != tree[mp[a]].is.end());
        }
        else {
            res = (tree[mp[a]].has.find(mp[b]) != tree[mp[a]].has.end());
        }
        cout << "Query " << i << ": ";  
        if (res) cout << "true\n";
        else cout << "false\n";
    }
    return 0;
}