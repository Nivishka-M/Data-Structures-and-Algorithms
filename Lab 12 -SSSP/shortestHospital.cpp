#include <iostream>
#include <limits.h>
using namespace std;


// Number of cities which is defined for this senario
#define cities 6

//this function returns the index of the city with the minimum shortest time among the unvisited cities
int minTimed(int st_arr[], bool visited[])   // st_arr = shortest times array
{
	int min_index, min = INT_MAX ;  // Initialize min value as INT MAX
	for (int v = 0; v < cities; v++){
		if (visited[v] == false && st_arr[v] <= min){
			min = st_arr[v];
            min_index = v;
        }
    }
	return min_index;
}

void printSolution(int st_arr[],int source)
{   
    int sum = 0;
	for (int i = 0; i < cities; i++){
        if ( i != source){
		    cout << "Shortest time from source("<< source<<") to city "<<i<<  " is -> "<< st_arr[i] << endl;}
        sum = sum + st_arr[i];
    }
    
    cout << "\n" << "The total time for shortest path from source "<< source<<" => "<< sum;
}


void dijkstra(int graph[cities][cities], int src)   //src source city
{
	int shortest_times_arr[cities]; //from src city to i th city 
	bool visited[cities]; 

	// initializing all shortest times as INF and visited[] as false
	for (int i = 0; i < cities; i++){
		shortest_times_arr[i] = INT_MAX;
        visited[i] = false;
        }

	// time taken for source vertex from itself is 0
	shortest_times_arr[src] = 0;

	for (int count = 0; count < cities - 1; count++) {
		int u = minTimed(shortest_times_arr, visited);
        visited[u] = true;

		for (int v = 0; v < cities; v++)
			// Update vth of shortest_times_arr if v is not visited,
			if (!visited[v] && graph[u][v]
				&& shortest_times_arr[u] != INT_MAX
				&& shortest_times_arr[u] + graph[u][v] < shortest_times_arr[v])
				shortest_times_arr[v] = shortest_times_arr[u] + graph[u][v];
	}

	// print the constructed shortest_times_arr
	printSolution(shortest_times_arr , src);
}

// driver's code
int main()
{
    int const V = cities;
	int graph[V][V] = { { 0, 10, 0, 0, 15, 5},
						{ 10, 0, 10, 30, 0, 0},
						{ 0, 10, 0, 12, 5, 0},
						{ 0, 30, 12, 0, 0, 20},
						{ 15, 0, 5, 0, 0, 0},
						{ 5, 0, 0, 20, 0, 0}};

    int u = 5;  //u is the considering source
	dijkstra(graph, u);

	return 0;
}
