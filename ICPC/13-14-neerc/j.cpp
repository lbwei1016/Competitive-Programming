/*
***DP***
    Solution:
        map<string, pair<int, int>> mp: mp[W] = {以 W 為結尾的最長對話長度, 該最長對話結尾處}
        vector<int> poi(n): poi[at] = 編號 at 的 mention 的上一則 mention 的編號
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+5;

int main(){
    freopen("join.in","r",stdin);
    freopen("join.out","w",stdout);
    
    int n; cin >> n; cin.ignore();
    int cnt = 1, mx = 1, who = 0;
    map<string, pair<int, int>> mp;
    vector<int> poi(n);
    iota(poi.begin(), poi.end(), 0);
    for (int i=0; i<n; ++i) {
        string s; 
        getline(cin, s);
        s += ' ';
        int at = s.find('@');
        int blk = s.find(' ');
        string say = s.substr(at, blk-at-1);
        if (mp.find(say) == mp.end()) {
            mp[say] = make_pair(1, i);
        }
        s.erase(0, blk+1);
        while ((at = s.find(' ')) != string::npos) {
            string men = s.substr(0, at);
            if (men[0] == '@' && men != say && mp.find(men) != mp.end()) {
                if (mp[men].first + 1 > mp[say].first) {
                    mp[say].first = mp[men].first + 1;
                    poi[i] = mp[men].second;
                    mp[say].second = i;
                    if (mp[men].first + 1 > mx) {
                        mx = mp[men].first + 1;
                        who = i;
                    }
                }
            }
            s.erase(0, at+1);
        }
    }

    cout << mx << '\n';
    vector<int> idx;
    while (true) {
        idx.push_back(who);
        if (poi[who] == who) break;
        who = poi[who];
    }
    reverse(idx.begin(), idx.end());
    for (auto x: idx) cout << x+1 << ' ';

    return 0;
}
/*
3
@a: jsdfkjl @v
@b: @a kjdl sdkj @addindex
@c: sjkj dkjf fjls @a

3
@a: sjdfsj @b @
@b: skjdfsj @b 
@c: dkjfj @b kdjf s a@

7
@Petr: Leaving for #NEERC tomorrow!
@Roman: This #NEERC is going to be awesome!
@Stone in forest: Nothing happened today.
@NEERCNews: @Petr Don’t forget an umbrella :)
@Lydia: @NEERCNews cares about @Petr - so cute ^ ^
@Lydia: @Lydia @NEERCNews @Petr it won’t be raining though!
@Petr: @Lydia goog
*/