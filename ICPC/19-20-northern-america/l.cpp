#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

string s;
int tar[30];
int sum[30];
int half;
vector<int> dig;

bool check(int d) {
    if (d == half) {
        if (tar[2 * d] == dig[d] * dig[d] % 10) 
            return true;
    }
    else if (tar[half + d] == (sum[half + d] + 2 * dig[d] * dig[half]) % 10)
        return true;
    return false;
}

vector<int> res;

bool dfs(int d) {
    if (d < 0) {
        for (int i=0; i<s.size(); ++i) {
            if (sum[i] % 10 != tar[i]) return false;
        }
        for (int i=0; i<=half; ++i) {
            res[i] = dig[i];
        }
        return true;
    }
    bool good = false;
    for (int x=0; x<10; ++x) {
        dig[d] = x;
        if (check(d)) {
            for (int i=half; i>d; --i) {
                sum[i + d] += 2* dig[i] * dig[d];
            }
            sum[2*d] += dig[d] * dig[d];

            good |= dfs(d - 1);
            if (good) return good;

            for (int i=half; i>d; --i) {
                sum[i + d] -= 2 * dig[i] * dig[d];
            }
            sum[2*d] -= dig[d] * dig[d];
        }
    }
    return good;
}

int main() {
    io;
    cin >> s;
    if (s.size() % 2 == 0) {
        cout << "-1\n";
        return 0;
    }
    for (int i=0; i<s.size(); ++i) {
        tar[s.size()-1-i] = s[i] - '0';
        // tar[i] = s[i] - '0';
    }
    half = s.size() / 2;
    dig.resize(half + 1);
    res.resize(half + 1);
    if (!dfs(half)) cout << "-1\n";
    else {
        reverse(res.begin(), res.end());
        for (auto x: res) cout << x;
    }
    return 0;
}