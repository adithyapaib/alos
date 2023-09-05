#include <iostream>
#include <cstring>

using namespace std;



// Global variables
int n, m;
int graph[10][10];
bool visited[100]= {false};
int st[100], top = -1;

void dfs(int node) {
    visited[node] = true;

    for (int i = 1; i < n+1; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }

    st[++top] = node;
}


void topologicalSort() {
    top = -1;

    for (int i = 1; i < n+1; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    cout << "Topological sorting order: ";
    for (int i = top; i >= 0; i--) {
        cout << st[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    memset(graph, 0, sizeof(graph));

    cout << "Enter the edges:\n";
    for (int i = 1; i < m+1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
    }

    topologicalSort();
    
    return 0;
}
