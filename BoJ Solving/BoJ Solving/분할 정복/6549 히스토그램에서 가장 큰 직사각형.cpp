#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define INF 2000000000 // 20��
long long n;
long long seg[1000001];
long long x, ans;
long long h[100001];

int init(int node, int s, int e)
{
	if (s == e) return seg[node] = s; // start �� end �� ��ġ�� ��ġ�ϸ� �ε��� s ���� �־��ش�.
	int mid = (s + e) / 2;
	int left_index = init(2 * node, s, mid);
	int right_index = init(2 * node + 1, mid + 1, e);

	return seg[node] =
		h[left_index] < h[right_index] ? left_index : right_index;
}

int query(int node, int s, int e, int l, int r)
{
	if (e < l || r < s) return INF; // ã�ƾ��ϴ� ������ ��屸���� ��ġ�� ���� ��
	if (l <= s && e <= r) return seg[node]; // ã�ƾ��ϴ� �������� ��屸���� ���Ե� ��
	int mid = (s + e) / 2;
	int left_index = query(2 * node, s, mid, l, r);
	int right_index = query(2 * node + 1, mid + 1, e, l, r);

	// ã�ƾ��ϴ� ������ ��屸���� ���Եǰų�, �κ������� ��ġ�� ���
	if (left_index == INF) return right_index; // ��������
	else if (right_index == INF) return left_index; // ��������
	else return h[left_index] < h[right_index] ? left_index : right_index;
}


void solve(long long left, long long right)
{
	if (left > right) return;

	// �������� �ּҰ��� �ش� �ε��� ã��
	long long index = query(1, 0, n - 1, left, right); // ���� ���� �ּҰ� ã��

	ans = max(ans, h[index] * (right - left + 1));

	solve(left, index - 1);
	solve(index + 1, right);

}

int main()
{
	while (1)
	{
		ans = 0;
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++)
		{
			cin >> h[i];
		}
		init(1, 0, n - 1); // ���׸�Ʈ Ʈ�� �����
		solve(0, n - 1);

		cout << ans << endl;
	}

}
