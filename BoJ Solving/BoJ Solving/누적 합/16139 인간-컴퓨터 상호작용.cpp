#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string S;
int q, l, r;
char alpha;
int arr[26][200001]; // ���ĺ� ���� x ���ڿ� �ִ� ����(��� ���� ���ĺ��� ��� ����)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> S;

	for(int i = 0; i < 26; i++)
		for (int j = 1; j <= S.length(); j++)
		{
			arr[i][j] = arr[i][j - 1];
			if (S[j - 1] - 97 == i) // ���ڿ��� ���� - 97(�ƽ�Ű�ڵ�)�� i�� ���ٸ�
			{
				arr[i][j]++;
			}
		}

	cin >> q;

	while (q--)
	{
		cin >> alpha >> l >> r;

		cout << arr[alpha - 97][r + 1] - arr[alpha - 97][l] << '\n'; // arr[][0]=0�̹Ƿ� r+1 ���� l����
	}


	return 0;
}