#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int DP[101][100001];
int W[1001];// 무게
int V[1001];// 가치

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
			if (j >= W[i])// j가 현재 보려고 하는 물건의 무게보다 높다면
			{
				DP[i][j] = max(DP[i-1][j - W[i]] + V[i], DP[i - 1][j]); // 한단계 전에서 하는 이유는 이미 자신을 썼다는 가정이므로 자신을 배제한 전 단계를 봐야한다.
			}
			else
			{
				DP[i][j] = DP[i - 1][j]; // j가 현재 물건의 무게보다 낮으면 전 단계의 동일 j와 같음
			}
		}
	}

	cout << DP[N][K];

	return 0;
}