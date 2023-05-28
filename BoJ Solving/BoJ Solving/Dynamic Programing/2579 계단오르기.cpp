#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[301]; // 계단을 나타내는 배열
int dp[301]; // 해당 계단까지의 Max값을 나타내는 배열

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1] = arr[1]; // 첫번째 계단 까지의 max 값은 첫번째 계단
	dp[2] = arr[1] + arr[2]; // 두번째 게단 까지의 max 값은 첫번째 계단 + 두번째 계단
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]); // 세번째 계단 까지의 max 값은 첫번째 계단 + 세번째 계단 혹은 두번째 계단 + 세번째 계단

	for (int i = 4; i <= n; i++)
	{
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}

	cout << dp[n];

	return 0;
}