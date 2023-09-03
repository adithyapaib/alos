#include <iostream>

using namespace std;

int V = 5;
int graph[10][10] = {0};
int trans[10][10] = {0};


void printGraph(int g[10][10]){
    for (int i = 0; i < V; i++){
        cout << i << " : ";
        for (int j = 0; j < V; j++){
            if (g[i][j] == 1)
                cout << j << " ";
        }
        cout << endl;
    }
}

void transpose(){
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            if (graph[i][j] == 1)
                trans[j][i] = 1;
        }
    }
}
    
    
    
int main()
{
   

    graph[0][2] = 1;
    graph[0][3] = 1;
    graph[2][4] = 1;
    graph[3][2] = 1;
    graph[4][1] = 1;

    cout << "Original Graph" << endl;
    printGraph(graph);
    transpose();
    cout << "Transpose Graph" << endl;
    printGraph(trans);
   

    return 0;
}
