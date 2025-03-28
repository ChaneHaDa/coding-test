#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1000001;  // n이 1,000,000까지 가능

// 부모 배열과 랭크 배열을 전역 또는 동적 할당
int parent[MAX_N];
int rankArr[MAX_N];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);  // 경로 압축
    return parent[x];
}

void union_node(int x, int y) {
    int pX = find(x);
    int pY = find(y);
    if (pX == pY) return;
    // Union by rank: 낮은 랭크를 높은 랭크에 붙임
    if (rankArr[pX] < rankArr[pY]) {
        parent[pX] = pY;
    } else if (rankArr[pX] > rankArr[pY]) {
        parent[pY] = pX;
    } else {
        parent[pY] = pX;
        rankArr[pX]++;
    }
    // parent[pX] = pY; 
}

bool isUnion(int x, int y) {
    return find(x) == find(y);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 초기화: 1부터 n까지 각 원소는 자기 자신을 부모로, rank는 0
    for (int i = 1; i <= n; i++){
        parent[i] = i;
        rankArr[i] = 0;
    }

    int op, a, b;
    while (m--) {
        cin >> op >> a >> b;
        if (op == 0) {  // 합집합 연산
            union_node(a, b);
        } else {       // 두 원소가 같은 집합에 속하는지 확인
            cout << (isUnion(a, b) ? "YES" : "NO") << "\n";
        }
    }

    return 0;
}
