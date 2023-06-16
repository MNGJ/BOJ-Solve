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

	for (int i = 1; i < N; i++) // i는 구간 범위의 크기. i가 2라면 dp[1][3], dp[2][4], dp[3][5]... dp[x][x+2] 등
	{
		for (int j = 1; i + j <= N; j++) // j는 구간 범위의 시작지점. dp[2][3], dp[2][6], dp[2][11]등 모두 시작지점은 2
		{
			dp[j][i + j] = INF;
			for (int k = j; j <= i + j; j++) // k는 구간 범위를 두 부분으로 나눌 때 기준점
			{
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i + j][1]);
																			// matrix[j][0] : 구간 시작 부분의 행렬의 행(N 역할)
																							// matrix[k][1] : 구간을 둘로 나누는 기준점 행렬의 열(M 역할)
																											// matrix[i+j][1] : 구간 마지막 부분의 행렬의 열 (K  역할)
			}
		}
	}

	cout << dp[1][N];

	return 0;
}