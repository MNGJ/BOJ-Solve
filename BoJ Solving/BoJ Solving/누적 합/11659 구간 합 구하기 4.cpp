#include <iostream>
#include <vector>
using namespace std;

int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	vector<long> dp(N + 1);
	dp[0] = 0;

	for (int i = 1; i <= N; i++)
	{
		long num;
		cin >> num;
		dp[i] = dp[i - 1] + num;
	}

	for (int i = 0; i < M; i++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		cout << dp[temp2] - dp[temp1 - 1] << '\n';
	}

	return 0;
}