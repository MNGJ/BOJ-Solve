#include <iostream>
#include <string>
using namespace std;

int N;
char arr[64][64]; // 입력값이 띄어쓰기 구분이 안돼있으므로 char로 선언
string ans = "";

void quad_tree(int x, int y, int size)
{
	char check = arr[x][y]; // 가장 왼쪽 위를 기준으로 비교
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
				quad_tree(x, y, size / 2); // 1/4 분면
				quad_tree(x, y + size/2, size / 2); // 2/4 분면
				quad_tree(x + size/2 , y, size / 2); // 3/4 분면
				quad_tree(x + size/2, y + size/2, size / 2); // 4/4 분면
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