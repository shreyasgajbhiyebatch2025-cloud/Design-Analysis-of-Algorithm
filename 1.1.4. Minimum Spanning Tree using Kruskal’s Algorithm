#include <stdio.h>
#include <stdlib.h>
#include <limits.h>





#define INF 9999

typedef struct {
    int u, v, weight;
} Edge;

int compareEdges(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    if (edgeA->weight != edgeB->weight) {
        return edgeA->weight - edgeB->weight;
    }
    if (edgeA->u != edgeB->u) {
        return edgeA->u - edgeB->u;
    }
    return edgeA->v - edgeB->v;
}

int findSet(int i, int parent[]) {
    if (parent[i] == i)
        return i;
    return parent[i] = findSet(parent[i], parent);
}

void unionSet(int i, int j, int parent[]) {
    int rootI = findSet(i, parent);
    int rootJ = findSet(j, parent);
    if (rootI != rootJ) {
        parent[rootI] = rootJ;
    }
}void kruskalMST(int **cost, int V) {
    int maxEdges = (V * (V - 1)) / 2;
    Edge *edges = (Edge *)malloc(maxEdges * sizeof(Edge));
    int edgeCount = 0;

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (cost[i][j] != INF) {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = cost[i][j];
                edgeCount++;
            }
        }
    }

    qsort(edges, edgeCount, sizeof(Edge), compareEdges);

    int *parent = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int mstEdges = 0;
    int totalCost = 0;

    for (int i = 0; i < edgeCount; i++) {
        if (mstEdges == V - 1) {
            break;
        }

        int u = edges[i].u;
        int v = edges[i].v;

        if (findSet(u, parent) != findSet(v, parent)) {
            unionSet(u, v, parent);
            printf("Edge %d:(%d, %d) cost:%d\n", mstEdges, u, v, edges[i].weight);
            totalCost += edges[i].weight;
            mstEdges++;
        }
    }    printf("Minimum cost= %d\n", totalCost);

    free(edges);
    free(parent);



	
}


int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
