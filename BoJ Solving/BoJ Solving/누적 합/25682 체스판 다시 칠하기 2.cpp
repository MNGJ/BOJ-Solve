#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
int B[2001][2001];
int W[2001][2001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			char c;
			cin >> c;
			B[i][j] = B[i][j - 1] + B[i - 1][j] - B[i - 1][j - 1];
			W[i][j] = W[i][j - 1] + W[i - 1][j] - W[i - 1][j - 1];
			if ((i + j) % 2 == 0) {
				if (c == 'W') B[i][j]++;
				else W[i][j]++;
			}
			else {
				if (c == 'B') B[i][j]++;
				else W[i][j]++;
			}
		}
	}

	int cnt = K * K;
	for (int i = K; i <= N; i++)
	{
		for (int j = K; j <= M; j++)
		{
			int tmpW = W[i][j] - W[i - K][j] - W[i][j - K] + W[i - K][j - K];
			int tmpB = B[i][j] - B[i - K][j] - B[i][j - K] + B[i - K][j - K];
			cnt = min(cnt, min(tmpW, tmpB));
		}
	}

	cout << cnt;

	return 0;
}