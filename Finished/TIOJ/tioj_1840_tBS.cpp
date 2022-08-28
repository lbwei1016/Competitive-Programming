/*
***Total Binary Search***
    Description:
        區間第 K 小。
    Solution:
        整體二分，精神是: 與其個別二分，不如大家一起二分。
        依照慣例，先考慮靜態。
        假設題目簡化至只有一次查詢；從二分搜的想法，我們可以計算每個前綴區間
        小於等於 mid 的數量: 若 [l, r] 內小於等於 mid 的數量小於 K，代表 mid 
        太小，所以答案在 mid 的右方，反之左方。但是，對於每個 mid 都要計算一
        次所有前綴太花時間了；這樣的資訊其實可以保留:
            假設 [l, r] 中小於等於 mid 的數量 C >= K，也就是說 mid 太大了；要往
            左邊搜尋之前，我們可以將序列中小於等於 mid 的數值保留往左邊送就好，
            其餘捨棄，因為他們無法對接下來的計算做出貢獻 (mid 只會變更小)。如果
            是 C < K 的情形，我們可以依樣畫葫蘆，只把大於 mid 的數值往右邊送；但
            此時要記得將 K 減去 C (類似 treap 在依左子樹大小搜索的時候)。
            
            說這麼多，"往左邊送"是什麼意思? 
            因要動態計算前綴，我們採用 BIT。如果 A[i] <= x，BIT[i] = 1，否則 BIT[i] = 0；
            所以 C 其實就是區間和而已。如果我們在每次二分搜開始時，在 BIT 上標記 A[i] 
            的資訊，二分搜結束後，將本次標記的資訊全部移除。於是"往左 (右) 邊送"，就是將 
            "還要標記的 A[i]" 保留至下次二分搜。如此一來，A[i] 最多被標記 O(log n) 次 (二分
            搜深度)，而每次標記需 O(log n)，於是計算前綴的時間花費是 O(nlog^2(n))。

        現在考慮動態。
        我們可以把每次修改看成是 "移除並加入"，而原序列元素 A[i] 也可以看作要一個個加入 BIT 的
        資訊 (可以說是"往中間送"(?))。

        總而言之，將所有操作都視為一個"事件"，並把事件依序加入一佇列(簡單想就好)中(確保依序執行)
        、對所有事件同時二分搜 (不斷送到左或右邊)。
    Complexity:
        序列本身計算: O(nlog^2(n))
        查詢: O(log n) 次二分搜，每次二分搜花 O(log n)，共 O(qlog^2(n))
        Overall: O((n+q)log^2(n))
    Note:
        記得離散化。這裡是左閉右閉。
    Comparison:
        Space:
            比起 BIT 套持久化線段樹的 O(q + nlog(n)) 空間，整體二分只需線性。
        Time:
            靜態解複雜度略差、動態解複雜度一樣，但常數小的多。
*/
#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int MAX_N = 5e4 + 5;
const int MAX_M = 1e4 + 5;
// event
struct Operator {
    // l == -1: 題目的特殊條件
    // l == -2: 在 r 的位置加入 k 
    // l == -3: 在 r 的位置移除 k 
    // else: 查詢 [l, r] 的第 k 小元素
    int l, r, k, ans;
} op[MAX_N + MAX_M * 2];

int A[MAX_N], bit[MAX_N], n, q;

void add(int i, int val) {
    for (; i<=n; i+=(i&-i)) bit[i] += val;
}

int sum(int i) {
    int res = 0;
    for (; i>0; i-=(i&-i)) res += bit[i];
    return res;
}

void update_op(int x, vector<int> &V, int type, bool modifyAns) {
    for (auto &i: V) {
        if (op[i].l == -2) {
            if (op[i].k <= x) add(op[i].r, type);
        }
        else if (op[i].l == -3) {
            if (op[i].k <= x) add(op[i].r, -type);
        }
        else if (modifyAns) {
            // 這裡 op[i].ans 是 [l, r] 內小於等於 x 的數量
            op[i].ans = sum(op[i].r) - sum(op[i].l - 1);
        }
    }   
}

void divid(int x, vector<int> &V, vector<int> &LV, vector<int> &RV) {
    for (auto &i: V) {
        if (op[i].l < 0) {
            if (op[i].k <= x) LV.push_back(i);
            else RV.push_back(i);
        }
        else {
            // 太多了，所以要放左邊
            if (op[i].ans >= op[i].k) LV.push_back(i);
            else {
                RV.push_back(i);
                // 因為會 undo，所以先減去已經確定小於等於目前 x 的數量
                op[i].k -= op[i].ans; 
            }
        }
    }
    vector<int>().swap(V); // totally erase V
}
// [l, r]
void total_binary_search(int l, int r, vector<int> &V) {
    if (V.empty()) return;
    if (r == l) {
        for (auto &i: V) op[i].ans = l;
        return;
    }
    int mid = (l + r) / 2;
    update_op(mid, V, 1, true); // do
    vector<int> LV, RV;
    divid(mid, V, LV, RV); // 分左右
    update_op(mid, LV, -1, false); // undo，但這裡操作的是 LV
    /*
        為甚麼操作的是 LV ?
        因為 update_op() 只有當 op[i].k <= x 時才會動作，而所有 op[i].k <= x 的
        i 都被分配到 LV 中。
    */

    total_binary_search(l, mid, LV);
    // update_op(mid,LV,1,false); 不可以把註解拿掉 (不然可能會忘記整體二分的原貌(?))
    total_binary_search(mid+1, r, RV);
    // update_op(mid,LV,-1,false);
}

int main() {
    io;
    int t; cin >> t;
    while (t--) {
        cin >> n >> q;
        int pt = 0;
        vector<int> all;
        memset(bit + 1, 0, sizeof(int)*n);
        for (int i=1; i<=n; ++i) {
            cin >> A[i];
            op[pt++] = {-2, i, A[i], 0};
            all.push_back(A[i]);
        }

        int type, a, b, c;
        while (q--) {
            cin >> type >> a >> b;
            if (type == 1) {
                cin >> c;
                op[pt++] = {a, b, c, 0};
            }
            else if (type == 2) {
                op[pt++] = {-3, a, A[a], 0};
                op[pt++] = {-2, a, b, 0};
                A[a] = b;
                all.push_back(b);
            }
            else {
                op[pt++] = {-1, a, b, 7122};
            }
        }

        sort(all.begin(), all.end());
        all.resize(unique(all.begin(), all.end()) - all.begin());

        vector<int> V;
        for (int i=0; i<pt; ++i) {
            auto &p = op[i];
            if (p.l == -1) continue; // no need to proceed
            V.push_back(i); // 準備二分搜
            if (p.l > 0) continue; // l > 0: query
            // discretization
            p.k = lower_bound(all.begin(), all.end(), p.k) - all.begin();
        }
        // [l, r]
        // 因離散化了，所以 (l, r) = (0, all.size()-1)
        total_binary_search(0, all.size()-1, V);
        for (int i=n; i<pt; ++i) {
            if (op[i].l == -1) 
                cout << op[i].ans << '\n';
            else if (op[i].l > 0) 
                cout << all[op[i].ans] << '\n';
        }
    }
    return 0;
}