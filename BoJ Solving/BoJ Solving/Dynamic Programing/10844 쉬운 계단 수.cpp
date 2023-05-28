#include  <iostream>
#define NUM 1000000000
using namespace std;

int N, result = 0;
int dp[101][10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i < 10; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][1];
            else if (j == 9)
                dp[i][j] = dp[i - 1][8];
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
        }
    }

    for (int i = 0; i < 10; i++)
    {
        result += dp[N][i] % NUM;
    }

    cout << result;

    return 0;
}