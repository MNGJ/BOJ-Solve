#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		if (temp > 0)
			pq.push(temp);
		else
		{
			if (pq.empty())
			{
				cout << '0' << '\n';
				continue;
			}
			cout << pq.top() << '\n';
			pq.pop();
		}
	}

	return 0;
}