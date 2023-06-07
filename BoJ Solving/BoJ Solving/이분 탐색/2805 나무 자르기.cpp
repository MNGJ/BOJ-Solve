#include <iostream>
#include <algorithm>
using namespace std;

int N, M, s, e, ans;
long long sum_tree = 0;
int trees[1000000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> trees[i];
	}

	s = 1;
	e = *max_element(trees, trees + N);

	while (s <= e)
	{
		int mid = (s + e) / 2; // 중간값 -> 이분 탐색을 위해
		sum_tree = 0;
		for (int i = 0; i < N; i++)
		{
			if (trees[i] <= mid)
				continue;
			sum_tree += trees[i] - mid; // mid높이를 기준으로 잘랐을 때 잘린 나무들의 총 길이의 합
		}
		if (sum_tree >= M) // 잘린 나무의 합이 가져가려 하는 나무길이보다 크거나 같다면
		{
			s = mid + 1; // mid값을 높여서 잘린 나무의 합을 낮추기 위해
			ans = mid; // 마지막은 항상 M만큼 혹은 그보다 더 가져가야 할 것이므로 답을 mid로 갱신
		}
		else if(sum_tree < M) // 잘린 나무의 합이 가져가려 하는 나무길이보다 작다면
		{
			e = mid - 1; // mid 값을 낮춰서 잘린 나무의 합을 높이기 위해
		}
	}

	cout << ans;

	return 0;
}