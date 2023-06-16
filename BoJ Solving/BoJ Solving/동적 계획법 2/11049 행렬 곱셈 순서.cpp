#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000

int N, r, c;
int sum[501], matrix[501][2], dp[501][501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> r >> c;
		matrix[i][0] = r;
		matrix[i][1] = c;
	}

	for (int i = 1; i < N; i++) // i�� ���� ������ ũ��. i�� 2��� dp[1][3], dp[2][4], dp[3][5]... dp[x][x+2] ��
	{
		for (int j = 1; i + j <= N; j++) // j�� ���� ������ ��������. dp[2][3], dp[2][6], dp[2][11]�� ��� ���������� 2
		{
			dp[j][i + j] = INF;
			for (int k = j; j <= i + j; j++) // k�� ���� ������ �� �κ����� ���� �� ������
			{
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i + j][1]);
																			// matrix[j][0] : ���� ���� �κ��� ����� ��(N ����)
																							// matrix[k][1] : ������ �ѷ� ������ ������ ����� ��(M ����)
																											// matrix[i+j][1] : ���� ������ �κ��� ����� �� (K  ����)
			}
		}
	}

	cout << dp[1][N];

	return 0;
}