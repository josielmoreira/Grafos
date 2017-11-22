#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#define N 1000000

using namespace std;

struct node {
    int initial;
    int final;
    int distance;
} graph [1000000];

int parent [1000000];
int size [1000000];

bool compare (node s, node t) {
    if ( s.distance < t.distance ) {
      return true;
    }
    return false;
}

int findset (int n) {
    if (n != parent[n]) {
      parent[n] = findset(parent[n]);
    }
    return parent [n];
}

int main () {
    int numEdges, numVertex;

    while ( scanf ("%d %d", &numEdges, &numVertex) ) {
        if ( numEdges == 0 && numVertex == 0 )
          break;
        int totalDist = 0;

        for ( int i = 0; i < numVertex; i++ ) {
            parent [i] = i;
            size [i] = 1;
            scanf ("%d %d %d", &graph [i].initial, &graph [i].final, &graph [i].distance);
            totalDist += graph [i].distance;
        }

        parent [numVertex] = numVertex;
        size [numVertex] = 1;

        sort (graph, graph + numVertex, compare);

        int selected = numEdges - 1;
        int countDist = 0;

        for ( int i = 0; i < numVertex && selected; i++ ) {
            int pu = findset (graph [i].initial);
            int pv = findset (graph [i].final);

            if ( pu != pv ) {
                if ( size [pu] > size [pv] ) swap (pu, pv);
                size [pv] += size [pu];
                parent [pu] = pv;
                countDist += graph [i].distance;
                selected--;
            }
        }

        printf ("%d\n", totalDist - countDist);
    }

    return 0;
}
