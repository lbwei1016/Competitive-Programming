/*
    Description:
        給一規則，在必須符合該規則的情況下，問給定字串是否只有一種可能。
    Solution:
        首先依照規則，建構出"最佳"情形(左方的 '?' 優先替換成 '('，剩下的 '?' 才換成 ')')，
        再想辦法找出第二種符合規則的排序。最可能依舊符合規則的改變是:
            將最後一個 '?' 換成 '(' 的字元與第一個 '?' 換成 ')' 的字元對調
        若字串經此變換後無法符合規則，則此字串為唯一(因為這是代價最小的變動了，若這都沒辦法，
        則不可能再有符合規則的)，反之則非。
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

bool RBS(string s) {
    int cnt = 0;
    for (auto c: s) {
        if (c == '(') ++cnt;
        else if (c == ')') --cnt;
        if (cnt < 0) return false;
    }
    return true;
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int n = s.size();
        int op = n / 2, cl = n / 2;
        vector<int> qmark;
        for (int i=0; i<n; ++i) {
            if (s[i] == '(') --op;
            else if (s[i] == ')') --cl;
            else qmark.push_back(i);
        }
        for (int i=0; i<qmark.size(); ++i) {
            if (i < op) s[qmark[i]] = '(';
            else s[qmark[i]] = ')';
        }

        bool ok = true;
        if (op > 0 && cl > 0) {
            swap(s[qmark[op-1]], s[qmark[op]]);
            ok = !RBS(s);
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}