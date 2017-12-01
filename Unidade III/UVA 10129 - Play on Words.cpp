#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 1000
#define NumCaracters 26

int graph[N][N];
bool visited[N];
int inDegree[N];
int outDegree[N];
int n;


void dfs_visit(int i)
{
    for(int j = 1; j <= NumCaracters; j++)
        if(graph[i][j] && !visited[j])
        {
            visited[j] = true;
            dfs_visit(j);
        }
    return ;
}

int DFS()
{
    int count = 0;
    for(int i = 1; i <= NumCaracters; i++)
    {
        if(inDegree[i] || outDegree[i])
        {
            if(!visited[i])
            {
                visited[i] = true;
                count++;
                dfs_visit(i);
            }
        }
    }
    if(count > 1)
        return 0;
    else
        return 1;
}

int hasPath()
{
    int i;
    int in = 0;
    int out = 0;

    for(i = 1; i <= NumCaracters; i++)
    {
        if(outDegree[i] - inDegree[i] == 1)
        {
            in++;
            if(in > 1) break;
        }
        else if(inDegree[i] - outDegree[i] == 1)
        {
            out++;
            if(out > 1) break;
        }
        else if(inDegree[i] - outDegree[i] > 1 )
            break;
    }

    if( i <= NumCaracters)
        return 0;
    else
        return 1;

}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(visited, 0, sizeof(visited));
        memset(graph, 0, sizeof(graph));
        memset(inDegree, 0, sizeof(inDegree));
        memset(outDegree, 0, sizeof(outDegree));

        char word[1001];
        scanf("%d",&n);

        while(n--)
        {
            scanf("%s", word);
            int lenght = strlen(word);
            int u = word[0] - 'a' + 1;
            int v = word[lenght - 1] - 'a' + 1;

            outDegree[u]++;
            inDegree[v]++;
            graph[u][v] = graph[v][u] = 1;
          }

        if(!DFS())
        {
            printf("The door cannot be opened.\n");
        }
        else
        {
            if(!hasPath())
            {
                printf("The door cannot be opened.\n");
            }
            else
                printf("Ordering is possible.\n");
        }
    }
    return 0;
}
