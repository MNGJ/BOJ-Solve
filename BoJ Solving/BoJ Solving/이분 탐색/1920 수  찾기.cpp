#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    cin >> M;
    int tmp;
    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        cout << binary_search(arr, arr + N, tmp) << '\n';
    }
        return 0;
}