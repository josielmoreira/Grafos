#include <cstdio>
#include <vector>
#include <cstring>
#include <bitset>
using namespace std;

typedef vector<int> sequenceOut;

vector<sequenceOut> AdjList;
bitset<26> visited, appeared;
sequenceOut finishingOrder;

void dfs_visit(int u) {
	visited.set(u);

	for (int i = 0; i < (int) AdjList[u].size(); i++) {
		int v = AdjList[u][i];
		if (!visited[v]) {
			dfs_visit(v);
		}
	}

	finishingOrder.push_back(u);
}

int main() {
	char stack[25], stackOut[25];
	AdjList.assign(26, sequenceOut());

	scanf("%s", stackOut);
	while (scanf("%s", stack), strcmp(stack, "#") != 0) {
		for (int i = 0; i < (int) strlen(stack) && i < (int) strlen(stackOut); i++) {
			if (stackOut[i] != stack[i]) {
				appeared.set(stackOut[i] - 'A');
				appeared.set(stack[i] - 'A');
				AdjList[stackOut[i] - 'A'].push_back(stack[i] - 'A');
				break;
			}
		}
		strcpy(stackOut, stack);
	}

	for (int i = 0; i < 26; i++) {
		if (!visited[i] && appeared[i])
			dfs_visit(i);
	}

	for (int i = finishingOrder.size() - 1; i >= 0; i--) {
		printf("%c", finishingOrder[i] + 'A');
	}
	printf("\n");

	return 0;
}
