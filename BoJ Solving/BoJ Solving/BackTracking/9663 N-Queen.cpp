#include <iostream>
#define MAX 15
using namespace std;

int col[MAX];
int n, cnt = 0;

bool check(int depth)
{
    for (int i = 0; i < depth; i++)
        if (col[i] == col[depth] || abs(col[depth] - col[i]) == depth - i) // 대각선이거나 같은 라인
            return false;
    // col[i] 가 의미하는 것이 x좌표, i가 의미하는것이 y좌표이므로 차이가 일정하다면 대각선에 있다
    return true;
}

void nqueen(int depth)
{
    if (depth == n)
        cnt++;
    else
    {
        for (int i = 0; i < n; i++)
        {
            col[depth] = i; // 해당 위치에 퀸 배치
            if (check(depth)) // 유효하다면 다음 행 퀸 배치, 유효하지 않다면 현재 행 퀸 배치 변경
                nqueen(depth + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    nqueen(0);
    cout << cnt;

    return 0;
}