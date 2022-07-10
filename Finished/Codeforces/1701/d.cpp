/*
***Order / Greedy*** (*)
    Description:
        After translation, there are "n" positions, each of which has a 
        range indicating integers it can hold; for instance, "position 1" 
        can hold a integer in "[2, 5]". We need to assign integr 1 to n to 
        each of the position so that the integers in all position makes for 
        a "permutation of n".
    Solution:
        For any range with fewer numbers available, e.g. many numbers in the range 
        has been picked, it (the range) has higher priority to fetch a number; this 
        is the greedy part.

        We first sort all the ranges according to their left boundries: less goes first.
        Then, we iterate from 1 to n, meaning to choose a range for 1, for 2, ..., and 
        finally for n. Since the left boundry is non-decreasing, we can choose one among 
        the prefix of the sorted ranges. When is comes to making choices, the greedy rule 
        established above is just what we need.

        Which position has the least numbers available? The one whose range has the minimum 
        right boundry does, for "numbers availble = (right - left + 1)", and currently all
        left bounds are the same! (non-decreasing, prefix). Case closed.
    Complexity:
        Worst case: O(nlogn)
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

// 這兩個 structure 可以改成 pair 就好，這裡只是為了清楚說明 pair 內容為何
struct P {
    int left, who;
    bool operator<(const P &p) const {
        return left < p.left;
    }
};

struct PP {
    int right, who;
    bool operator<(const PP &p) const {
        // 必須 specify "right == p.right" 的情形，否則要用 multiset
        return right == p.right ? who < p.who : right < p.right;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> b(n+1), a(n);
    vector<P> lv(n);
    for (int i=1; i<=n; ++i) {
        cin >> b[i];
        lv[i-1] = {i/(1+b[i]) + 1, i};
    }
    sort(lv.begin(), lv.end());

    set<PP> S;
    for (int i=1, j=0; i<=n; ++i) {
        while (j<n && lv[j].left == i) {
            int who = lv[j].who;
            S.insert({b[who] ? who/b[who] : n, who});
            ++j;
        }
        int at = S.begin()->who;
        a[at-1] = i;
        S.erase(S.begin());
    }

    for (auto x: a) cout << x << ' ';
    cout << '\n';
}

int main() {
    io;
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}