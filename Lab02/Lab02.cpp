


/*
 *
 *
 * Code By Adithya Pai B
 * MTech CNE
 *
 *
 *
*/




#include <iostream>
using namespace std;

bool printDfs = true;
bool hasPath(int ** vertArr, int v, int start, int end, bool * visited);
bool hasCycle(int ** vertArr, int v, int start, int parent, bool * visited);




void displayMatrix(int ** vertArr, int v) {
    cout << "Adjacency  Matrix" << endl;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++)
            cout << vertArr[i][j] << " ";
        cout << endl;
    }
}


void add_edge(int ** vertArr, int u, int v, int size) {
    if (u >= 0 && u < size && v >= 0 && v < size) {
        vertArr[u][v] = 1;
        vertArr[v][u] = 1;
    } else
        cout << "Invalid vertices" << endl;
}

void dfs(int ** vertArr, int v, int vertex, bool * visited) {
    visited[vertex] = true;
    if (printDfs)
        cout << vertex << " ";

    for (int i = 0; i < v; i++) {
        if (vertArr[vertex][i] == 1 && !visited[i])
            dfs(vertArr, v, i, visited);
    }
}

void bfs(int ** vertArr, int v, int startVertex, bool * visited) {
    int * queue = new int[v];
    int front = 0;
    int rear = 0;

    queue[rear++] = startVertex;
    visited[startVertex] = true;

    cout << endl << "BFS traversal: ";

    while (front != rear) {
        int vertex = queue[front++];
        cout << vertex << " ";

        for (int i = 0; i < v; i++) {
            if (vertArr[vertex][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }

    cout << endl;

    delete[] queue;
}

void clearVoid(bool * visited, int v) {
    for (int i = 0; i < v; i++)
        visited[i] = false;
}

int findMotherVertex(int ** adjList, int v) {
    bool * visited = new bool[v];

    for (int i = 0; i < v; i++)
        visited[i] = false;

    int lastVisitedVertex = 0;

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(adjList, v, i, visited);
            lastVisitedVertex = i;
        }
    }

    for (int i = 0; i < v; i++)
        visited[i] = false;

    dfs(adjList, v, lastVisitedVertex, visited);

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            delete[] visited;
            return -1;
        }
    }

    delete[] visited;
    return lastVisitedVertex;
}

// Transpose of Graph
void transposeGraph(int ** graph, int v) {
    int ** transpose = new int * [v];
    for (int i = 0; i < v; i++) {
        transpose[i] = new int[v];
        for (int j = 0; j < v; j++) {
            transpose[i][j] = graph[j][i];
        }
    }
    cout << "Transpose of the graph:" << endl << endl;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
}

bool hasPath(int ** vertArr, int v, int start, int end, bool * visited) {
    visited[start] = true;

    if (start == end) {
        visited[start] = false; // Reset visited array for future use
        return true;
    }

    for (int i = 0; i < v; i++) {
        if (vertArr[start][i] == 1 && !visited[i]) {
            if (hasPath(vertArr, v, i, end, visited)) {
                visited[start] = false; // Reset visited array for future use
                return true;
            }
        }
    }

    visited[start] = false; // Reset visited array for future use
    return false;
}

bool hasCycle(int ** vertArr, int v, int start, int parent, bool * visited) {
    visited[start] = true;

    for (int i = 0; i < v; i++) {
        if (vertArr[start][i] == 1) {
            if (!visited[i]) {
                if (hasCycle(vertArr, v, i, start, visited)) {
                    return true;
                }
            } else if (i != parent) {
                return true;
            }
        }
    }

    return false;
}

bool isConnected(int ** vertArr, int v) {
    bool * visited = new bool[v];
    clearVoid(visited, v);

    dfs(vertArr, v, 0, visited);

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            delete[] visited;
            return false;
        }
    }

    delete[] visited;
    return true;
}

// Main Code
int main(int argc, char * argv[]) {
    int v = 6;
    int ** vertArr = new int * [v];
    for (int i = 0; i < v; i++) {
        vertArr[i] = new int[v];
        for (int j = 0; j < v; j++)
            vertArr[i][j] = 0;
    }

    add_edge(vertArr, 0, 4, v);
    add_edge(vertArr, 0, 3, v);
    add_edge(vertArr, 1, 2, v);
    add_edge(vertArr, 1, 4, v);
    add_edge(vertArr, 1, 5, v);
    add_edge(vertArr, 2, 3, v);
    add_edge(vertArr, 2, 5, v);
    add_edge(vertArr, 5, 3, v);
    add_edge(vertArr, 5, 4, v);

    displayMatrix(vertArr, v);

    bool * visited = new bool[v];
    clearVoid(visited, v);

    cout << endl << "DFS traversal: ";
    dfs(vertArr, v, 0, visited);
    clearVoid(visited, v);

    bfs(vertArr, v, 0, visited);
    cout << endl;

    // Mother vertex
    printDfs = false;

    int motherVertex = findMotherVertex(vertArr, v);

    if (motherVertex != -1)
        cout << endl << "The mother vertex is: " << motherVertex << endl;
    else {
        cout << endl << "There is no mother vertex in the graph." << endl;
    }

    // Transpose of Graph

    transposeGraph(vertArr, v);

    visited = new bool[v];
    clearVoid(visited, v);

    // Find a path
    cout << endl << "Has Path from 0 to 5: " << (hasPath(vertArr, v, 0, 5, visited) ? "Yes" : "No") << endl;

    // Find a cycle
    cout << "Has Cycle in the graph: " << (hasCycle(vertArr, v, 0, -1, visited) ? "Yes" : "No") << endl;

    // Reset visited array for future use
    clearVoid(visited, v);

    visited = new bool[v];
    clearVoid(visited, v);

    // Check if the graph is connected
    cout << "Is the graph connected? " << (isConnected(vertArr, v) ? "Yes" : "No") << endl;

    clearVoid(visited, v);

    return 0;
}
