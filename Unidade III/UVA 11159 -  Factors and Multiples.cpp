#include <stdio.h>
#include <string.h>

#define MAX_N 101
#define MAX_M 101
const int MAX_E = 10001;

int path[MAX_E][MAX_E];
int next[MAX_E];
int left[MAX_E];
int right[MAX_E];
int visited[MAX_E];

int augmentingPath(int node)
{
    for(int i = 0; i < next[node]; i++)
    {
        int nodeAux = path[node][i];
        if(!visited[nodeAux])
        {
            visited[nodeAux] = 1;
            if(right[nodeAux] < 0 || augmentingPath(right[nodeAux]))
            {
                left[node] = nodeAux;
                right[nodeAux] = node;
                return 1;
            }
        }
    }
    return 0;
}

int initValues()
{
  memset(next, 0, sizeof(next));
  memset(left, -1, sizeof(left));
  memset(right, -1, sizeof(right));
}

int main()
{
    int T;
    int cases = 1;
    int n, m;
    int setA[MAX_N], setB[MAX_M];
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
          scanf("%d", &setA[i]);
        }
        scanf("%d", &m);
        for(int i = 0; i < m; i++)
        {
          scanf("%d", &setB[i]);
        }
        initValues();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(setB[j] == 0 || (setA[i] && setB[j] % setA[i] == 0))
                {
                    path[i][next[i]++] = n + j;
                }
            }
        }
        int answer = 0;
        for(int i = 0; i < n; i++)
        {
            if(left[i] < 0)
            {
                memset(visited, 0, sizeof(visited));
                if(augmentingPath(i))
                    answer++;
            }
        }
        printf("Case %d: %d\n", cases++, answer);
    }
    return 0;
}

