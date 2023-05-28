#include <iostream>
using namespace std;

int n;
int arr[11];
int cal[4];
int min_ = 1000000000;
int max_ = -1000000000;

void calculator(int result, int depth)
{
	if (n == depth)
	{
		if (result > max_)
			max_ = result;
		if (result < min_)
			min_ = result;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (cal[i] > 0)
		{
			cal[i]--;
			if (i == 0)
				calculator(result + arr[depth], depth + 1);
			else if (i == 1)
				calculator(result - arr[depth], depth + 1);
			else if (i == 2)
				calculator(result * arr[depth], depth + 1);
			else
				calculator(result / arr[depth], depth + 1);
			cal[i]++;
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < 4; i++)
		cin >> cal[i];

	calculator(arr[0], 1);

	cout << max_ << '\n' << min_;

	return 0;
}