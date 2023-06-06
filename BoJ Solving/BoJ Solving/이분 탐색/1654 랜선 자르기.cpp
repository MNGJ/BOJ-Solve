#include <iostream>
#include <algorithm>
using namespace std;

long long K, N, max_cm, sum, ans = 0;
int arr[10000];

void solve(long long s, long long e)
{
	while (s <= e)
	{
		long long mid = (s + e) / 2;
		long long cnt = 0;
		for (int i = 0; i < K; i++)
			cnt += arr[i] / mid;

		if (cnt >= N)
		{
			s = mid + 1;
			if (mid > ans)
				ans = mid;
		}
		else
		{
			e = mid - 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K >> N;
	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	max_cm = sum / N;

	solve(1, max_cm);

	cout << ans;

	return 0;
}