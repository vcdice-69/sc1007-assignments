#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int V; // number of regions
int count = 0;

/* A utility function to check if
   the current color assignment
   is safe for vertex v i.e. checks
   whether the edge exists or not
   (i.e, graph[v][i]==1). If exist
   then checks whether the color to
   be filled in the new vertex(c is
   sent in the parameter) is already
   used by its adjacent
   vertices(i-->adj vertices) or
   not (i.e, color[i]==c) */
int isSafe(int v, int** graph, int* color, int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return 0;
    return 1;
}

/* A backtracking function
to solve m coloring problem */
int graphColoring(int** graph, int m, int* color, int v)
{
    //BASE CASE
    if (v == V) {//If all vertices are assigned a color, then increment count
        count++;
        return count;
    }


    //RECURSIVE STEP
    for (int c = 1; c <= m; c++) {// Try different colors c for current vertex v

        if (isSafe(v, graph, color, c)){// Check if assigning color c to v is valid

            color[v] = c; // Assign color c to v
            graphColoring(graph, m, color, v + 1);// Recur for next vertex
            color[v] = 0;// Backtrack by resetting the color of current vertex v

        }
    }

    // Return the count of solutions
    return count;
}

int main()
{
    int m;
    int **graph;
    int *color;

    printf("Enter number of colors:\n");
    scanf("%d", &m);

    printf("Enter number of regions:\n");
    scanf("%d", &V);

    int i, j;
    color = (int *)malloc(V * sizeof(int));
    graph = (int **)malloc(V * sizeof(int *));

    for (i = 0; i < V; i++)
        graph[i] = (int *)malloc(V * sizeof(int));

    printf("Input the adjacency matrix:\n");
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    // Initialize all color values as 0.
    for (i = 0; i < V; i++)
        color[i] = 0;

    int numSolutions = graphColoring(graph, m, color, 0);
    printf("There is/are total %d solution(s)\n", numSolutions);

    // Free dynamically allocated memory
    free(color);
    for (i = 0; i < V; i++)
        free(graph[i]);
    free(graph);

    return 0;
}
