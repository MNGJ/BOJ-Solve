#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, a, b, node_a, node_b, cnt= 1;
vector<pair<int, int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
		cout << v[i].first << " " << v[i].second << '\n';

	node_a = v[0].first;
	node_b = v[0].second;

	for (int i = 0; i < N; i++)
	{
		if (node_b <= v[i].first)
		{
			cnt++;
			node_b = v[i].second;
		}
	}

	cout << cnt;

	return 0;
}