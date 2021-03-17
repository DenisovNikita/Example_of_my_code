#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100'000;

vector<int> gr[MAXN];
vector<int> col;
vector<int> order;

bool has_cycle;

void dfs(int v) {
    col[v] = 1;
    for (int u : gr[v]) {
        if (!col[u]) {
            dfs(u);
        } else if (col[u] == 1) {
            has_cycle = 1;
        }
    }
    col[v] = 2;
    order.push_back(v);
}

void get_topsort() {
    // init n, gr
    has_cycle = 0;
    col.assign(n, 0);
    order.clear();
    for (int r = 0; r < n; ++r) {
        if (!col[r]) {
            dfs(r);
        }
    }
    if (has_cycle) {
        // No topsort
        return;
    }
    reverse(order.begin(), order.end());
    // topsort is order
}

int main() {
}

