#include <iostream>
using namespace std;

int N;
long long city[100000];
long long dis[100000];
long long current_oil;
long long result = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N - 1; i++)
		cin >> dis[i];
	for (int i = 0; i < N; i++)
		cin >> city[i];
	current_oil = city[0];
	for (int i = 0; i < N - 1; i++)
	{
		if (current_oil < city[i])
		{
			result += current_oil * dis[i];
		}
		else
		{
			current_oil = city[i];
			result += current_oil * dis[i];
		}
	}

	cout << result;

	return 0;
}