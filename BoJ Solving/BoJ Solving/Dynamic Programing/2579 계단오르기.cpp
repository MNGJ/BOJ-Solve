#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[301]; // ����� ��Ÿ���� �迭
int dp[301]; // �ش� ��ܱ����� Max���� ��Ÿ���� �迭

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1] = arr[1]; // ù��° ��� ������ max ���� ù��° ���
	dp[2] = arr[1] + arr[2]; // �ι�° �Դ� ������ max ���� ù��° ��� + �ι�° ���
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]); // ����° ��� ������ max ���� ù��° ��� + ����° ��� Ȥ�� �ι�° ��� + ����° ���

	for (int i = 4; i <= n; i++)
	{
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}

	cout << dp[n];

	return 0;
}