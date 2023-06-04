#include <iostream>
using namespace std;

int N;
int arr[128][128];
int white = 0, blue = 0;


void divide_color(int x, int y, int size)
{
	int check = arr[x][y];
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (check == 0 && arr[i][j] == 1)
				check = 2;
			else if (check == 1 && arr[i][j] == 0)
				check = 2;
			if (check == 2)
			{
				divide_color(x, y, size / 2);
				divide_color(x, y + size/2, size / 2);
				divide_color(x + size/2, y, size / 2);
				divide_color(x + size/2, y+ size/2, size / 2);
				return;
			}
		}
	}
	if (check == 0)
		white++;
	else
		blue++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	divide_color(0,0, N);
	cout << white << '\n';
	cout << blue << '\n';

	return 0;
}