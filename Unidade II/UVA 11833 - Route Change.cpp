#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define INFINITE 100000
#define MAX 250

using namespace std;

typedef pair< int , int > ii;
vector < ii > serviceRoute[MAX];
int distances[MAX];

int N, M, C, K;


int dijkstra()
{
        priority_queue <pair<int, int>,
             vector<pair<int, int> >,
             greater<pair<int, int> > > pq;

        for( int i = 0; i < N; i++ )
        {
              distances[i] = INFINITE;
        }

        distances[K] = 0;
        pq.push(ii(K, 0));

        while(!pq.empty())
        {
            int origin = pq.top().first;
            int cost = pq.top().second;
            pq.pop();

            for( int i = 0; i < serviceRoute[origin].size(); i++ )
            {
                int destination = serviceRoute[origin][i].first;
                int nextCost = serviceRoute[origin][i].second;

                if( origin < C)
                {
                    // origin and destination are adjacents cities
                    if( destination == origin + 1 && distances[destination] > distances[origin] + nextCost)
                    {
                        distances[destination] = distances[origin] + nextCost;
                        pq.push(ii(destination, distances[destination]));
                    }

                }
                //route of destination is  larger than route of origin plus cost of road descovered
                else if( distances[destination] >  distances[origin] + nextCost)
                {
                    //update distance to destination.
                    distances[destination] = distances[origin] + nextCost;
                    pq.push(ii(destination, distances[destination]));
                }

            }
        }
    return distances[C-1]; //return the total of services routes C - 1 routes
}
int main()
{
    while(scanf("%d %d %d %d", &N, &M, &C, &K))
    {
        if (!N && !M && !C && !K) break;

        while (M--) {
            int start, dest, roadCost;
            scanf("%d %d %d", &start, &dest, &roadCost);
            serviceRoute[start].push_back(ii(dest, roadCost));
            serviceRoute[dest].push_back(ii(start, roadCost));
        }

        int result = dijkstra();
        printf("%d\n", result);

        for( int i = 0; i < N; i++ )
            serviceRoute[i].clear();
    }

	return 0;
}
