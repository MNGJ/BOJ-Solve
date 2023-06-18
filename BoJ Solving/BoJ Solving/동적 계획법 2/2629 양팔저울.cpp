#include <iostream>
using namespace std;

int chu, ball, temp;
int chus[31];
bool dp[31][15001];

void solve(int i, int b_w)
{
	if (i > chu || dp[i][b_w]) return;
	dp[i][b_w] = true;
	solve(i + 1, b_w + chus[i]);
	solve(i + 1, abs(b_w - chus[i]));
	solve(i + 1, b_w);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> chu;
	for (int i = 0; i < chu; i++)
	{
		cin >> chus[i];
	}
	solve(0, 0);

	cin >> ball;

	for (int i = 0; i < ball; i++)
	{
		cin >> temp;
		if (temp > 15000) cout << "N ";
		else if (dp[chu][temp]) cout << "Y ";
		else cout << "N ";
	}

	return 0;
}