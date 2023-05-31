#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string S;
int q, l, r;
char alpha;
int arr[26][200001]; // 알파벳 범위 x 문자열 최대 길이(모두 같은 알파벳일 경우 가정)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> S;

	for(int i = 0; i < 26; i++)
		for (int j = 1; j <= S.length(); j++)
		{
			arr[i][j] = arr[i][j - 1];
			if (S[j - 1] - 97 == i) // 문자열의 문자 - 97(아스키코드)와 i가 같다면
			{
				arr[i][j]++;
			}
		}

	cin >> q;

	while (q--)
	{
		cin >> alpha >> l >> r;

		cout << arr[alpha - 97][r + 1] - arr[alpha - 97][l] << '\n'; // arr[][0]=0이므로 r+1 부터 l까지
	}


	return 0;
}