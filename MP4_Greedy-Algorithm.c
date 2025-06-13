#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int numNodes;

void dijkstra(int source) {
    int dist[MAX_NODES];
    int visited[MAX_NODES] = {0};
    
    // Initialize distances to infinity and source distance to 0
    for (int i = 0; i < numNodes; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    for (int count = 0; count < numNodes - 1; count++) {
        // Find the minimum distance node from the set of nodes not yet processed
        int minIndex = -1;
        int minValue = INT_MAX;
        for (int v = 0; v < numNodes; v++) {
            if (!visited[v] && dist[v] < minValue) {
                minValue = dist[v];
                minIndex = v;
            }
        }

        // Mark the picked node as processed
        visited[minIndex] = 1;

        // Update the distance value of the adjacent vertices of the picked node
        for (int v = 0; v < numNodes; v++) {
            if (!visited[v] && graph[minIndex][v] && dist[minIndex] != INT_MAX && 
                dist[minIndex] + graph[minIndex][v] < dist[v]) {
                dist[v] = dist[minIndex] + graph[minIndex][v];
            }
        }
    }

    // Print the distance array
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < numNodes; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int numEdges, u, v, weight, source;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    // Initialize the graph with 0s
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter each edge in the format (u v weight):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &u, &v, &weight);
        graph[u][v] = weight; // Directed graph
        graph[v][u] = weight; // Uncomment this line for an undirected graph
    }

    printf("Enter the source node: ");
    scanf("%d", &source);

    dijkstra(source);

    return 0;
}
