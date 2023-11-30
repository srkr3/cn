#include <stdio.h>
int parent[50];
void sunion(int p, int q)
{
    parent[p] = q;
}
int find(int k)
{
    if (parent[k] > 0)
    {
        k = parent[k];
    }
    return k;
}
void main()
{
    int graph[50][50];
    int n, min, u, v, p, q, mst[50][2], cost = 0,i,j;
    printf("enter no.of vertices: ");
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    for ( i = 0; i < n; i++)
    {
        min = 99;
        for ( j = 0; j < n; j++)
        {
            if (graph[i][j] != 99)
            {
                if (min > graph[i][j])
                {
                    min = graph[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        p = find(u);
        q = find(v);
        if (p != q)
        {
            mst[i][0] = u;
            mst[i][1] = v;
            cost = cost + graph[u][v];
            sunion(p, q);
        }
        else
        {
            mst[i][0] = -1;
            mst[i][1] = -1;
        }
    }
    printf("minimum cost is: %d\n\n",cost);
    for ( i = 0; i < n; i++)
    {
        if (mst[i][0] != -1 && mst[i][1] != -1)
            printf("%c %c %d\n", mst[i][0] + 65, mst[i][1] + 65, graph[mst[i][0]][mst[i][1]]);
    }
}

