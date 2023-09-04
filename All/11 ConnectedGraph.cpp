#include <iostream>

using namespace std;

int numNodes, numEdges;
int graph[10][10] = {0};
bool visited[100] = {false};

void dfs(int start) {
    int stack[100], top = -1;

    stack[++top] = start;
    visited[start] = true;

    while(top >= 0) {
        int node = stack[top--];

        for(int i = 0; i < numNodes; i++) {
            if(graph[node][i] && !visited[i]) {
                stack[++top] = i;
                visited[i] = true;
            }
        }
    }
}

bool isConnected() {
    for(int i = 0; i < numNodes; i++)
        if(!visited[i]){
            cout<<i;
            return false;
        }
              
    return true;
}

int main() {
    int start;

    cout << "Enter the number of nodes and edges: ";
    cin >> numNodes >> numEdges;

    cout << "Enter the edges: ";
    for(int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "Enter the starting node: ";
    cin >> start;

    dfs(start);

    if(isConnected())
        cout << endl << "The graph is connected";
    else
        cout << endl << "The graph is not connected";

    return 0;
}
