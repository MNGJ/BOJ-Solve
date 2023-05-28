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
        dp[1][i] = 1;  // 자릿수가 한 자릿수 일땐 0일때 제외하고 전부 1

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)             // 첫째 자리 수가 0일때 자릿수가 -1인 수는 없으므로 [1]만 더함
                dp[i][j] = dp[i - 1][1];
            else if (j == 9)
                dp[i][j] = dp[i - 1][8]; // 첫째 자리 수가 9일때 자릿수가 10인 수는 없으므로 [8]만 더함
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1]; // 현재 첫째 자리 수에 전 단계의 자리수 +- 1 였던 값을 더함 
            dp[i][j] %= NUM;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        result = (result + dp[N][i]) % NUM; // +=로 할 경우 연산 순서가 달라져서 (result + dp[N][i])로 해야함
    }

    cout << result;

    return 0;
}