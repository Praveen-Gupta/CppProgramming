#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
	int c;
	while (a != 0)
	{
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}

vector < int > connectedCities(int n, int g, vector < int > originCities, vector < int > destinationCities)
{
	vector <int> connections;
	connections.reserve(originCities.size());
	int size = std::min(originCities.size(), destinationCities.size());
	for (int i = 0; i < size; i++)
	{
		if (gcd(originCities[i], destinationCities[i]) > g)
			connections.push_back(1);
		else
			connections.push_back(0);
	}
	return connections;
}

int mainFindConnectedCities()
{
	vector <int> con = connectedCities(6, 1, { 1,2,4,6 }, { 3,3,3,4 });
	for (int i = 0; i < con.size(); i++)
		cout << con[i] << endl;
	return 0;
}

