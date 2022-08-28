#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    // io;
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        char a[n+1], b[m+1];
        scanf("%s\n%s", a, b);
        sort(a, a+n); sort(b, b+m);
        char *pa = a, *pb = b;

        string c;     
        int cnt = 0, cntp = 0;
        while (true) {
            if (*pa == '\0' || *pb == '\0') break;

            if (cntp == k) {
                c.push_back(*(pa++));
                ++cnt;
            }

            while (cnt<k && *pa!='\0' && *pa<*pb) {
                c.push_back(*(pa++));
                ++cnt;
            }
            swap(pa, pb);
            cntp = cnt;
            cnt = 0;
        }
        cout << c + '\n';
    }
    return 0;
}