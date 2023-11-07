// Dijkstra's FindShortestPath Algorithm Implementation in Adjacency Matrix Format

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <stdio.h>

#define V 9

int minDistance(int dist[], bool isShortest[])
{
	int min = INT_MAX; //at first infinity
	int min_index; // since it is adjacency matrix, we have indexes.

	for (int v = 0; v < V; v++){
		if (isShortest[v] == false && dist[v] <= min){
			min = dist[v];
			min_index = v;
		}
	}
	return min_index;
}

void printSolution(int dist[])
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t\t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V]; // dist[i] will hold the shortest distance from src to i

	bool isShortest[V]; // isShortest[i] will be true if vertex i is
					// included in shortest path (A.K.A PAINTED TO RED)
                                    
	for (int i = 0; i < V; i++){
		dist[i] = INT_MAX; // All distances are inf. (not pratically)
		isShortest[i] = false; // No vertex included at first
	}
	dist[src] = 0; // Distance of source vertex from itself is always 0

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum distance vertex from the set of
		// vertices not yet processed. u is always equal to
		// src in the first iteration.
		int u = minDistance(dist, isShortest);

		// Mark the picked vertex as processed
		isShortest[u] = true;

		// Update dist value of the adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < V; v++){

			// Update dist[v] only if is not in isShortest,
			// there is an edge from u to v, and total
			// weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!isShortest[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
		}
	}

	printSolution(dist);
}


int main(int argc, char *argv[])
{ 
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 0, 6 },
						{ 8, 11, 0, 0, 0, 0, 0, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

						//    A  B  C  D  E  F  G  H  I
						// A  0  4  0  0  0  0  0  8  0
						// B  4  0  8  0  0  0  0 11  0
						// C  0  8  0  7  0  4  0  0  2
						// D  0  0  7  0  9 14  0  0  0
						// E  0  0  0  9  0 10  0  0  0
						// F  0  0  4 14 10  0  2  0  0
						// G  0  0  0  0  0  2  0  0  6
						// H  8 11  0  0  0  0  0  0  7
						// I  0  0  2  0  0  0  6  7  0

	int src;
	if(argc == 2)
	{
		src = atoi(argv[1]);	
	}
	else
	{
		printf("One integer argument is expected for source vertex.\n");
		return 0;
	}

	dijkstra(graph, src);

	return 0;
}
