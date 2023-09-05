#include <iostream>
#include <climits>

using namespace std;

#define V 5
bool visited [10] = {false};

void printMST(int parent[], int graph[V][V])
{
    cout<<"Minimum spanning tree"<<endl;
    cout<<endl;
    for(int i =1; i<V;i++){
        cout<<parent[i]<<", "<<i<<"     "<<graph[i][parent[i]]<<endl;
    }
    
}



int minKey(int key[])
{
    int min = INT_MAX, mindex;
    for(int i =0; i<V;i++)
        if(!visited[i] && key[i] < min)
            min = key[i], mindex = i;
    
    return mindex;
}




void primMST(int graph[V][V])
{
    int parent[10], key[10];
    for(int i = 0; i < V;i++)
        key[i] = INT_MAX, visited[i] = false;
    key[0] = 0;
    parent[0] = -1;
    
    for(int count = 0 ; count < V-1; count++){
        int u = minKey(key);
        visited[u] = true;
        for(int v = 0; v<V;v++){
            if(graph[u][v] && !visited[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
        }
    }
    printMST(parent,graph);
    
}

int main()
{
    int graph[V][V] =  { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    primMST(graph);

    return 0;
}
