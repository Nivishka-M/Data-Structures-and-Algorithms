#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 6

//a utility function to Pick the minimum key vertex 
//if the vertex is not yet included in MST
int minKey(int keyVals[], bool mstset[])
{
	// initializing min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++){
		if (mstset[v] == false && keyVals[v] < min){
			min = keyVals[v];
			min_index = v;}
	}
	return min_index;
}

void printMST(int parent[], int graph[V][V])
{	int cost =0;
	cout << "Edge \t :\tWeight\n";
	for (int i = 1; i < V; i++){
		int weight = graph[i][parent[i]];
		cout << parent[i] << " - " << i << " \t : \t" << weight << " \n";
		cost = cost + weight;
		}
	cout << "The cost of MST is : " << cost;
}

void prims(int graph[V][V])
{
	int parent[V];	//an array to store the parent of each vertex
	int keyVals[V];	//to keep track of the minimum costs of vertices 
				//by storing and updating key-values of each node
	bool mstSet[V];

	// initializing all key values as INFINITE and all elements are not in mst
	for (int i = 0; i < V; i++){
		keyVals[i] = INT_MAX;
		mstSet[i] = false;
		}

	keyVals[0] = 0;		//taking 0 as the first vertex
	parent[0] = -1;

	for (int count = 0; count < V - 1; count++) {
		int u = minKey(keyVals, mstSet);	//getting the minimum key vertex which is not included in mst already
		mstSet[u] = true;

		for (int v = 0; v < V; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < keyVals[v]){
				parent[v] = u, 
				keyVals[v] = graph[u][v];
				}
	}
	// Print the constructed MST
	printMST(parent, graph);
}

int main()
{
	int graph[V][V] = { { 0, 3, 0, 0, 0, 1 },
			{ 3, 0, 2, 1, 10, 0 },
			{ 0, 2, 0, 3, 0, 5 },
			{ 0, 1, 3, 0, 5, 0 },
			{ 0, 10, 0, 5, 0, 4 },
                        { 1, 0, 5, 0, 4, 0 } };

	// Print the solution
	prims(graph);

	return 0;
}
