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
    }
    else if(graph[node][i] == 1 && i != parent) {
      hasCycle = true;
      cout << "Cycle: ";
      for (int j = 0; j < pathIndex; j++) {
        cout << path[j] << "-> ";
      }
      cout << path[i] << endl;
      exit(0);
    }
  }
  pathIndex--;
}

int main() {
  cout << "Enter number of nodes and edges: ";
  cin >> numNodes >> numEdges;

  cout << "Enter edges:" << endl;
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

  if(!hasCycle)
    cout << "Graph doesn't contain cycle" << endl;

  return 0;
}
