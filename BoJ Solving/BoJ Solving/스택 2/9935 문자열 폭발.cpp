#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

string str, sub_str, answer = "";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str;
	cin >> sub_str;

	int sub_str_idx = sub_str.length() - 1;
	for (int i = 0; i < str.length(); i++)
	{
		answer += str[i];
		if (answer[answer.length() - 1] == sub_str[sub_str_idx])
		{
			if (answer.length() >= sub_str.length())
			{
				int cnt = 1;
				for (int j = sub_str_idx - 1; j >= 0; j--)
				{
					if (answer[answer.length() - (sub_str_idx - j) - 1] == sub_str[j])
						cnt++;
				}

				if (sub_str.length() == cnt)
					for (int k = 0; k < sub_str.length(); k++)
						answer.pop_back();
			}
		}
	}
	
	if (answer.length() > 0)
		cout << answer;
	else
		cout << "FRULA";

	return 0;
}