/* Graph read from file, and represnted as adjacency list. 
To implement DFS and BFS on the graph
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

// Each vertex has an integer id. 

typedef vector<vector<pair<int,int>>> adjlist; // Pair: (head vertex, edge weight)

adjlist makeGraph(ifstream& ifs);
void printGraph(const adjlist& alist);
vector<int> BFS(const adjlist& alist, int source); // Return vertices in BFS order
vector<int> DFS(const adjlist& alist, int source);  // Return vertices in DFS order
void DFSHelper(const adjlist& alist, vector<int>& dfslist, vector<bool>& visited, int source);
void printQ(queue<int> qcopy);






// DFS - returns list of nodes in DFS order starting from source vertex
vector<int> DFS(const adjlist& alist, int source) {
	
	// Initializing vectors
	vector<bool> vis(alist.size()); // visited vector
	vector<int> listDFS; // returning vector
	
	for (int i=0; i<alist.size(); i++) { // set all visit to false except source
        vis[i] = false;
	} 
	
    vis[source] = true;
	
	listDFS.push_back(source);	// Because source is visited, first entry to return is source
	DFSHelper(alist, listDFS, vis, source);	// Now we need the helper for the rest	
	return listDFS; // Return list of all nodes visited
	
}

void DFSHelper(const adjlist& alist, vector<int>& dfslist, vector<bool>& visited, int source) {
	for (auto& pair : alist[source]){ // adjacent nodes at node source
		auto vertex = pair.first;	// graph first adjacent node

		if (!visited[vertex]) { // Check if the node has been visited
			visited[vertex] = true;	// if not, mark as visited
			dfslist.push_back(vertex);	// push into visited vector
			
			// recursion function checking current vertex as source node and adj node
			DFSHelper(alist, dfslist, visited, vertex); 
		}
	}
}


// BFS - returns list of nodes in BFS order starting from source vertex
vector<int> BFS(const adjlist& alist, int source) {

	queue<int> queue; // start source in queue
	queue.push(source);
	
	// visited boolean matrix, source is first node visited
	vector<bool> vis(alist.size()); 
	for (int j=0; j<alist.size(); j++) { vis[j] = false; }
	vis[source] = true;
	
	vector<int> bfsList; // make a list for BFS to return later
	bfsList.push_back(source); // add the source value
	
	while (!queue.empty()){
		
        auto nodeOne = queue.front(); // Take first node, nodeOne
		queue.pop();			// pop the queue
		
        for (auto& pair : alist[nodeOne]){ // adjacent nodes at node nodeOne
			
            auto nodeAdj = pair.first;	// first adjacent node nodeAdj

 			if (!vis[nodeAdj]){
					vis[nodeAdj] = true;	// mark nodeAdj as visited
					queue.push(nodeAdj);		// put back into queue, important
					bfsList.push_back(nodeAdj);	// nodeAdj is visted now
			}
		}
	}
	
	return bfsList;
}





// Reads a csv graph from file and returns an adjacency list
adjlist makeGraph(ifstream& ifs) {
    int vh, vt, wt;
    string line;
    unordered_multimap<int, pair<int, int>> elist;
    set<int> vlist;
    
    while (getline(ifs, line)) {
        stringstream ss(line);
        ss >> vt;
        if (ss.peek() == ',')
            ss.ignore();
        ss >> vh;
        if (ss.peek() == ',')
            ss.ignore();
        ss >> wt;

        elist.emplace(vt, make_pair(vh, wt));   
        vlist.insert(vt);
        vlist.insert(vh);
    }
    
    adjlist res(vlist.size()); // Preallocate vector
    
    for (auto& ele : elist) {
        res.at(ele.first).push_back(make_pair(ele.second.first, ele.second.second));
    }
    return res;
}

// Prints the adjacency list (only vertices, not edge weights)
void printGraph(const adjlist& alist) {
    int i = 0;
    for (auto& nodeAdj : alist) {
        cout << i++ << ": ";
        for (auto& av : nodeAdj) {
            cout << av.first << " ";
        }
        cout << endl;
    }
}

// Prints queue for debugging
void printQ(queue<int> qcopy) {
    while (!qcopy.empty()) {
        cout << qcopy.front();
        qcopy.pop();
    }
    cout << endl;
}





