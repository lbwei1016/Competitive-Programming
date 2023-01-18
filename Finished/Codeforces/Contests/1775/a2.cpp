#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    io;
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        if (s.front() == s.back()) {
            cout << s.front() << " " + s.substr(1, s.size()-2) + " " << s.back() << '\n';
            continue;
        }
        else if (s.front() == 'b') {
            bool good = false;
            for (int i=1; i<s.size()-1; ++i) {
                if (s[i] == 'a') {
                    good = true;
                    // cout << "s.front(): " << s.front() << "\n";
                    // cout << s.front() << " " + s.substr(i, s.size() - i - 1) + " " << s.back() << "\n";
                    cout << s.substr(0, i) + " a " + s.substr(i + 1, s.size() - i - 1) + "\n";
                    break;
                }
            }
            if (!good) {
                cout << "b b " + s.substr(2, s.size() - 2) + '\n';
            }
        }
        else if (s.front() == 'a') {
            bool good = false;
            for (int i=1; i<s.size()-1; ++i) {
                if (s[i] == 'a') {
                    good = true;
                    cout << s.substr(0, i) + " a " + s.substr(i + 1, s.size() - i - 1) + "\n";
                    break;
                }
            }
            if (!good) {
                cout << "a " + s.substr(1, s.size() - 2) + " " + "b\n";
            }
        }
    }
    return 0;
}