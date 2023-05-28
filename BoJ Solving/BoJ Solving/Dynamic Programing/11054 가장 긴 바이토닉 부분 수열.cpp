#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, answer = 0;
int DP[2][1001];
int arr[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	fill(DP[0], DP[0] + 1001, 1); // �ּ��� �ڱ��ڽ��� ������ 1�� ���̸� �����Ƿ�
	fill(DP[1], DP[1] + 1001, 1);

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++) // �����ϴ� ���� �� ����
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				DP[0][i] = max(DP[0][i], DP[0][j] + 1);
			}
		}
	}

	for (int i = N; i >= 1; i--) // ���������� �����ϴ� ���� �� ����
	{
		for (int j = N; j > i; j--)
		{
			if (arr[i] > arr[j])
			{
				DP[1][i] = max(DP[1][i], DP[1][j] + 1);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (answer < DP[0][i] + DP[1][i])
			answer = DP[0][i] + DP[1][i];
	}

	cout << answer - 1; // ������, ������ �� ���� �� ������ ���� �ߺ��ǹǷ� -1 ���ش�.

	return 0;
}