#include "stdc++.h"
using namespace std;
#define Max_R 1
#define Max_V 40000
#define Max_E 400000
#define Max_W 300

int main()
{
	set<pair<int, int>> container;

	set<pair<int, int>>::iterator it;
    freopen("input2.txt","w",stdout);
	srand(time(NULL));
	int Vertice;
	int Edge;
	for (int i=1; i<=Max_R; i++)
	{
		Vertice = 1 + rand() % Max_V;
		Edge = 1 + rand() % Max_E;
		while (Edge > Vertice*(Vertice-1)/2)
			Edge = 1 + rand() % Max_E;
        cout << Vertice << Edge;
		for (int j=1; j<=Edge; j++)
		{
			int a = 1 + rand() % Vertice;
			int b = 1 + rand() % Vertice;
			pair<int, int> p = make_pair(a, b);
			while (container.find(p) != container.end())
			{
				a = 1 + rand() % Vertice;
				b = 1 + rand() % Vertice;
				p = make_pair(a, b);
			}
			container.insert(p);
		}
		for (it=container.begin(); it!=container.end(); ++it)
		{
			int y = 1 + rand() % Max_W;

			printf("%d %d %d\n", it->first, it->second, y);
		}
		container.clear();
		cout << "\n";
	}
	return(0);
}
