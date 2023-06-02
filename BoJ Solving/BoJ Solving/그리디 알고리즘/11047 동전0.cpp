#include <iostream>
using namespace std;

int N, K, result = 0;
int cnt[10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> cnt[i];

	for (int i = N - 1; i >= 0; i--)
	{
		if (K / cnt[i] >= 1)
		{
			result += K / cnt[i];
			K = K % cnt[i];
		}
	}

	cout << result;

	return 0;
}