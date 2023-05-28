#include <iostream>
#include <algorithm>
using namespace std;

int n, maxnum;
int dp[500][500] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> dp[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0) // ���� ���̵忡 ���� ���
				dp[i][j] = dp[i - 1][0] + dp[i][j];
			else if (i == j) // ������ ���̵忡 ���� ���
				dp[i][j] = dp[i - 1]dp[j - 1] + dp[i][j];
			else // �߰��� ���� ��� �� �밢���� ū ��
				dp[i][j] = max(dp[i - 1][j - 1] + dp[i][j], dp[i - 1][j] + dp[i][j]);

			maxnum = max(maxnum, dp[i][j]);
		}
	}

	cout << maxnum;

	return 0;
}