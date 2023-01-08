#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int A[505], B[505];
int n;

bool check() {
    for (int i=0; i<n; ++i) {
        if (A[i] != B[i]) return false;
    }
    return true;
}

struct P {
    int l, r;
    bool inc;
};

int main() {
    io;
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> A[i];
    }
    for (int i=0; i<n; ++i) {
        cin >> B[i];
    }

    if (check()) {
        cout << "0\n";
        return 0;
    }
    sort(A, A+n);

    vector<P> res;
    res.push_back({0, n-1, 1});
    for (int i=0; i<n; ++i) {
        int at;
        bool inc = true;
        for (int j=i; j<n; ++j) {
            if (A[j] == B[i]) {
                at = j;
                break;
            }
            if (A[j] < A[j+1]) {
                inc = false;
            }
            else inc = true;
        }
        // if (i == 0 && at != 0) inc = false;
        if (at == i) {
            if (check()) break;
            continue;
        }
        if (inc) {
            sort(A+i, A+at+1);
        }
        else {
            sort(A+i, A+at+1, [](int a, int b) {
                return a > b;
            });  
        } 
        res.push_back({i, at, inc});
        if (check()) break;
    }

    cout << res.size() << '\n';
    for (auto p: res) {
        cout << p.l + 1 << ' ' << p.r + 1 << (p.inc ? " I\n" : " D\n");
    }  
    return 0;
}