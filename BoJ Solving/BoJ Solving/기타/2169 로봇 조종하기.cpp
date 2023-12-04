#include <iostream>
#include <math.h>
using namespace std;

#define MAX 1001

int N, M;
int MAP[MAX][MAX];
int DP[MAX][MAX];
int Temp[MAX][MAX][2]; // [][][0] 은 왼쪽에서 오른쪽으로 갈 때 [][][1] 은 오른쪽에서 왼쪽으로 갈 때

void Input()
{
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			cin >> MAP[i][j];
		}
}

void Solve()
{
	DP[1][1] = MAP[1][1];
	for (int i = 2; i <= M; i++) DP[1][i] = DP[1][i - 1] + MAP[1][i]; // 첫째 줄은 최적값이 왼쪽에서 오른쪽밖에 없으므로

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= M; j++) // 우선 위에서 아래로 내려오는 경우를 우선적으로 갱신
		{
			Temp[i][j][0] = DP[i - 1][j] + MAP[i][j];
			Temp[i][j][1] = DP[i - 1][j] + MAP[i][j];
		}

		for (int j = 2; j <= M; j++) // 왼쪽에서 오른쪽으로 가는 경우. j=1일땐 왼쪽끝이므로 제외
			Temp[i][j][0] = max(Temp[i][j][0], Temp[i][j-1][0] + MAP[i][j]);
		
		for (int j = M - 1; j >= 1; j--) // 오른쪽에서 왼쪽으로 가는 경우. j = M일땐 오른쪽끝이므로 제외
			Temp[i][j][1] = max(Temp[i][j][1], Temp[i][j + 1][1] + MAP[i][j]);

		for (int j = 1; j <= M; j++) DP[i][j] = max(Temp[i][j][0], Temp[i][j][1]);
	}
	cout << DP[N][M];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();

	return 0;
}