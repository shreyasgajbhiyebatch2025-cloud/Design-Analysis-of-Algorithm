#include <stdio.h>
#include <stdlib.h>
#define MAX 99

struct node {
    int vertex;
    struct node* next;
};
typedef struct node* GNODE;

GNODE graph[20];
int visited[20];
int queue[MAX], front = -1, rear = -1;
int n;

void insertQueue(int vertex) {
    if (rear == MAX - 1)
        printf("Queue Overflow.\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = vertex;
    }
}

int isEmptyQueue() {
    return (front == -1 || front > rear);
}

int deleteQueue() {
    if (isEmptyQueue()) {
        printf("Queue Underflow\n");
        exit(1);
    }
    return queue[front++];
}

void BFS(int v) {
    printf("\n"); 
    
    insertQueue(v);
    visited[v] = 1;
    
    while (!isEmptyQueue()) {
        int currentVertex = deleteQueue();
        printf("%d\n", currentVertex);
        
        GNODE temp = graph[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                insertQueue(adjVertex);
                visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
	}
    
    
}

void main() {
    int N, E, s, d, i, v;
    GNODE p, q;

    printf("Enter the number of vertices: ");
    scanf("%d", &N);
    n = N;

    for (i = 0; i < N; i++) {
        graph[i] = NULL;
}
