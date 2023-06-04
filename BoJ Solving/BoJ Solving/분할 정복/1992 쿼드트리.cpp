#include <iostream>
#include <string>
using namespace std;

int N;
char arr[64][64]; // �Է°��� ���� ������ �ȵ������Ƿ� char�� ����
string ans = "";

void quad_tree(int x, int y, int size)
{
	char check = arr[x][y]; // ���� ���� ���� �������� ��
	for(int i = x; i < x + size; i++)
		for (int j = y; j < y + size; j++)
		{
			if (check == '0' && arr[i][j] == '1') 
				check = '2';
			if (check == '1' && arr[i][j] == '0')
				check = '2';

			if (check == '2')
			{
				ans += "(";
				quad_tree(x, y, size / 2); // 1/4 �и�
				quad_tree(x, y + size/2, size / 2); // 2/4 �и�
				quad_tree(x + size/2 , y, size / 2); // 3/4 �и�
				quad_tree(x + size/2, y + size/2, size / 2); // 4/4 �и�
				ans += ")";
				return;
			}
		}
	if (check == '0')
		ans += "0";
	else
		ans += "1";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	quad_tree(0, 0, N);

	cout << ans;

	return 0;
}