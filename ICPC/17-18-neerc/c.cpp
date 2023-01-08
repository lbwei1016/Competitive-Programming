#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using ll = long long;

int tab[26][26];
string vow = "aeiouwy";

int main() {
    io;
    string s; cin >> s;
    for (int i=0; i<s.size()-1; ++i) {
        // con
        int c = s[i] - 'a';
        if (vow.find(s[i]) == string::npos) {
            tab[c][s[i+1]-'a']++;
            tab[s[i+1]-'a'][c]++;
        }
    }

    vector<int> v;
    for (int i=0; i<26; ++i) {
        if (vow.find('a'+i) == string::npos)
            v.push_back(i);
    }

    ll cnt = 0, ans = 0;
    int rec = 0;
    for (int i=0; i<(1<<26); ++i) {
        for (auto j: v) {
            for (auto k: v) {
                if (j == k) continue; 
                // if (tab[j][k] == 0) continue;
                if (((i >> j) & 1) ^ ((i >> k) & 1)) cnt += tab[j][k];
            }
        }
        if (cnt > ans) {
            ans = cnt;
            rec = i;
        }
        cnt = 0;
    }
    // cout << ans / 2 << '\n';
    for (auto c: s) {
        int k = c - 'a';
        if ((rec >> k) & 1) cout << char('A'+k);
        else cout << c;
    }
    return 0;
}