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





or




#include <iostream>
#include <queue>

using namespace std;
int nodes, edges, graph[10][10] = {0};
bool visited[10] = {false};
queue <int> q;

void dfs(int start){
    visited[start] = true;
    cout<<start<<" ";
    for(int i = 0; i<nodes;i++)
        if(graph[start][i] ==1 && !visited[i])
            dfs(i);
}

void bfs(){
    if(q.empty())
        return;
    int item = q.front();
    q.pop();
    visited[item] = true;
    cout<<item<<" ";
    for(int i = 0; i<nodes; i++){
        if(graph[item][i] ==1 && !visited[i]){
            q.push(i);
            visited[i] = true;
        }
    }
    bfs();
    
}



int main() {
    cout << "Enter the number of nodes: ";
    cin >> nodes;
    cout << "Enter the number of edges: ";
    cin >> edges;


    cout << "Enter the edges:\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    int start;
    cout<<endl<<"Enter start node";
    cin>>start;

    //dfs(start);
    
    for(int i = 0;i<nodes;i++)
        visited[i] = false;
    
    
    
    q.push(start);
    bfs();
    
    return 0;
}
