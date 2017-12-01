#include <cstdio>
#include <vector>
#include <bitset>
using namespace std;

typedef vector<int> vi;

#define WHITE 0
#define BLACK 1

bitset<105> colored;
int color[105];
vector<vi> AdjList;
int m, nodes, numBlack;
vi maxBlack;

void calculateBlacks(int currentNode)
{
	if (currentNode == nodes)
	{
		int black = 0;
		int white = 0;
		for (int i = 0; i < nodes; i++)
		{
			if (color[i] == BLACK)
				black++;
			else
				white++;
		}
		if (black > numBlack)
		{
			numBlack = black;
			maxBlack.clear();
			for (int i = 0; i < nodes; i++)
			{
				if (color[i] == BLACK)
					maxBlack.push_back(i);
			}
		}
		return;
	}

	bool isBlack = true;
	for (int i = 0; i < (int) AdjList[currentNode].size(); i++)
	{
		int v = AdjList[currentNode][i];
		if (colored[v] && color[v] == BLACK)
		{
			isBlack = false;
			break;
		}
	}
	colored.set(currentNode);
	if (isBlack)
	{
		color[currentNode] = BLACK;
		calculateBlacks(currentNode + 1);
	}
	color[currentNode] = WHITE;
	calculateBlacks(currentNode + 1);
	colored.reset(currentNode);
}


int main()
{
	int k;
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d %d", &nodes, &k);

		AdjList.assign(nodes, vi());
		colored.reset();
		numBlack = -1;
		int u, v;
		for (int i = 0; i < k; i++)
		{
			scanf("%d %d", &u, &v);
			u--;
			v--;
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}

		calculateBlacks(0);

		printf("%d\n", numBlack);
		for (int i = 0; i < maxBlack.size(); i++)
		{
			printf("%d", maxBlack[i] + 1);
			if (i < maxBlack.size() - 1)
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}
