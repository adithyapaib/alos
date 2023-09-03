#include <bits/stdc++.h>
using namespace std;

void insertion(int arr[], int n){
    for(int i = 0,j=0;i<n;i++,j=i)
        while(j>0 && arr[j-1] > arr[j])
               swap(arr[j],arr[j--]);

    for(int i = 0;i<n;i++)
        cout<<arr[i]<<endl;
}

int main()
{
	int arr[] = { 1,2,3,4,5,604, 34, 25, 12, 22, 11, 90 };
	int N = sizeof(arr) / sizeof(arr[0]);
	insertion(arr, N);
	return 0;
}