#include <iostream>
using namespace std;

#define V 6
int parent[V];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j) {
    parent[find(i)] = find(j);
}


void kruskals(int cost[][V]) {
    int maxcost = 0, edge_count = 0;
    for (int i = 0; i < V; i++)
        parent[i] = i;

    cout << "Edges Selected and corresponding cost:" << endl;
    while (edge_count < V - 1) {
        int max = 9999,a= -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (find(i) != find(j) && cost[i][j] < max) {
                    max = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        union1(a, b);
        cout << "(" << a + 1 << "," << b + 1 << ")\t\t" << max << endl;
        edge_count++;
        maxcost += max;
    }
    cout << "Maximum cost = " << maxcost << endl;
}

int main() {
    int cost[V][V] = {
       { 9999, 6,1,5,9999,9999 },{ 6,9999,5, 9999, 3, 9999 },{ 1,5,9999, 5,6,4 },{ 5,9999, 5,9999,9999,2 },{ 9999, 3,6,9999,9999,6 },{ 9999, 9999, 4,2,6,9999 }};
    kruskals(cost);
    return 0;
}
