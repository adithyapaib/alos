#include <iostream>
using namespace std;

const int V = 5;
int graph[V][V] = {0};

bool hasCycleUtil(int v, bool visited[], bool recStack[]) {
    visited[v] = true;
    recStack[v] = true;

    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1) {
            if (!visited[i] && hasCycleUtil(i, visited, recStack))
                return true;
            else if (recStack[i])
                return true;
        }
    }

    recStack[v] = false;
    return false;
}

bool hasCycle() {
    bool visited[V] = {false};
    bool recStack[V] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (hasCycleUtil(i, visited, recStack))
                return true;
        }
    }

    return false;
}

int main() {
    graph[0][2] = 1;
    graph[0][3] = 1;
    graph[2][4] = 1;
    graph[3][2] = 1;
    graph[4][1] = 1;
    if (hasCycle())
        cout << "Graph contains a cycle." << endl;
    else
        cout << "Graph does not contain a cycle." << endl;

    return 0;
}
