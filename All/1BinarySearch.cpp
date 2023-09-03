#include <iostream>


using namespace std;

int binarySearch(int arr[], int n, int key) {
    int f = 0, l = n - 1, m;
    while (l >= f) {
        m = (f + l) / 2;
        if (arr[m] == key)
            return m;
        else if (key > arr[m])
            f = m + 1;
        else
            l = m - 1;
    }
    cout<<"not found";
    return -1;
}

int binary(int arr[], int n, int key,int f,int l){
    if(f>l)
        return -1;
    int m = (f+l)/2,pos=-1;
    if(arr[m] == key)
        return m;
    else if(key>arr[m])
        pos = binary(arr,n,key,m+1,l);
    else
        pos = binary(arr,n,key,f,m-1);
    return pos;

}


int main() {
    cout<<"Enter the no of Elements :"<<endl;
    int n, arr[100], key;
    cin>>n;
    cout<<"Enter the elements :"<<endl;
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the key: ";
    cin>>key;
    
    int pos = binary(arr,n,key,0,n-1);
    cout<<"Pos of key is "<<pos;
    pos = binarySearch(arr,n,key);
    cout<<endl<<"Pos of key is "<<pos;
    

}