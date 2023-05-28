#include <iostream>
#include <vector>
using namespace std;

int board[9][9];
vector<pair<int, int>> points; // ����ִ� ���� ��ǥ �迭
int cnt = 0; // ����ִ� ���� ����
bool found = false; // ���� ���尡 �ϼ��Ǹ� true ��ȯ

bool check(pair<int, int> p)
{
	int square_x = p.first / 3;
	int square_y = p.second / 3;
	for (int i = 0; i < 9; i++)
	{
		if (board[i][p.second] == board[p.first][p.second] && i != p.first) // ���� �� �˻�
		{
			return false;
		}
		if (board[p.first][i] == board[p.first][p.second] && i != p.second) // ���� �� �˻�
		{
			return false;
		}
	}
	for(int i = 3*square_x; i < 3*square_x + 3; i++) // 3x3 ���� �˻�
		for (int j = 3 * square_y; j < 3 * square_y + 3; j++)
		{
			if (board[i][j] == board[p.first][p.second])
			{
				if (i != p.first && j != p.second)
					return false;
			}
		}
	return true;
}

void sukudo(int depth)
{
	if (depth == cnt) // ���� ���带 ��� ã���� ��� ���
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		found = true; // �ظ� �� ã�����Ƿ� found true�� ��ȯ
		return;
	}
	for (int i = 1; i <= 9; i++) // 1���� 9���� �� �־�鼭 üũ
	{
		board[points[depth].first][points[depth].second] = i;
		if (check(points[depth])) // ����� ��ȿ�ϴٸ� ���� ��ĭ ä�췯 ��
			sukudo(depth + 1);
		if (found) // ������ �ϼ��Ǿ��� ��� ���̻� �ظ� ã�� �ʿ䰡 �����Ƿ� �Լ� ����
			return;
	}
	board[points[depth].first][points[depth].second] = 0; // �ظ� ��ã���� ��� �� ����
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 0)
			{
				points.push_back({ i, j });
				cnt++;
			}
		}

	sukudo(0);

	return 0;
}