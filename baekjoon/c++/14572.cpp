#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    long long d;
    cin >> n >> k >> d;

    vector<pair<long long, vector<int>>> v(n);
    for (int i = 0; i < n; i++) {
        int c;
        long long t;
        cin >> c >> t;
        v[i].first = t;
        v[i].second.resize(c);
        for (int j = 0; j < c; j++) {
            cin >> v[i].second[j];
        }
    }

    sort(v.begin(), v.end(), [](auto &a, auto &b) { return a.first < b.first; });

    vector<int> alg_count(k+1, 0);
    int cntKnown = 0;
    long long answer = 0;

    int left = 0;
    for (int right = 0; right < n; right++) {
        for (int alg : v[right].second) {
            if (alg_count[alg] == 0) {
                cntKnown++;
            }
            alg_count[alg]++;
        }

        while (v[right].first - v[left].first > d) {
            for (int alg : v[left].second) {
                alg_count[alg]--;
                if (alg_count[alg] == 0) {
                    cntKnown--;
                }
            }
            left++;
        }

        int windowSize = right - left + 1;

        int cntAllKnown = 0;
        for (int x = 1; x <= k; x++) {
            if (alg_count[x] == windowSize) {
                cntAllKnown++;
            }
        }

        long long score = (long long)(cntKnown - cntAllKnown) * windowSize;
        answer = max(answer, score);
    }

    cout << answer << "\n";
    return 0;
}
