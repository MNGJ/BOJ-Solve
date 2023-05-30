#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, temp, dp_max = -10000001;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	vector<int> dp(N + 1);
	dp[0] = 0;

	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		dp[i] = dp[i - 1] + temp;
		if (i >= K)
		{
			dp_max = max(dp_max, dp[i] - dp[i - K]);
		}
	}

	cout << dp_max;

	return 0;
}