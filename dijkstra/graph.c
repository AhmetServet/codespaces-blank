#include <stdio.h>

#define MAX_SIZE 10

typedef struct {
    int matrix[MAX_SIZE][MAX_SIZE];
    int numVertices;
} Graph;

void createGraph(Graph* g, int numVertices) {
    g->numVertices = numVertices;
    for(int i=0; i<numVertices; i++) {
        for(int j=0; j<numVertices; j++) {
            g->matrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int from, int to) {
    g->matrix[from][to] = 1;
}

void printGraph(Graph* g) {
    int i, j;

    for (i = 0; i < g->numVertices; i++) {
        printf("%d: ", i);
        for (j = 0; j < g->numVertices; j++)
            printf("%d ", g->matrix[i][j]);
        printf("\n");
    }
}

int main() {
    // Graph g;
    // createGraph(&g, 5);
    // addEdge(&g, 0, 1);
    // addEdge(&g, 0, 2);
    // addEdge(&g, 1, 2);
    // addEdge(&g, 2, 0);
    // addEdge(&g, 2, 3);

    // printGraph(&g);

    return 0;
}