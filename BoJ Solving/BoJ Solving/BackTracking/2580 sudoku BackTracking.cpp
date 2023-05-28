#include <iostream>
#include <vector>
using namespace std;

int board[9][9];
vector<pair<int, int>> points; // 비어있는 지점 좌표 배열
int cnt = 0; // 비어있는 지점 개수
bool found = false; // 스쿠도 보드가 완성되면 true 변환

bool check(pair<int, int> p)
{
	int square_x = p.first / 3;
	int square_y = p.second / 3;
	for (int i = 0; i < 9; i++)
	{
		if (board[i][p.second] == board[p.first][p.second] && i != p.first) // 같은 열 검사
		{
			return false;
		}
		if (board[p.first][i] == board[p.first][p.second] && i != p.second) // 같은 행 검사
		{
			return false;
		}
	}
	for(int i = 3*square_x; i < 3*square_x + 3; i++) // 3x3 구역 검사
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
	if (depth == cnt) // 스쿠도 보드를 모두 찾으면 결과 출력
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		found = true; // 해를 다 찾았으므로 found true로 변환
		return;
	}
	for (int i = 1; i <= 9; i++) // 1부터 9까지 수 넣어보면서 체크
	{
		board[points[depth].first][points[depth].second] = i;
		if (check(points[depth])) // 결과가 유효하다면 다음 빈칸 채우러 감
			sukudo(depth + 1);
		if (found) // 스도쿠가 완성되었을 경우 더이상 해를 찾을 필요가 없으므로 함수 종료
			return;
	}
	board[points[depth].first][points[depth].second] = 0; // 해를 못찾았을 경우 값 비우기
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