#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
int minDistance(int dist[50], bool visited[50], int n)
{
    int min = INT_MAX, min_index,i;
    for ( i = 0; i < n; i++)
    {
        if (!visited[i] && dist[i] <= min)
        {
            min_index = i;
            min = dist[i];
        }
    }
    return min_index;
}
void dijkstra(int graph[50][50], int source, int n)
{
    int dist[50], i,v,last[50];
    bool visited[50];

    for (i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[source] = 0;

    for (i = 0; i < n - 1; i++)
    {
        int u = minDistance(dist, visited, n);
        visited[u] = true;

        for ( v = 0; v < n; v++)
        {
            if ((!visited[v]) && (graph[u][v]) && (dist[u] + graph[u][v] < dist[v]))
            {
                dist[v] = dist[u] + graph[u][v];
                last[v]=u;
            }
        }
    }
    for ( i = 0; i < n; i++)
    {
    	printf("%d ==> %d : path taken: %d",source,i,i);
        int w= i;
        while(w != source){
            printf("<-- %d",last[w]);
            w = last[w];
        }
        printf("\n distance : %d \n", dist[i]);
    }
}
void main()
{
    int graph[50][50] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    int source = 0,n = 9;
    dijkstra(graph, source, n);
}
