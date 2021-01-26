// Q2: (45 pts)
// Find if the input undirected graph is connected (using adjacency matrix)
// Note: Your code should work for any undirected graph - not just this example
// Feel free to add additional functions as necessary
//
// What is the complexity of your solution?
//

#include <iostream>

using namespace std;

const int N = 8;

bool isConnected(int A[][N]);
void isConnectedHelper(int A[][N], int i, bool visited[][N]);


int main() {
  
    int adjmat[N][N] = { {0,1,0,0,1,0,0,0}, 
                         {1,0,0,1,0,0,0,0},
                         {0,0,0,0,1,0,1,0},
                         {0,1,0,0,0,0,0,1},
                         {1,0,1,0,0,0,1,0},
                         {0,0,0,0,0,0,0,0},
                         {0,0,1,0,1,0,0,0},
                         {0,0,0,1,0,0,0,0},};
                         
    if (isConnected(adjmat))
        cout << "Graph is connected" << endl;
    else 
        cout << "Graph is not connected" << endl;
}

void isConnectedHelper(int A[][N], int i, bool visited[][N]) {
    for (int j = 0; j < N; ++j) {
        if (A[i][j] == 1 && !visited[i][j]) {
            visited[i][j] = true;
            isConnectedHelper(A, j, visited);
        }
    }
}

bool isConnected(int A[][N]) {
    // Create the found matrix for out recursive search
    bool visited[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            visited[i][j] = false;
        }
    }
    
    // Find the first point so we can start the
    // connectivity search
    int i, j;
    bool found = false;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            if (A[i][j] == 1) {
                found = true;
                break;
            }
        }

        if (found) {
            break;
        }
    }
    
    // start visited recursive search
    isConnectedHelper(A, i, visited);

    // if any node is unvisited then the graph is unconnected
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (A[i][j] == 1 && !visited[i][j]) {
                return false;
            }
        }
    }

    return true;
}
