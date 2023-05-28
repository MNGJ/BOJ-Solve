#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, answer = 0, dp_max, temp;
vector<int> v;
int DP[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    DP[0] = 1;

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        v.push_back(temp); 
        dp_max = 0;
        for (int j = 0; j < v.size(); j++) // DP[i] 보다 낮은 값들 루프
        {
            if (v[i] > v[j]) // 0부터 i-1까지 i와 비교하며 작을경우 검사
                if (dp_max < DP[j]) // 비교한게 작은 것들 중에서 DP값이 가장 큰 것 저장
                    dp_max = DP[j];
        }
        DP[i] = dp_max + 1;
        answer = max(answer, DP[i]);
    }

    cout << answer;

    return 0;
}