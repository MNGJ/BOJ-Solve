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
            result++; // j ~ i ���� ������-������ �ƴ϶�, ù ���Һ��� i���� �����յ� ����� ���� �־���
        arr[sum % M]++;
    }

    for (int i = 0; i <= M; i++)
        result += arr[i] * (arr[i] - 1) / 2; // nC2 

    cout << result;

    return 0;
}