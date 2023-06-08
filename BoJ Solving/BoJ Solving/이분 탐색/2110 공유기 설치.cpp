#include <iostream>
#include <algorithm>
using namespace std;

int N, C, s, e, mid, spot, router, ans = 0;
int arr[200000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> C;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	s = 1; // �ּ� �Ÿ�
	e = arr[N - 1] - arr[0]; // �ִ� �Ÿ�
	
	while (s <= e)
	{
		mid = (s + e) / 2;
		router = 1; // ������ ��ġ ����. 1�� ������ ù��° ��ġ�� ������ �����Ƿ�
		spot = arr[0]; // ù��° ��ġ�� �������� ����
		for (int i = 1; i < N; i++)
		{
			if (arr[i] - spot >= mid)
			{
				router++; // mid��ŭ �����Ÿ��� �þ�� ������ ��ġ
				spot = arr[i]; // �����Ÿ� ������ ����
			}
		}
		if (router >= C)
		{
			ans = max(ans, mid);
			s = mid + 1;
		}
		else
		{
			e = mid - 1;
		}
	}

	cout << ans;

	return 0;
}