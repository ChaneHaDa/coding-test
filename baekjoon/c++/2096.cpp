#include <iostream>
#include <algorithm>
using namespace std;

int map[100001][3] = {0,};
int minDp[3] = {0,};  // 1차원 배열로 변경 -> 다 저장 안하고 마지막만 저장
int maxDp[3] = {0,};  // 1차원 배열로 변경

int main() {
    int n;
    cin >> n;

    // 입력 받기
    for (int i = 1; i <= n; i++) {
        cin >> map[i][0] >> map[i][1] >> map[i][2];
    }

    // 초기 상태 설정 (첫 번째 집)
    minDp[0] = map[1][0];
    minDp[1] = map[1][1];
    minDp[2] = map[1][2];

    maxDp[0] = map[1][0];
    maxDp[1] = map[1][1];
    maxDp[2] = map[1][2];

    // 동적 계획법 계산
    for (int i = 2; i <= n; i++) {
        int prevMinDp[3] = {minDp[0], minDp[1], minDp[2]};
        int prevMaxDp[3] = {maxDp[0], maxDp[1], maxDp[2]};

        minDp[0] = map[i][0] + min(prevMinDp[0], prevMinDp[1]);
        minDp[1] = map[i][1] + min({prevMinDp[0], prevMinDp[1], prevMinDp[2]});
        minDp[2] = map[i][2] + min(prevMinDp[1], prevMinDp[2]);

        maxDp[0] = map[i][0] + max(prevMaxDp[0], prevMaxDp[1]);
        maxDp[1] = map[i][1] + max({prevMaxDp[0], prevMaxDp[1], prevMaxDp[2]});
        maxDp[2] = map[i][2] + max(prevMaxDp[1], prevMaxDp[2]);
    }

    int a1 = min({minDp[0], minDp[1], minDp[2]});
    int a2 = max({maxDp[0], maxDp[1], maxDp[2]});

    cout << a2 << " " << a1;

    return 0;
}
