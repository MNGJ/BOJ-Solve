#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000

int test_case, K;
int sum[501], chapter[501], DP[501][501]; // DP[x][y] : x~y��° ���ϵ��� ��ġ�µ� �ʿ��� �ּҺ��
// sum[x] : 1~x��° ���ϱ����� ũ�� ��

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> test_case;

	while (test_case--)
	{
		cin >> K;
		for (int i = 1; i <= K; i++)
		{
			cin >> chapter[i];
			sum[i] = sum[i - 1] + chapter[i];
		}

		for (int i = 1; i <= K; i++) // i�� ���ؾ� �ϴ� ������ ũ��. ������� i = 1�̸� 1~2��° ����, 2~3��° ���� ��
		{
			for (int j = 1; j <= K - i; j++) // j�� ��ġ�� ������ ���� �κ�
			{
				DP[j][i + j] = INF;
				for (int k = j; k < i + j; k++)// k�� ���ؾ� �ϴ� ������ �� �κ����� ������ ����
				{
					DP[j][i + j] = min(DP[j][i + j], DP[j][k] + DP[k + 1][i + j] + sum[i + j] - sum[j - 1]);
				}
			}
		}
		cout << DP[1][K] << '\n';

	}

	return 0;
}