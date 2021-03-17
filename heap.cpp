#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4e5;

struct Heap {
    vector <int> h, val, pos_in_heap;
    int sz;

    Heap() {
        sz = 0;
        h.assign(MAXN, -1);
        pos_in_heap.assign(MAXN, -1);
    };

    void heap_swap(int &a, int &b) {
        pos_in_heap[h[a]] = b;
        pos_in_heap[h[b]] = a;
        swap(h[a], h[b]);
        swap(a, b);
    }

    bool is_less(int i, int j) {
        return val[h[i]] < val[h[j]];
    }

    void sift_up(int i) {
        while (i > 1) {
            int p = i / 2;
            if (is_less(i, p)) {
                heap_swap(p, i);
            } else {
                break;
            }
        }
    }

    void sift_down(int i) {
        while (true) {
            int l = 2 * i, r = 2 * i + 1;
            if (l <= sz && (r > sz || is_less(l, r)) && is_less(l, i)) {
                heap_swap(i, l);
            } else if (r <= sz && is_less(r, i)) {
                heap_swap(i, r);
            } else {
                break;
            }
        }
    }

    void insert(int x) {
        h[++sz] = val.size();
        pos_in_heap[val.size()] = sz;
        val.push_back(x);
        sift_up(sz);
    }

    void erase(int i) {
        int a = i, b = sz;
        heap_swap(a, b);
        --sz;
        sift_up(i);
        sift_down(i);
    }

    void erase_for_pos(int i) {
        erase(pos_in_heap[i]);
    }

    pair <int, int> get() {
        int res = val[h[1]];
        int pos = h[1];
        erase(1);
        return {res, pos};
    }

    void print() {
        print(1);
    }

    void print(int v, string c = "") {
        if (v > sz) {
            return;
        }
        print(2 * v + 1, c + "   ");
        cout << c << "(" << v << " = " << pos_in_heap[h[v]] << " " << h[v] << " " << val[h[v]] << ")\n";
        print(2 * v, c + "    ");
    }

};

int main() {
}
