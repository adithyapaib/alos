#include <bits/stdc++.h>
using namespace std;

void selection(int arr[], int n){
    for(int i = 0;i<n;i++)
        for(int j =0; j<i;j++)   
               swap((arr[i] < arr[j])? arr[j]:arr[i], arr[i]);
}


void printArray(int arr[], int size){
     for(int i = 0;i<size;i++)
        cout<<arr[i]<<endl;
}

int main()
{
	int arr[] = { 604, 34, 25, 12, 22, 11, 90 };
	int N = sizeof(arr) / sizeof(arr[0]);
	selection(arr, N);
	cout << "Sorted array: \n";
	printArray(arr, N);
	return 0;
}