#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];
int DP[10001];
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	DP[0] = 0;
	DP[1] = arr[1];
	DP[2] = arr[1] + arr[2];

	// 3���� ����� �� �� ���� ū ���� �ִ�. ������ ���� i��� ��
	// 1. i-3 ������ �ִ� + i-1��° �� + i��° ��
	// 2. i-2 ������ �ִ� + i��° ��
	// 3. i-1 ������ �ִ�. i��°���� ������ ����
	for (int i = 3; i <= N; i++) 
	{
		DP[i] = max(DP[i - 3] + arr[i - 1] + arr[i], max(DP[i - 2] + arr[i], DP[i - 1]));
	}

	cout << DP[N];

	return 0;
}