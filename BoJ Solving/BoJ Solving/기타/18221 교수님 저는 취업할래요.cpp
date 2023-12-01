#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int N;
int ans = 0;
int A1, B1, A2, B2, temp = 0;
int RC[1001][1001];

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			RC[i][j] = temp;
			if (temp == 2)
			{
				A1 = i;
				A2 = j;
			}
			else if (temp == 5)
			{
				B1 = i;
				B2 = j;
			}
		}
	}

	if (sqrt(pow(A1 - B1, 2) + pow(A2 - B2, 2)) < 5.0)
	{
		cout << 0;
			return 0;
	}


	for(int i = min(A1, B1); i <= max(A1, B1); i++)
		for (int j = min(A2, B2); j <= max(A2, B2); j++)
		{
			if (RC[i][j] == 1)
			{
				ans++;
			}
		}

	if (ans >= 3)
		cout << 1;
	else
		cout << 0;

	return 0;
}