// Determine the number of connected components in a undirected graph in O(n) using adjacency matrix.
// A connected component is a subgraph where two or more vertices are connected via one or more edges.
// For more information: https://www.baeldung.com/cs/graph-connected-components
// or https://en.wikipedia.org/wiki/Component_(graph_theory)
//
// Code must run in O(n)

#include <iostream>

using namespace std;

const int N = 6;

int numConnectedComponents(int A[][N]);
void DFS(int A[][N], bool visited[], int v);

int main() {
    int A[N][N] = { {0, 0, 1, 0, 0, 0}, 
                    {0, 0, 0, 0, 0, 1}, 
                    {1, 0, 0, 0, 1, 0}, 
                    {0, 0, 0, 0, 0, 0}, 
                    {0, 0, 1, 0, 0, 0}, 
                    {0, 1, 0, 0, 0, 0} };

    cout << numConnectedComponents(A) << endl; // Should output 3
}

// returns number of connected components
int numConnectedComponents(int A[][N]) { 
    bool visited[N];    // empty vertices as none are visited 
    int count = 0;      // number of connected components 

    for (int v = 0; v < N; v++) { 
        visited[v] = 0; // initialize false 
    }
        for (int v = 0; v < N; v++) { 
            if (visited[v] == false) { 
                DFS(A, visited, v); 
                count += 1; 
            }
        } 
    

    return count; 
}

// runs DFS on a graph represented as an adjacency matrix
void DFS(int A[][N], bool visited[], int v) {

    visited[v] = 1;      // true, vertex vistied
  
    // recursive back for all the vertices adjacent to this vertex
    for (int i = 0; i < N; i++) { 
        if(A[v][i] == 1 && visited[i] == 0) { // edge detection and it is not visted
                DFS(A, visited, i); //  recursive call
        }
    }
}