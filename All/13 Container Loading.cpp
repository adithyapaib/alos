#include <bits/stdc++.h>
using namespace std;

void sort(int arr[], int n = 8){
    for(int i = 0,j=0;i<n;i++,j=i)
        while(j>0 && arr[j-1] > arr[j])
               swap(arr[j],arr[j--]);
               
}

int findIndex(int w, int t[]){
    for(int i = 0; i <8;i++){
        if(w == t[i]){
            t[i] = 9999;
            return i;
        }
    }
    return 0;
}


int main()
{
    int capacity = 400;
    int n  = 8;
    int weight[] = {100,200,50,90,150,50,20,80};
    int temp[] = {100,200,50,90,150,50,20,80};
    int xi[8] = {0};
    
    sort(weight);
    for(int i = 0 ; i<8;i++){
        if(capacity-weight[i]>=0){
            capacity-=weight[i];
            int index = findIndex(weight[i], temp);
            xi[index] =1;
        }
    }
    cout<<"The xi graph is "<<endl;
    for(int i = 0;i<8;i++)
        cout<<xi[i];
    
    return 0;
}
