#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef struct{
  int u,v,w;
} Edge;

int distance[1005];
int predecessor[1005];
Edge edge[2005];
int n, m;

bool BellmanFord(int s){
  int i, j;

  for(i = 0; i < n; i++){   //initialize all vertex
    distance[i] = INT_MAX;
    predecessor[i] = 0;
  }

  distance[s] = 0;

  for(i = 0; i < n-1; i++)
    for(j = 0; j < m; j++){
      if(distance[edge[j].v] > distance[edge[j].u]+edge[j].w){
	         distance[edge[j].v] = distance[edge[j].u]+edge[j].w;
	         predecessor[edge[j].v] = edge[j].u;
      }
    }

  for(j = 0; j < m; j++){   //verify negative cycle
    if(distance[edge[j].v] > distance[edge[j].u]+edge[j].w)
    return false;
  }
  return true;
}

int main(){
  int t, i;

  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &n, &m);
    for(i = 0; i < m; i++){
      scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
    }

   if(BellmanFord(0)) {
   	printf("not ");
   }
    	printf("possible\n");


  }
  return 0;
}
