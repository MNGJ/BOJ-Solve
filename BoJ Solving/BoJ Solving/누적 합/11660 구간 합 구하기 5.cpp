#include <iostream>
using namespace std;

int arr[1025][1025], dp[1025][1025];
int N, M, x, x_1, y_1, x_2, y_2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
        }

    while (M--)
    {
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        cout << dp[x_2][y_2] - dp[x_2][y_1 - 1] - dp[x_1 - 1][y_2] + dp[x_1 - 1][y_1 - 1] << '\n';
    }

    return 0;
}