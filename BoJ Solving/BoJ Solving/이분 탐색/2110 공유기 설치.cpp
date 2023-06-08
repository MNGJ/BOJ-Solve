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

	s = 1; // 최소 거리
	e = arr[N - 1] - arr[0]; // 최대 거리
	
	while (s <= e)
	{
		mid = (s + e) / 2;
		router = 1; // 공유기 설치 갯수. 1인 이유는 첫번째 위치는 무조건 넣으므로
		spot = arr[0]; // 첫번째 위치를 스팟으로 시작
		for (int i = 1; i < N; i++)
		{
			if (arr[i] - spot >= mid)
			{
				router++; // mid만큼 인접거리가 늘어나면 공유기 설치
				spot = arr[i]; // 인접거리 갱신을 위해
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