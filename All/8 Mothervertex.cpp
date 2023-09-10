#include <iostream>

using namespace std;

bool visited[100] = {false};
int numNodes, numEdges;
int graph[10][10] = {0};

void dfs(int start) {
    visited[start] = true;
        for (int i = 0; i < numNodes; i++) 
            if (graph[start][i] && !visited[i]) 
                dfs(i);
                
            
        
}

int findMotherVertex() {
int mother = -1;
for(int i = 0;i <numNodes; i++)
    if(!visited[i]){
        dfs(i);
        mother = i;
    }
for(int i = 0; i < numNodes;i ++)
    visited[i] = false;
dfs(mother);
for(int i = 0; i < numNodes;i ++)
    if(!visited[i])
        return -1;
return mother;
}


int main() {
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    int u, v;
    cout << "Enter the edges:\n";
    for (int i = 0; i < numEdges; i++) {
        cin >> u >> v;
        graph[u][v] = 1, graph[v][u] = 1;
    }

    int motherVertex = findMotherVertex();

    if (motherVertex != -1) 
        cout << "A mother vertex is " << motherVertex << endl;
    else 
        cout << "No mother vertex exists" << endl;
    

    return 0;
}
