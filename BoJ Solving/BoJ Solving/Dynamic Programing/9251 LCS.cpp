#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string A, B;
int DP[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B;

	for (int i = 0; i < A.length(); i++)
	{
		for (int j = 0; j < B.length(); j++)
		{
			if (A[i] == B[j]) // ���ڰ� ���ٸ�
			{
				DP[i + 1][j + 1] = DP[i][j] + 1; // ������ �밢�� �� + 1
			}
			else
			{
				DP[i + 1][j + 1] = max(DP[i][j + 1], DP[i + 1][j]); // ���� Ȥ�� �� ���� ū ��
			}
		}
	}

	cout << DP[A.length()][B.length()];

	return 0;
}