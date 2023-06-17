#include <iostream>
#include <algorithm>
using namespace std;

int M, N, H = 0;
int arr[502][502];
int dp[502][502]; // dp[x][y] = z���� z�� x, y���� M, N���� �� �� �ִ� ����� ��

int depth(int x, int y)
{
	if (x == M && y == N)
	{
		return 1;
	}

	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = 0;

	// �����¿쿡�� �� �� �ִ� �������� ���� �켱 Ž��(DFS)�� �Ѵ�.
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
	fill(&arr[0][0], &arr[M+1][N+1]+1, 10001); // ���������� ���� ����� �������� ������ �ʰ� �ϱ� ����
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = -1; // -1�� ���� �˻��غ��� �������� �ǹ�
		}

	H = depth(1, 1);

	cout << H;

	return 0;
}