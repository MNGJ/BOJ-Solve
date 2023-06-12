#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>,greater<int>> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int temp;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		if (temp == 0)
		{
			if (q.empty())
			{
				cout << 0 << '\n';
				continue;
			}
			cout << q.top() << '\n';
			q.pop();
		}
		else
			q.push(temp);
	}


	return 0;
}