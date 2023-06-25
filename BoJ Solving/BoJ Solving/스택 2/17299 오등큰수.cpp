#include <iostream>
#include <stack>
using namespace std;

int F[1000001];
int N;
int A[1000001];
int NGF[1000001];
stack<int> st;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		F[A[i]]++;
	}

	for (int i = N - 1; i >= 0; i--)
	{
		int number = A[i];
		int height = F[number];
		while (!st.empty())
		{
			int topNum = A[st.top()];
			int topHeight = F[topNum];
			if (height >= topHeight) st.pop();
			else break;
		}
		NGF[i] = -1;
		if (!st.empty()) NGF[i] = A[st.top()];
		st.push(i);
	}

	for (int i = 0; i < N; i++)
		cout << NGF[i] << " ";

	return 0;
}