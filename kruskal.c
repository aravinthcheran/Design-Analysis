#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function prototypes
int find(struct Subset subsets[], int i);
void unionSets(struct Subset subsets[], int x, int y);
void kruskalMST(struct Edge edges[], int V, int E);

int main() {
    // Number of vertices and edges
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    // Array to store the edges
    struct Edge edges[E];

    // Input the edges
    printf("Enter the source, destination, and weight of each edge:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    // Call the Kruskal's algorithm function
    kruskalMST(edges, V, E);

    return 0;
}

// Find function for union-find
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Union function for union-find
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Kruskal's algorithm function
void kruskalMST(struct Edge edges[], int V, int E) {
    // Array to store the resulting MST
    struct Edge result[V];

    // Sort the edges in non-decreasing order of their weight
    // (you can use any sorting algorithm here)
    // ...

    // Allocate memory for creating V subsets
    struct Subset subsets[V];

    // Initialize subsets with single elements
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Index variable for result[]
    int i = 0, j = 0;

    // Number of edges to be taken is equal to V-1
    while (i < V - 1 && j < E) {
        // Pick the smallest edge
        struct Edge nextEdge = edges[j++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If including this edge doesn't cause a cycle, add it to the result
        if (x != y) {
            result[i++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    // Print the resulting MST
    printf("Minimum Spanning Tree:\n");
    for (int i = 0; i < V - 1; i++) {
        printf("%d -- %d\tWeight: %d\n", result[i].src, result[i].dest, result[i].weight);
    }
}