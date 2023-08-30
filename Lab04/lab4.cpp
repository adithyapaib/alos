#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;




void containerLoading() {
    int xi[100],weight[100], c, n;

    cout << "\nEnter the number of items: ";
    cin >> n;
    cout << "\nEnter the capacity: ";
    cin >> c;

    cout << "\nEnter the weights: ";
    for (int i = 0; i < n; i++)
        cin >> weight[i];


    vector<int> xiMatrix;
    for (int i = 0; i < n; i++) {
        if (weight[i] <= c ) {
            xiMatrix.push_back(1);
            c -= weight[i];
        } else {
            xiMatrix.push_back(0);
        }
    }

    cout << "xi matrix: ";
    for (int i = 0; i < xiMatrix.size(); i++)
        cout << xiMatrix[i] << " ";

}


void knapsackProblem(){


}


void topologicalSort() {
    int n, a[100][100],i, j, k, indeg[10], flag[10], count = 0;
    cout<<"Enter the number of vertices: \n";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"\nEnter the vertices for "<<i+1<<" node : \n";
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
    for (i = 0; i < n; i++) {
        indeg[i] = 0;
        flag[i] = 0;
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            indeg[i] = indeg[i] + a[j][i];
    system("cls");
    cout << "The topological order is: ";
    while (count < n) {
        for (k = 0; k < n; k++) {
            if (indeg[k] == 0 && flag[k] == 0) {
                cout << k + 1 << " ";
                flag[k] = 1;

                for (j = 0; j < n; j++) {
                    if (a[k][j] == 1)
                        indeg[j]--;
                }
            }
        }
        count++;
    }
}



int main()
{

    while(1==1){

        cout<<"\n\n Enter an option: \n";
        cout<<"\n1) Container loading ";
        cout<<"\n2) 0/1 Knapsack Problem ";
        cout<<"\n3) Topological sorting";
        cout<<"\n4) exit";
        int choice;
        cin>>choice;
        system("cls");

         switch (choice) {
            case 1:
                containerLoading();
                break;
            case 2:
                knapsackProblem();
                break;
            case 3:
                topologicalSort();
                break;
            case 4:
                return 0; // Exit the program
            default:
                cout << "Invalid option. Please try again.\n";
        }


    }
    return 0;
}
