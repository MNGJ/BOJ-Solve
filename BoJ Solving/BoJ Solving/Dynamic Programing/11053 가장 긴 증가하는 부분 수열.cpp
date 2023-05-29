#include <iostream>
#include <algorithm>
using namespace std;

int N, answer = 1;
int arr[1001];
int DP[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;


    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        DP[i] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if(arr[i] > arr[j])
                DP[i] = max(DP[i], DP[j] + 1);
        }
        answer = max(answer, DP[i]);
    }

    cout << answer;

    return 0;
}