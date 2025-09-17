#include <bits/stdc++.h>
using namespace std;

int p[1000000];

inline int ind(int i, int j, int m) {
    return i * m + j; // ← 핵심 수정
}

void init(int total) {
    for (int i = 0; i < total; ++i) p[i] = i;
}

int findp(int x) {
    if (p[x] == x) return x;
    return p[x] = findp(p[x]);
}

void unite(int x, int y) {
    x = findp(x); y = findp(y);
    if (x != y) p[x] = y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 안전: n*m 이 1,000,000 이하인지 확인(필요시 지우거나 assert로 대체)
    // if (1LL * n * m > 1000000) return 0;

    vector<string> str(n);
    for (int i = 0; i < n; ++i) cin >> str[i];

    init(n * m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int ni = i, nj = j;
            char ch = str[i][j];
            if (ch == 'U') ni -= 1;
            else if (ch == 'R') nj += 1;
            else if (ch == 'L') nj -= 1;
            else if (ch == 'D') ni += 1;

            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

            unite(ind(i, j, m), ind(ni, nj, m));
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int id = ind(i, j, m);
            if (p[id] == id) ++ans;   // 루트 개수 = 컴포넌트 수
        }
    }

    cout << ans << '\n';
    return 0;
}
