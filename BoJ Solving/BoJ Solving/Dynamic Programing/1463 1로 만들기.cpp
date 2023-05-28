#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, temp;
vector<int> DP = { 0, 0, 1, 1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 4; i <= N; i++)
	{
		if (i % 2 == 0 && i % 3 == 0) // 2와 3으로 나누어질 경우
		{
			temp = min(DP[i / 3], min(DP[i / 2], DP[i - 1])) + 1;
		}
		else if (i % 2 == 0 && i % 3 != 0) // 2로만 나누어질 경우
		{
			temp = min(DP[i / 2], DP[i - 1]) + 1;
		}
		else if (i % 2 != 0 && i % 3 == 0) // 3로만 나누어질 경우
		{
			temp = min(DP[i / 3], DP[i - 1]) + 1;
		}
		else
			temp = DP[i - 1] + 1;
		DP.push_back(temp);
	}

	cout << DP[N];

	return 0;
}