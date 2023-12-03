#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int N;

bool can_see(int x1, int x2, int h1, int h2, vector<int> buildings)
{
	for (int x = 0; x < N; x++)
	{
		if (x == x1 || x == x2)
			continue;

		if ((x1 < x && x < x2) || (x2 < x && x < x1))
		{
			double height_at_x = h1 + 1.0*(h2 - h1) * (x - x1) / (x2 - x1);
			if (height_at_x < 0)
				cout << height_at_x << '\n';
			if (buildings[x] >= height_at_x)
				return false;
		}
	}
	return true;
}

int find_building_with_most_views(vector<int> buildings)
{
	int max_views = 0;
	for (int i = 0; i < N; i++)
	{
		int views = 0;
		for (int j = 0; j < N; j++)
		{
			if (i != j && can_see(i, j, buildings[i], buildings[j], buildings))
				views += 1;
		}
		if (views > max_views)
			max_views = views;
	}
	return max_views;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	vector<int> buildings(N);

	for (int i = 0; i < N; i++)
	{
		cin >> buildings[i];
	}

	int views = find_building_with_most_views(buildings);
	cout << views;

	return 0;
}