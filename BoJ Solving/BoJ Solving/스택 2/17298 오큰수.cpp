#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int N;
stack<int> stk;
int NGE[1000001];
int seq[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> seq[i];
	}
	for (int i = N - 1; i >= 0; i--)
	{
		while (!stk.empty() && stk.top() <= seq[i])
			stk.pop();

		if (stk.empty()) NGE[i] = -1;
		else NGE[i] = stk.top();

		stk.push(seq[i]);
	}

	for (int i = 0; i < N; i++)
		cout << NGE[i] << " ";

	return 0;
}