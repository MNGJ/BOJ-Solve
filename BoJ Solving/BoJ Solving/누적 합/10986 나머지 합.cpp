#include <iostream>
using namespace std;

int N, M, A;
long long arr[1001];
long long sum = 0, result = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> A;
        sum += A;
        if (sum % M == 0)
            result++; // j ~ i 까지 누적합-누적합 아니라, 첫 원소부터 i까지 누적합도 경우의 수를 넣어줌
        arr[sum % M]++;
    }

    for (int i = 0; i <= M; i++)
        result += arr[i] * (arr[i] - 1) / 2; // nC2 

    cout << result;

    return 0;
}