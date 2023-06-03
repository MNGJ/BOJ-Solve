#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string str;
vector<int> v;
int index = 0;
int first_minus = 50;
bool find_minus = false;
int result = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '+' || str[i] == '-')
		{
			v.push_back(stoi(str.substr(index, i - index)));
			if (find_minus == false && str[i] == '-') // ù ���̳ʽ����
			{
				find_minus = true;
				first_minus = v.size(); // ���̳ʽ��� �������� ����
			}
			index = i + 1;
		}
		if (str.find('+', index) == string::npos && str.find('-', index) == string::npos) // + Ȥ�� -�� ���̻� ���ٸ�(������ ���� �־���)
		{
			v.push_back(stoi(str.substr(index)));
			break;
		}
	}



	for (int i = 0; i < v.size(); i++)
	{
		if (i < first_minus)
			result += v[i];
		else
			result -= v[i];
	}

	cout << result;

	return 0;
}