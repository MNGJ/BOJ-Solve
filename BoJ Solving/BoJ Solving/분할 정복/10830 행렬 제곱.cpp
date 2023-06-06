#include <iostream>
using namespace std;

long long N, B, mod = 1000;
long long A[5][5];
long long tmp[5][5];
long long ans[5][5];

// ��� ����
void Matrix_multi(long long x[5][5], long long y[5][5])
{
	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			tmp[i][j] = 0; // ��� �ʱ�ȭ
			for (int k = 0; k < N; k++)
				tmp[i][j] += x[i][k] * y[k][j];

			tmp[i][j] %= mod;
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			x[i][j] = tmp[i][j];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> A[i][j];
		ans[i][i] = 1; // ������� ������ķ� �ʱ�ȭ
	}

	while (B > 0) // 5 -> 2 -> 1
	{
		if (B % 2 == 1) // ans : a -> a*a^4
			Matrix_multi(ans, A); // ���� ��Ŀ� A��� ���ϱ�
		Matrix_multi(A, A); // a : a^2 -> a^4
		B /= 2;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << ans[i][j] << " ";
		cout << '\n';
	}

	return 0;
}