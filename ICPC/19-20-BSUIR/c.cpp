#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

string s0, s1;
bool check(int p0, int p1, bool st) {
    while (s0[p0] == s1[p1]) {
        p0++; p1++;
        if (max(p0, p1) == s0.size()) {
            return true;
        }
    }
    if (st == 0) p1++;
    else p0++;
    while (p0 < s0.size() && s0[p0] == s1[p1]) {
        p0++; p1++;
    }
    return p0 == s0.size();
}

int main() {
    io;
    cin >> s0 >> s1;
    int p0 = 0, p1 = 0;
    int at = 0;
    while (s0[p0] == s1[p1]) {
        p0++; p1++;
        if (p0 == s0.size()) {
            cout << s0 + 'a' + '\n';
            return 0;
        }
    }
    at = p0;
    bool res = check(p0 + 1, p1, 0);
    if (res) {
        string s = s1.insert(at, 1, s0[at]);
        cout << s + '\n';
    }
    else {
        res = check(p0, p1 + 1, 1);  
        if (res) {
            string s = s0.insert(at, 1, s1[at]);
            cout << s + '\n';
        }
        else cout << "IMPOSSIBLE\n";
    } 

    return 0;
}
/*
sdjhfshfsh
sdhfshfsh
sdjhfhfsh
*/