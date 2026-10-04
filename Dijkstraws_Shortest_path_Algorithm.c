#include <stdio.h>

#define MAX 20
#define INF 9999

int main()
{
    int n;
    int graph[MAX][MAX];
    int distance[MAX];
    int visited[MAX];

    int source;
    int i, j, count;
    int minDistance;
    int current;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter weighted adjacency matrix:\n");
    printf("Enter 0 if there is no direct edge.\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    /* Initialization */
    for (i = 0; i < n; i++)
    {
        distance[i] = INF;
        visited[i] = 0;
    }

    distance[source] = 0;

    /* Dijkstra Algorithm */
    for (count = 0; count < n - 1; count++)
    {
        minDistance = INF;
        current = -1;

        /* Find minimum distance unvisited vertex */
        for (i = 0; i < n; i++)
        {
            if (visited[i] == 0 &&
                distance[i] < minDistance)
            {
                minDistance = distance[i];
                current = i;
            }
        }

        if (current == -1)
            break;

        visited[current] = 1;

        /* Update adjacent vertices */
        for (i = 0; i < n; i++)
        {
            if (visited[i] == 0 &&
                graph[current][i] != 0 &&
                distance[current] + graph[current][i]
                    < distance[i])
            {
                distance[i] =
                    distance[current] + graph[current][i];
            }
        }
    }

    printf("\nShortest distances from source %d:\n", source);

    for (i = 0; i < n; i++)
    {
        if (distance[i] == INF)
        {
            printf("%d -> %d = INF\n", source, i);
        }
        else
        {
            printf("%d -> %d = %d\n",
                   source, i, distance[i]);
        }
    }

    return 0;
}
