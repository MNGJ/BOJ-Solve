#include <iostream>
#include <math.h>
using namespace std;

#define MAX 1001

int N, M;
int MAP[MAX][MAX];
int DP[MAX][MAX];
int Temp[MAX][MAX][2]; // [][][0] �� ���ʿ��� ���������� �� �� [][][1] �� �����ʿ��� �������� �� ��

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
	for (int i = 2; i <= M; i++) DP[1][i] = DP[1][i - 1] + MAP[1][i]; // ù° ���� �������� ���ʿ��� �����ʹۿ� �����Ƿ�

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= M; j++) // �켱 ������ �Ʒ��� �������� ��츦 �켱������ ����
		{
			Temp[i][j][0] = DP[i - 1][j] + MAP[i][j];
			Temp[i][j][1] = DP[i - 1][j] + MAP[i][j];
		}

		for (int j = 2; j <= M; j++) // ���ʿ��� ���������� ���� ���. j=1�϶� ���ʳ��̹Ƿ� ����
			Temp[i][j][0] = max(Temp[i][j][0], Temp[i][j-1][0] + MAP[i][j]);
		
		for (int j = M - 1; j >= 1; j--) // �����ʿ��� �������� ���� ���. j = M�϶� �����ʳ��̹Ƿ� ����
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