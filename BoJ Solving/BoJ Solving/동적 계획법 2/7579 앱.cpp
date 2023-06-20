#include <iostream>
#include <algorithm>
using namespace std;

int N, M, ans, sum;
int bite[101], cost[101];
int dp[101][10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) cin >> bite[i];
	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i];
		// sum : ��� ����� ��
		sum += cost[i];
	}

	// dp[i][j] == i��° �۱��� Ž������ ��
	// j����� �Ҹ��ؼ� ���� �� �ִ� �ִ� �޸�

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			if (j - cost[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + bite[i]);

			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	for (int i = 0; i <= sum; i++)
	{
		if (dp[N][i] >= M)
		{
			cout << i << '\n';
			break;
		}
	}

	return 0;
}