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

	fill(DP, DP + 101, 1); // ���� �� �����ϴ� �κ� �������� �ּ� 1�̻��� �����Ƿ� 1�� �ʱ�ȭ

	for (int i = 1; i <= N; i++)
	{
		cin >> A >> B;
		v.push_back({ A, B });
	}

	sort(v.begin(), v.end()); // A�� �������� ����

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (v[i].second > v[j].second) // B���� ���� �� �����ϴ� �κ� ������ ����
				DP[i] = max(DP[i], DP[j] + 1);
		}
		answer = max(answer, DP[i]);
	}

	cout << N - answer; // �������� �� ���� - B���� ���� �� �����ϴ� �κ� ���� = ���־� �ϴ� �������� �ּ� ����

	return 0;
}