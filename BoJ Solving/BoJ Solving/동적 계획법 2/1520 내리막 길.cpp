#include <iostream>
#include <algorithm>
using namespace std;

int M, N, H = 0;
int arr[502][502];
int dp[502][502]; // dp[x][y] = z에서 z는 x, y에서 M, N까지 갈 수 있는 경우의 수

int depth(int x, int y)
{
	if (x == M && y == N)
	{
		return 1;
	}

	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = 0;

	// 상하좌우에서 갈 수 있는 방향으로 깊이 우선 탐색(DFS)를 한다.
	if (arr[x + 1][y] < arr[x][y])
	{
		dp[x][y] = dp[x][y] + depth(x + 1, y);
	}
	if (arr[x - 1][y] < arr[x][y])
	{
		dp[x][y] = dp[x][y] + depth(x - 1, y);
	}
	if (arr[x][y + 1] < arr[x][y])
	{
		dp[x][y] = dp[x][y] + depth(x, y + 1);
	}
	if (arr[x][y - 1] < arr[x][y])
	{
		dp[x][y] = dp[x][y] + depth(x, y - 1);
	}
	return dp[x][y];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;
	fill(&arr[0][0], &arr[M+1][N+1]+1, 10001); // 여유공간을 실제 사용할 공간에서 향하지 않게 하기 위해
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = -1; // -1은 아직 검사해보지 않은곳을 의미
		}

	H = depth(1, 1);

	cout << H;

	return 0;
}