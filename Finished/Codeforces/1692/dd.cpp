#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

bool palin(string s) {
    for (int i=0; i<s.size()/2; ++i) {
        if (s[i] != s[s.size()-1-i]) return false;
    }
    return true;
}

int toint(string s) {
    return 10*(s[0]-'0') + s[1]-'0';
}

int main() {
    io;
    int t;
    cin >> t;
    while (t--) {
        string time;
        int x, ans = 0;
        cin >> time >> x;
        set<string> S;
        while (!S.count(time)) {
            S.insert(time);
            ans += palin(time);
            string H = time.substr(0, 2), M = time.substr(3, 2);
            int iH = toint(H), iM = toint(M);
            int car = (iM + x) / 60; 
            iM = (iM + x) % 60;
            iH = (iH + car) % 24;
            time[1] = iH%10 + '0'; iH /= 10;
            time[0] = iH + '0';
            time[4] = iM%10 + '0'; iM /= 10;
            time[3] = iM + '0';
        }
        cout << ans << '\n';
    }
    return 0;
}