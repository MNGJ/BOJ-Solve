#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, tmp, s, e, mid;
vector<int> arr, res;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	arr.resize(N + 1);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int cnt = 1;
	res.push_back(arr[0]);
	for (int i = 1; i < N; i++)
	{
		if (res.back() < arr[i])
		{
			res.push_back(arr[i]);
			cnt++;
		}
		else
		{
			int idx = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
			res[idx] = arr[i];
		}
	}

	cout << cnt;

	return 0;
}