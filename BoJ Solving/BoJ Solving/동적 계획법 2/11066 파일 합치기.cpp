#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000

int test_case, K;
int sum[501], chapter[501], DP[501][501]; // DP[x][y] : x~y번째 파일들을 합치는데 필요한 최소비용
// sum[x] : 1~x번째 파일까지의 크기 합

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

		for (int i = 1; i <= K; i++) // i는 구해야 하는 범위의 크기. 예를들면 i = 1이면 1~2번째 파일, 2~3번째 파일 등
		{
			for (int j = 1; j <= K - i; j++) // j는 합치는 범위의 시작 부분
			{
				DP[j][i + j] = INF;
				for (int k = j; k < i + j; k++)// k는 구해야 하는 범위를 두 부분으로 나누는 기준
				{
					DP[j][i + j] = min(DP[j][i + j], DP[j][k] + DP[k + 1][i + j] + sum[i + j] - sum[j - 1]);
				}
			}
		}
		cout << DP[1][K] << '\n';

	}

	return 0;
}