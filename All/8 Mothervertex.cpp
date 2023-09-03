#include <iostream>

using namespace std;

bool visited[100] = {false};
int numNodes, numEdges;
int graph[10][10] = {0};

void dfs(int start) {
    int stack[100], top = -1;
    stack[++top] = start;
    visited[start] = true;

    while (top >= 0) {
        int node = stack[top--];
    //cout << node << " ";

        for (int i = 0; i < numNodes; i++) {
            if (graph[node][i] && !visited[i]) {
                stack[++top] = i;
                visited[i] = true;
            }
        }
    }
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
    numNodes = 5;
    numEdges = 3;

    graph[4][1] = 1;
    graph[4][2] = 1;
    graph[4][3] = 1;
    graph[4][0] = 1;


    int motherVertex = findMotherVertex();

    if (motherVertex != -1) {
        cout << "A mother vertex is " << motherVertex << endl;
    } else {
        cout << "No mother vertex exists" << endl;
    }

    return 0;
}
