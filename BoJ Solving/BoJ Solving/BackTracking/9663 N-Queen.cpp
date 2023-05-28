#include <iostream>
#define MAX 15
using namespace std;

int col[MAX];
int n, cnt = 0;

bool check(int depth)
{
    for (int i = 0; i < depth; i++)
        if (col[i] == col[depth] || abs(col[depth] - col[i]) == depth - i) // �밢���̰ų� ���� ����
            return false;
    // col[i] �� �ǹ��ϴ� ���� x��ǥ, i�� �ǹ��ϴ°��� y��ǥ�̹Ƿ� ���̰� �����ϴٸ� �밢���� �ִ�
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
            col[depth] = i; // �ش� ��ġ�� �� ��ġ
            if (check(depth)) // ��ȿ�ϴٸ� ���� �� �� ��ġ, ��ȿ���� �ʴٸ� ���� �� �� ��ġ ����
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