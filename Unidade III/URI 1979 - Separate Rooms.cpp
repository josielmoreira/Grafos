//#include <stdio.h>
//#include <string.h>
//#include <queue>

#include <bits/stdc++.h>

#define MAX_STUDENTS 101

using namespace std;

int friendship[MAX_STUDENTS][MAX_STUDENTS];
int classroom[MAX_STUDENTS];


int isBipartite(int student, int n){
	classroom[student] = 1;
	queue <int> q;
	q.push(student);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for (int v = 0; v < n; ++v){
			if (friendship[u][v] && classroom[v] == -1){
				classroom[v] = 1 - classroom[u];
				q.push(v);
			}

			else if (friendship[u][v] && classroom[v] == classroom[u])
				return 0;
		}
	}
	return 1;
}

void initValues()
{
memset(friendship, 0, sizeof(friendship));
memset(classroom, -1, sizeof(classroom));
}


int main(void)
{
	int N;
	int friendsParticipant, participant;
	char in;

	while(N--)
	{
		scanf("%d",&N);
		if(N == 0) break;
		initValues();
		for(int i = 0; i < N; ++i)
		{
			scanf("%d", &participant);
			participant--;
			while(scanf("%d%c", &friendsParticipant, &in) == 2 )
			{
				friendsParticipant--;
				friendship[participant][friendsParticipant]++;
				friendship[friendsParticipant][participant]++;
				if(in =='\n') break;
			}
		}
		if(isBipartite(0,N))
			printf("SIM\n");
		else
			printf("NAO\n");

	}
  	return 0;
}
