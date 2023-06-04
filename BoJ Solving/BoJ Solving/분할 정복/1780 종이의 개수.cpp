#include <iostream>
using namespace std;

int N; // NÀº 3^k ²Ã
int arr[2187][2187];
int a= 0, b= 0, c= 0;

void solve(int x, int y, int size)
{
	int check = arr[x][y];
	for(int i = x; i < x+size; i++)
		for (int j = y; j < y + size; j++)
		{
			if (check == -1 && arr[i][j] != -1)
				check = 2;
			else if (check == 0 && arr[i][j] != 0)
				check = 2;
			else if (check == 1 && arr[i][j] != 1)
				check = 2;
			if (check == 2)
			{
				solve(x, y, size / 3);
				solve(x + size/3, y, size / 3);
				solve(x + size*2/3, y, size / 3);
				solve(x, y + size/3, size / 3);
				solve(x, y + size*2/3, size / 3);
				solve(x + size/3, y + size/3, size / 3);
				solve(x + size/3, y + size*2/3, size / 3);
				solve(x + size*2/3, y + size/3, size / 3);
				solve(x + size*2/3, y + size*2/3, size / 3);
				return;
			}
		}
	if (check == -1)
		a++;
	else if (check == 0)
		b++;
	else if (check == 1)
		c++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}

	solve(0, 0, N);

	cout << a << '\n' << b << '\n' << c;

	return 0;
}