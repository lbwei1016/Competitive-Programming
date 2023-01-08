#include <bits/stdc++.h>
// #define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;    

const int MH = 105;
// char G[MH][MH];
bool waterH[MH], waterW[MH];
int W, H;

bool rec(int h, int w, int n, int hoff, int woff) {
    if (n == 0) return 1;
    if (h <= 2 && w <= 2) return n == 0;

    bool res = 0;
    // if (h >= 3 && w >= 3) {
    //     for (int i=0; i<W; ++i) G[hoff+1][i] = '#';
    //     for (int i=0; i<H; ++i) G[i][woff+1] = '#';
    //     res = rec(h-2, w-2, n-3-(hoff/2)-(woff/2), hoff+2, woff+2);    
    //     if (res) return 1;
    //     for (int i=0; i<W; ++i) G[hoff+1][i] = '.';
    //     for (int i=0; i<H; ++i) G[i][woff+1] = '.';
    // }

    if (h >= 3) {
        // vector<int> tag;
        // for (int i=0; i<W; ++i) {
        //     if (G[hoff+1][i] == '.') tag.push_back(i);
        //     G[hoff+1][i] = '#';
        // }
        waterH[hoff+1] = 1;
        res = rec(h-2, w, n-1-(woff/2), hoff+2, woff);
        if (res) return 1;
        // for (auto i: tag) G[hoff+1][i] = '.';
        waterH[hoff+1] = 0;
    }   
    if (w >= 3) {
        // vector<int> tag;
        // for (int i=0; i<H; ++i) {
        //     if (G[i][woff+1] == '.') tag.push_back(i);
        //     G[i][woff+1] = '#';
        // }
        waterW[woff+1] = 1;
        res = rec(h, w-2, n-1-(hoff/2), hoff, woff+2);
        if (res) return 1;
        // for (auto i: tag) G[i][woff+1] = '.';
        waterW[woff+1] = 0;
    }

    return 0;
}

int main() {
    freopen("kotlin.in", "r", stdin);
    freopen("kotlin.out", "w", stdout);
    // io;
    int n;
    // cin >> H >> W >> n;
    scanf("%d %d %d", &H, &W, &n);
    // memset(G, '.', sizeof(G));  
    // cout << rec(h, w, n, 0, 0) << '\n';
    bool res = rec(H, W, n-1, 0, 0);
    if (res) {
        for (int i=0; i<H; ++i) {
            for (int j=0; j<W; ++j) {
                if (waterH[i] || waterW[j])
                    printf("%c", '#');
                else putchar('.');
            }
            if (i < H-1)
                puts("");
        }
    }
    else printf("Impossible");

    return 0;
}