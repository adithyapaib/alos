#include <queue>
#include <iostream>

using namespace std;

int graph[100][100]={0};
bool visited[100] = {false};

void bfs(int n, int startVertex) {

  queue<int> q;
  visited[startVertex] = true;
  q.push(startVertex);

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    
    cout << node << " "; 

    for (int i = 0; i < n; i++) 
      if (graph[node][i] && !visited[i]) {
        visited[i] = true;
        q.push(i);
      }
    
  }
}

int main() {
  int n; 
  cout << "Enter the number of vertices: ";
  cin >> n;

  cout << "Enter the adjacency matrix: " << endl;
  for (int i = 0; i < n; i++) {
      int u, v;
      cin>>u>>v;
      graph[u][v] = 1;
      graph[v][u] = 1;
    
  }

  int startVertex;
  cout << "Enter the starting vertex: ";
  cin >> startVertex;

  cout << "BFS Traversal: ";
  bfs(n, startVertex);

  return 0;
}
