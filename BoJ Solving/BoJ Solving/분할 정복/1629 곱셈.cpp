#include <iostream>
using namespace std;

long long A, B, C, k;

long long solve(long long b)
{
	if (b == 0) return 1;
	if (b == 1) return A % C;

	k = solve(b / 2) % C;
	if (b % 2 == 0) return k * k % C;
	return k * k % C * A % C;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B >> C;

	cout << solve(B);

	return 0;
}