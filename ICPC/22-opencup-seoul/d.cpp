#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 1e6 + 5;
struct P {
    int x, y, v;
};
multiset<int, greater<int>> vx, vy;
vector<int> px[N], py[N];
vector<int> xsum(N), ysum(N);

int main() {
    io;
    int n; cin >> n;
    vector<P> arr(n);
    for (int i=0; i<n; ++i) {
        int x, y, v; cin >> x >> y >> v;
        arr[i] = P{x, y, v};
        px[x].push_back(i); xsum[x] += v; 
        py[y].push_back(i); ysum[y] += v;
    }
    for (int i=0; i<N; ++i) {
        if (xsum[i] > 0) vx.insert(xsum[i]);
        if (ysum[i] > 0) vy.insert(ysum[i]);
    }

    int res = 0, sum = 0, cnt = 0;
    for (auto x: vx) {
        if (cnt++ == 3) break;
        sum += x;
    }
    res = max(res, sum); sum = cnt = 0;
    for (auto y: vy) {
        if (cnt++ == 3) break;
        sum += y;
    }
    res = max(res, sum); sum = cnt = 0;

    for (int i=0; i<N; ++i) {
        sum = xsum[i];
        for (auto id: px[i]) {
            vy.erase(vy.find(ysum[arr[id].y]));
            ysum[arr[id].y] -= arr[id].v;
            vy.insert(ysum[arr[id].y]);
        }

        for (auto val: vy) {
            if (cnt++ == 2) break;
            sum += val;
        }
        res = max(res, sum); sum = cnt = 0;

        for (auto id: px[i]) {
            vy.erase(vy.find(ysum[arr[id].y]));
            ysum[arr[id].y] += arr[id].v;
            vy.insert(ysum[arr[id].y]);      
        }
    }

    for (int i=0; i<N; ++i) {
        sum = ysum[i];
        for (auto id: py[i]) {
            vx.erase(vx.find(xsum[arr[id].x]));
            xsum[arr[id].x] -= arr[id].v;
            vx.insert(xsum[arr[id].x]);
        }
        
        for (auto val: vx) {
            if (cnt++ == 2) break;
            sum += val;
        }
        res = max(res, sum); sum = cnt = 0;

        for (auto id: py[i]) {
            vx.erase(vx.find(xsum[arr[id].x]));
            xsum[arr[id].x] += arr[id].v;
            vx.insert(xsum[arr[id].x]);      
        }
    }
    cout << res << '\n';
    return 0;
}