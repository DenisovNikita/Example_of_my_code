#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20'000;

struct Edge {
    int to, idx;
};

vector<Edge> gr[MAXN];
vector<int> tin, tup, used;
set<int> bridges;

void dfs(int v, int idx_parent) {
    static int timer = 0;
    tup[v] = tin[v] = timer++;
    used[v] = 1;
    for (auto [u, idx] : gr[v]) {
        if (!used[u]) {
            dfs(u, idx);
            tup[v] = min(tup[v], tup[u]);
            if (tin[v] < tup[u]) {
                bridges.insert(idx);
            }
        } else if (idx != idx_parent) {
            tup[v] = min(tup[v], tin[u]);
        }
    }
}

int main() {
}

