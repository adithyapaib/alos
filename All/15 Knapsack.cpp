#include <iostream>
using namespace std;

float rt[10];

int temp[10], xi[10] = {0}, val[10], wt[10];
int W,n;

void bubbleSort(float arr[], int n){
    for(int i = n-1;i>=0;i--)
        for(int j =0; j<i;j++)   
                swap((arr[j] <arr[j+1])? arr[j]: arr[j+1], arr[j+1]);
}
int findIndex(int p){
    for(int i = 0; i<n;i++)
        if(temp[i] == p){
              temp[i] = -999;
              return i;
        }
    return 0;
          
}

void kp(){
    int profit = 0;
    bubbleSort(rt,n);
    for(int i =0;i<n;i++){
        int p = rt[i];
        int index = findIndex(p);
        if(W-wt[index] >=0){
            W-=wt[index];
            profit+=val[index];
            xi[index] = 1;
        }
    }
    cout<<endl<<"Max profit "<<profit<<"XI values :";
    for(int i = 0;i<n;i++)
        cout<<" "<<xi[i];
    
    
}

int main() {
    cout<<"Enter the number of weights";
    cin>>n;
    cout<<"Enter the weights";
    for(int i =0;i<n;i++)
        cin>>wt[i];
    cout<<"Enter the profit";
    for(int i =0;i<n;i++)
        cin>>val[i];
    cout<<"Enter the max weight";
    cin>>W;
    for(int i = 0; i < 3; i++){
        rt[i] = val[i] / wt[i];
        temp[i] = rt[i];
    }
   kp();
    return 0;
}
