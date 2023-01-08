#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

string a, b;
int n, mid;

inline int rev(int x) {
    return n - x;
}

int solve() {
    if (a[mid] != b[mid]) return -1;
    int res = 0;
    int pa = 0, pb = 0;
    bool revd = false;
    for (int i=0; i<mid; ++i) {
        if (a[pa] != b[pb]) {
            if (a[pa] == b[rev(pb)] && a[rev(pa)] == b[pb]) {
                pa = rev(pa);
                // pb = rev(pb);
                revd ^= 1;
                res++;
            }  
            else return -1;
        }
        else if (a[rev(pa)] != b[rev(pb)]) return -1;
        
        if (revd) {
            // pa--; pb--;
            pa--; pb++;
        }
        else {
            pa++; pb++;
        }
    }
    return res;
}

int main() {
    io;
    int t; cin >> t;
    while (t--) {
        cin >> a >> b;
        n = a.size() - 1;
        mid = a.size() / 2;
        cout << solve() << '\n';
    }    
    return 0;
}
/*
3
ebcbdaa
abcbdae
eadbcba
abcbdae
eadbcba
abcbdae
*/