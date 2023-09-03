#include <iostream>

using namespace std;

bool visited[100] = {false};
int numNodes,numEdges;
int graph[10][10] = {0};

void dfs(int start) {
    
    int stack[100],top = -1;
    stack[++top] = start;
    visited[start] = true;

    while (top >= 0) {
        int node = stack[top--];
        cout << node << " ";

        for (int i = 0; i < numNodes; i++) {
            if (graph[node][i] && !visited[i]) {
                stack[++top] = i;
                visited[i] = true;
            }
        }
    }
}

int main() {
    int start;
    cout<<"Enter the number of nodes and Edges";
    cin >> numNodes >> numEdges;

    cout<<"Enter the edges";
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    cout<<"Enter the start Node";
    cin >> start;
    dfs(start);

    return 0;
}
