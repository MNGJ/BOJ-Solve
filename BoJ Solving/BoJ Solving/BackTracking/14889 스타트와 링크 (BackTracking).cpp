#include <iostream>
#include <cmath>
using namespace std;

int n;
int S[22][22];
bool visit[12];
int result = -1;
int start[12];
int link[12];

void make_team(int pos, int depth)
{
    if (n / 2 == depth)
    {
        int temp1 = 1;
        int temp2 = 1;
        for (int i = 1; i <= n; i++)
        {
            if (visit[i])
            {
                start[temp1] = i;
                temp1++;
            }
            else
            {
                link[temp2] = i;
                temp2++;
            }
        }
        temp1 = 0;
        temp2 = 0;
        for (int i = 1; i <= n / 2 - 1; i++)
        {
            for (int j = i + 1; j <= n / 2; j++)
            {
                temp1 += S[start[i]][start[j]] + S[start[j]][start[i]];
                temp2 += S[link[i]][link[j]] + S[link[j]][link[i]];
            }
        }
        int temp = abs(temp1 - temp2);
        if (result == -1 || result > temp)
            result = temp;

        return;
    }


    for (int i = pos; i < n; i++) // i < n인 이유는 반복을 제외하기 위해
    {
        if (!visit[i])
        {
            visit[i] = true;
            make_team(i + 1, depth + 1);
            visit[i] = false;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> S[i][j];
        }

    make_team(1, 0);
    cout << result;

    return 0;
}