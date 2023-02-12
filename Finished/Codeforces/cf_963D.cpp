#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int K = 26; // size of alphabet
struct Node {
    int next[K]; // whether there is a child
    int link = -1, exit_link = -1; // the proper suffix linik
    int trans[K]; // actual transition
    int id = -1;

    Node() {
        memset(next, -1, sizeof(next));
        memset(trans, -1, sizeof(trans));
    }
};

vector<Node> tr(1);

int n;
string text, str[N];
vector<int> ask(N);
vector<int> pos[N]; // position of the last character of the matched string

void add_string(const string &s, int id) {
    int v = 0;
    for (char ch: s) {
        int c = ch - 'a';
        if (tr[v].next[c] == -1) {
            tr[v].next[c] = tr.size();
            tr[v].trans[c] = tr[v].next[c];
            tr.emplace_back();
        }
        v = tr[v].next[c];
    }
    tr[v].id = id;
}

void construct() {
    queue<int> que;
    que.push(0);
    tr[0].link = 0;
    for (int i = 0; i < K; ++i) {
        if (tr[0].trans[i] == -1) 
            tr[0].trans[i] = 0;
    }
    while (que.size()) {
        int v = que.front(); que.pop();
        for (int i = 0; i < K; ++i) {
            int u = tr[v].next[i];
            if (u == -1) 
                tr[v].trans[i] = tr[tr[v].link].trans[i];
            else {
                if (v == 0) tr[u].link = 0;
                else
                    tr[u].link = tr[tr[v].link].trans[i];
                que.push(u);
            }
        }
    }
}

// exit link
int exit_link(int v, int at) {
    if (v == 0) return 0;
    if (tr[v].exit_link != -1) 
        exit_link(tr[v].exit_link, at);
    else 
        tr[v].exit_link = exit_link(tr[v].link, at);
    int id = tr[v].id;
    if (id != -1) {
        pos[id].push_back(at);
        return v;
    }
    else return tr[v].exit_link;
}

void match() {
    int v = 0;
    for (int i = 0; i < text.size(); ++i) {
        int c = text[i] - 'a';
        int to = tr[v].trans[c];
        exit_link(to, i);
        v = to;
    }
}

int main() {
    cin >> text >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ask[i] >> str[i];
        add_string(str[i], i);
    }
    construct();
    match();
    for (int i = 0; i < n; ++i) {
        if (pos[i].size() < ask[i]) {
            cout << "-1\n";
            continue;
        }

        int len = 1e9 + 7;
        auto st = pos[i].begin(), ed = pos[i].begin() + ask[i] - 1;
        while (ed != pos[i].end()) {
            len = min(len, int(*ed - *st + str[i].size()));
            st++; ed++;
        }
        cout << len << '\n';
    }
    return 0;
}