#include <iostream>
using namespace std;

bool visited[100] = {false};
bool hasCycle = false;
int graph[10][10] = {0};
int numNodes, numEdges; 
int path[10], pathIndex = 0;




void dfs(int node, int parent) {

  visited[node] = true;
  path[pathIndex++] = node;

  for(int i = 0; i < numNodes; i++) {
    if(graph[node][i] == 1 && !visited[i]) {
      dfs(i, node); 
      return;
    }
    else if(graph[node][i] == 1 && i != parent) {
     hasCycle = true;
     cout << "Cycle: ";
    for (int i = 0; i < pathIndex; i++) 
        cout << path[i] << "-> ";
      return;
    }
  }
  pathIndex--;
}

int main() {

  cout << "Enter number of nodes and edges: ";
  cin >> numNodes >> numEdges;

  cout << "Enter edges:\n";
  for(int i = 0; i < numEdges; i++) {
    int u, v;
    cin >> u >> v;
    graph[u][v] = 1;
    graph[v][u] = 1;
  }

  
  for(int i = 0; i < numNodes; i++) {
    if(!visited[i])
      dfs(i, -1); 
  }

  if(hasCycle) 
    cout << "Graph contains cycle";
  else
    cout << "Graph doesn't contain cycle";

  return 0;
}
