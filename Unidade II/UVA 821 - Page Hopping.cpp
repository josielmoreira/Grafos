#include <algorithm>
#include <iostream>
#include <cstdio>

#define MAX_PAGES 101
#define INFINITE 99999

using namespace std;

int AdjacencyMatrix[MAX_PAGES][MAX_PAGES];

int main()
{
	int pageA, pageB;
	int cases = 1;

	while (cin >> pageA >> pageB && (pageA || pageB))
	{
		if (pageA == 0 && pageB == 0) break;

		for (int i = 0; i < MAX_PAGES; ++i)
		{
			for (int j = 0; j < MAX_PAGES; ++j)
			{
				AdjacencyMatrix[i][j] = INFINITE;
			}
		}

		AdjacencyMatrix[pageA][pageB] = 1;

		while(cin >> pageA >> pageB  && (pageA || pageB))
		{
			if (pageA == 0 && pageB == 0) break;

			AdjacencyMatrix[pageA][pageB] = 1;
		}

		for (int k = 1; k < MAX_PAGES; ++k)
		{
			for (int i = 1; i < MAX_PAGES; ++i)
			{
				for (int j = 1; j < MAX_PAGES; ++j)
				{
					AdjacencyMatrix[i][j] = min(AdjacencyMatrix[i][j], AdjacencyMatrix[i][k] + AdjacencyMatrix[k][j]);
				}
			}
		}

		float sumPathLengths = 0;
		float numPaths = 0;

		for (int i = 1; i < MAX_PAGES; ++i)
		{
			for (int j = 1; j < MAX_PAGES; ++j)
			{
				if (i == j) continue;
				if (i != j && AdjacencyMatrix[i][j] != INFINITE)
				{
					sumPathLengths += AdjacencyMatrix[i][j];
					++numPaths;
				}
			}
		}

		printf("Case %d: average length between pages = %.3f clicks\n", cases++, (sumPathLengths / numPaths));
	}


}
