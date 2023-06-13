#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct cmp 
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
			return a > b;
		return abs(a) > abs(b);
	}
};

int N;
priority_queue<int, vector<int>, cmp> pq;

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
			if (pq.empty())
			{
				cout << 0 << '\n';
				continue;
			}
			cout << pq.top() << '\n';
			pq.pop();
		}
		else
		{
			pq.push(temp);
		}
	}

	return 0;
}