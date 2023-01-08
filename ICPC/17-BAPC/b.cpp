#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const double EPS = 1e-7, INF = 1e18;
struct P {
    double x, y, r;
    P operator+(P &p) {
        return P{x+p.x, y+p.y, r};
    }
    P operator-(P &p) {
        return P{x-p.x, y-p.y, r};
    }
    P operator/(double d) {
        return P{x / d, y / d, r};
    }
    P operator*(double d) {
        return P{x * d, y * d, r};
    }
};

P S, T;
int n;
vector<P> she, point;
map<int, vector<int>> mp;
vector<int> s_at, t_at;

double dist2(int i, int j) {
    P diff = she[i] - she[j];
    return diff.x*diff.x + diff.y*diff.y;
}

double norm(P p) {
    return sqrt(p.x*p.x + p.y*p.y);
}

P rotat(P vec, double ang, bool clk) {
    double sn = sin(ang), cs = cos(ang);
    if (clk) sn *= (-1);
    return P{cs*vec.x - sn*vec.y, sn*vec.x + cs*vec.y};
}

void inter(int i, int j) {
    double dis2 = dist2(i, j);
    double r1 = she[i].r, r2 = she[j].r;
    double rdis2 = (r1 + r2)*(r1 + r2);
    if (dis2 > rdis2) return;
    if (abs(dis2 - rdis2) < EPS) {
        P vec = she[j] - she[i];
        P cut = vec / norm(vec) * r1;
        mp[i].push_back(point.size());
        mp[j].push_back(point.size());
        point.push_back(cut + she[i]);
        return;
    }

    double hor = (r1*r1 - r2*r2 + dis2) / (2.0*sqrt(dis2));
    double ang = acos(hor / r1);

    P vec = she[j] - she[i];
    P rv1 = rotat(vec, ang, 0), rv2 = rotat(vec, ang, 1);
    rv1 = rv1 / norm(vec) * r1; rv2 = rv2 / norm(vec) * r1;

    int sz = point.size();
    mp[i].push_back(sz); mp[i].push_back(sz+1);
    mp[j].push_back(sz); mp[j].push_back(sz+1);
    point.push_back(rv1 + she[i]); point.push_back(rv2 + she[i]);
}

vector<vector<double>> dis;

double calc() {
    int sz = point.size();
    dis.resize(sz, vector<double>(sz, 1e18));
    for (int i=0; i<sz; ++i) {
        for (int j=0; j<sz; ++j) {
            if (dis[i][j] == INF) 
                dis[j][i] = dis[i][j] = norm(point[i] - point[j]);
            for (int k=0; k<sz; ++k) {
                if (dis[i][k] == INF)
                    dis[k][i] = dis[i][k] = norm(point[i] - point[k]);
                if (dis[k][j] == INF)
                    dis[k][j] = dis[j][k] = norm(point[j] - point[k]);
                dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
            }
        }
    }

    double mn = INF;
    for (auto u: s_at) {
        auto pts = mp[u];
        for (auto i: pts) {
            for (auto v: t_at) {
                auto ptt = mp[v];
                for (auto j: ptt) {
                    double d1 = norm(point[i] - S);
                    double d2 = norm(point[j] - T);
                    mn = min(dis[i][j] + d1 + d2, mn);
                }
            }
        }
    }
    return mn;
}

int main() {
    // io;
    // scanf("%lf %lf %lf %lf", &S.x, &S.y, &T.x, &T.y);
    // scanf("%d", &n);
    she.resize(n);
    for (int i=0; i<n; ++i) {
        double x, y, r;
        // scanf("%lf %lf %lf", &x, &y, &r);
        she[i] = P{x, y, r};
    }

    for (int i=0; i<n; ++i) {
        P p = P{S.x - she[i].x, S.y - she[i].y, 0};
        double d = norm(p);
        if (d < she[i].r || abs(d-she[i].r) < EPS) 
            s_at.push_back(i);
        p = P{T.x - she[i].x, T.y - she[i].y, 0};
        d = norm(p);
        if (d < she[i].r || abs(d-she[i].r) < EPS) 
            t_at.push_back(i);
    }

    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            inter(i, j);
        }
    }

    double res = calc();
    if (res == INF) puts("impossible");
    else printf("%.8lf", res);
    
    return 0;
}