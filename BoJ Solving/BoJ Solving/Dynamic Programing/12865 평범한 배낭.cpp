#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int DP[101][100001];
int W[1001];// ����
int V[1001];// ��ġ

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> W[i] >> V[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j >= W[i])// j�� ���� ������ �ϴ� ������ ���Ժ��� ���ٸ�
			{
				DP[i][j] = max(DP[i-1][j - W[i]] + V[i], DP[i - 1][j]); // �Ѵܰ� ������ �ϴ� ������ �̹� �ڽ��� ��ٴ� �����̹Ƿ� �ڽ��� ������ �� �ܰ踦 �����Ѵ�.
			}
			else
			{
				DP[i][j] = DP[i - 1][j]; // j�� ���� ������ ���Ժ��� ������ �� �ܰ��� ���� j�� ����
			}
		}
	}

	cout << DP[N][K];

	return 0;
}