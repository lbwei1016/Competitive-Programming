#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

struct Pr {
    int ty, val;
};

int n, k; 
int cnt;
void act(int n, vector<Pr> &P, bool flag) {
    for (int i=0; i<P.size(); ++i) {
        if (flag && i == n) return;
        if (cnt >= k) return;
        ++cnt;
        if (P[i].ty == 0) printf("%c", P[i].val);
        else if (P[i].ty == 1) {
            P.push_back(Pr{2, P[i].val});
        }
        else {
            --cnt;
            act(P[i].val, P, 1);
        }  
    }
}

int main() {
    scanf("%d %d", &n, &k);
    vector<Pr> P(n);
    for (int i=0; i<n; ++i) {
        // string s; 
        char s[30];
        char c;
        // cin >> s >> x;
        scanf("%s %c", s, &c);
        if (s[0] == 'e') {
            P[i] = {0, int(c)};
        }
        else {
            P[i] = {1, c - '0'};
        }
    }

    act(n, P, 0);

    return 0;
}
/*
abaabaaabaaaabaaaaab
abaabaaabaaaabaaaaab

abaababaaababaababaaaa
abaababaaababaababaaaa
*/