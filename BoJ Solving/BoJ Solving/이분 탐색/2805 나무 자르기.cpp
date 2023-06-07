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
		int mid = (s + e) / 2; // �߰��� -> �̺� Ž���� ����
		sum_tree = 0;
		for (int i = 0; i < N; i++)
		{
			if (trees[i] <= mid)
				continue;
			sum_tree += trees[i] - mid; // mid���̸� �������� �߶��� �� �߸� �������� �� ������ ��
		}
		if (sum_tree >= M) // �߸� ������ ���� �������� �ϴ� �������̺��� ũ�ų� ���ٸ�
		{
			s = mid + 1; // mid���� ������ �߸� ������ ���� ���߱� ����
			ans = mid; // �������� �׻� M��ŭ Ȥ�� �׺��� �� �������� �� ���̹Ƿ� ���� mid�� ����
		}
		else if(sum_tree < M) // �߸� ������ ���� �������� �ϴ� �������̺��� �۴ٸ�
		{
			e = mid - 1; // mid ���� ���缭 �߸� ������ ���� ���̱� ����
		}
	}

	cout << ans;

	return 0;
}