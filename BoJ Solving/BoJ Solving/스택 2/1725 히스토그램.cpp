#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int N, ans;
int height[100002];
stack<int> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> height[i];
	}

	s.push(0);
	for (int i = 1; i <= N + 1; i++)
	{
		while (!s.empty() && height[s.top()] > height[i])
		{
			int check = s.top();
			s.pop();
			ans = max(ans, height[check] * (i - s.top() - 1));
		}
		s.push(i);
	}
	cout << ans;

	return 0;
}