#include <bits/stdc++.h>

using namespace std;

const int MAGIC_BRUTE = 1e5;
const int MAGIC_CNT_STARTS = 2;
const int MAGIC_CNT_IT = 5;
const int SQRT4N = 10'000;

mt19937 rnd(1);

pair<int, int> pollard(int n) {
    for (int d = 2; d < min(n, MAGIC_BRUTE); ++d) {
        if (n % d == 0) {
            return {d, n / d};
        }
    }
    auto f = [&n] (__int128 x) {
        return (x * x + 1) % n;
    };
    for (int starts = 0; starts < MAGIC_CNT_STARTS; ++starts) {
        int x = rnd() % n, y = x;
        for (int it = 0; it < MAGIC_CNT_IT * SQRT4N; ++it) {
            x = f(x), y = f(f(y));
            int d = __gcd(n, x - y);
            if (1 < d && d < n && n % d == 0) {
                return {d, n / d};
            }
        }
    }
    return {0, 0};
}

int main() {
}

