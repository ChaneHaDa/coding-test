#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int N, K;
int visit[500001][2];
queue<pair<int, int>> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	visit[N][0] = true;
	q.push({ N,0 });

	while (!q.empty())
	{
		int now = q.front().first;
		int time = q.front().second;
		int pos = K + time * (time + 1) / 2;
		q.pop();

		if (pos > 500000)
		{
			cout << -1 << '\n';
			break;
		}

		if (now == pos || visit[pos][time%2])
		{
			cout << time << '\n';
			break;
		}
	
		for (int next : {now - 1, now + 1, 2 * now})
		{
			if (next >= 0 && next <= 500000 && !visit[next][(time+1)%2])
			{
				q.push({ next,time + 1 });
				visit[next][(time+1)%2] = true;
			}
		}

	}
}