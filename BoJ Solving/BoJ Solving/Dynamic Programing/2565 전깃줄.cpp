#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, A, B, answer;
vector<pair<int, int>> v;
int DP[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	v.push_back({ 0, 0 });

	fill(DP, DP + 101, 1); // 가장 긴 증가하는 부분 수열에서 최소 1이상은 나오므로 1로 초기화

	for (int i = 1; i <= N; i++)
	{
		cin >> A >> B;
		v.push_back({ A, B });
	}

	sort(v.begin(), v.end()); // A를 기준으로 정렬

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (v[i].second > v[j].second) // B에서 가장 긴 증가하는 부분 수열을 구함
				DP[i] = max(DP[i], DP[j] + 1);
		}
		answer = max(answer, DP[i]);
	}

	cout << N - answer; // 전깃줄의 총 갯수 - B에서 가장 긴 증가하는 부분 수열 = 없애야 하는 전깃줄의 최소 개수

	return 0;
}