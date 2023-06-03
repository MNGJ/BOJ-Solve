#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, result;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int temp = v[0];
	result = v[0];
	for (int i = 1; i < N; i++)
	{
		temp += v[i];
		result += temp;
	}
	cout << result;

	return 0;
}