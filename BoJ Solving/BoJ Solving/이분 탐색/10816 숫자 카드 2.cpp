#include <iostream>
#include <map>
using namespace std;

map<int, int> m;
int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		m[tmp]++;
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> tmp;
		cout << m[tmp] << " ";
	}

	return 0;
}