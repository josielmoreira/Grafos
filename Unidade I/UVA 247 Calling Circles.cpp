#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main() {

    int numVertex, numEdges, cases = 0;

    while(cin >> numVertex >> numEdges) {

        if(!numVertex && !numEdges)
            break;
        if(cases)
            puts("");
        
        printf("Calling circles for data set %d:\n", ++cases);
        
        map<string, int> sets;
        int size = 0, graph[26][26] = {}, i, j, k;
        int u, v, visited[26] = {};
        string name[26], name1, name2;

        while(numEdges--) {
            cin >> name1 >> name2;
            u = sets[name1];
            if(u == 0)
                sets[name1] = ++size, u = size, name[size] = name1;
            v = sets[name2];
            if(v == 0)
                sets[name2] = ++size, v = size, name[size] = name2;
            graph[u][v] = 1;
        }
        
        for(i = 1; i <= size; i++)
            graph[i][i] = 1;
            
        for(k = 1; k <= size; k++) {
            for(i = 1; i <= size; i++) {
                for(j = 1; j <= size; j++) {
                    if(graph[i][k] == 1 && graph[k][j] == 1)
                        graph[i][j] = 1;
                }
            }
        }
        
        for(i = 1; i <= size; i++) {
            if(!visited[i]) {
                int counter = 0;
                for(j = 1; j <= size; j++) {
                    if((!visited[j]) && graph[i][j] && graph[j][i]) {
                        visited[j] = 1;
                        visited[i] = 1;
                        if(counter)
                            printf(", ");
                        printf("%s", name[j].c_str());
                        counter++;
                    }
                }
                puts("");
            }
        }
    }
    return 0;
}
