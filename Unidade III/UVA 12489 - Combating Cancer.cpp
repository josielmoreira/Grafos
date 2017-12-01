#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>

#define MAX 10001
using namespace std;

vector<int> FirstMol[MAX];
vector<int> SecondMol[MAX];
vector<int> AtomA[MAX];
vector<int> AtomB[MAX];

bool compare(vector<int>& a, vector<int>& b)
{
    if (a.size() != b.size())
    {
      return a.size() < b.size();
    }
    for(int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
          return a[i] < b[i];
        }
    }
    return false;
}

bool equivalents( vector<int>& a, vector<int>& b)
{
    if (a.size() != b.size())
    {
      return false;
    }
    for(int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
          return false;
        }
    }
    return true;
}

void initValues()
{
  memset(FirstMol, 0, sizeof(FirstMol));
  memset(SecondMol, 0, sizeof(SecondMol));
  memset(AtomA, 0, sizeof(AtomA));
  memset(AtomB, 0, sizeof(AtomB));
}

int main()
{
    int N;
    int u, v;

    while(scanf("%d",&N) == 1)
    {
      initValues();

        for(int i = 0; i < N - 1; i++)
        {
            scanf("%d %d",&u, &v);
            FirstMol[u].push_back(v);
            FirstMol[v].push_back(u);
        }
        for(int i = 0; i < N - 1; i++)
        {
            scanf("%d %d",&u,&v);
            SecondMol[u].push_back(v);
            SecondMol[v].push_back(u);
        }
        for(int i = 1; i <= N; i++)
        {
            for(int j = 0; j < FirstMol[i].size(); j++)
            {
                AtomA[i].push_back(FirstMol[FirstMol[i][j]].size());
            }

            sort(AtomA[i].begin(), AtomA[i].end());

            for(int j = 0; j < SecondMol[i].size(); j++)
            {
                AtomB[i].push_back(SecondMol[SecondMol[i][j]].size());
            }

            sort(AtomB[i].begin(), AtomB[i].end());
        }

        sort(AtomA + 1, AtomA + N + 1, compare);
        sort(AtomB + 1, AtomB + N + 1, compare);

        bool bondExistent = true;
            for(int i = 1; i < N; i++)
            {
              bondExistent = bondExistent & equivalents(AtomA[i], AtomB[i]);
            }

        if(!bondExistent) printf("N\n");
        else printf("S\n");
    }
}
