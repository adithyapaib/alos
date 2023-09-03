
#include <bits/stdc++.h>
using namespace std;


//Largest will goto end first
void bubbleSort(int arr[], int n){
    for(int i = n-1;i>=0;i--)
        for(int j =0; j<i;j++)   
                swap((arr[j] >arr[j+1])? arr[j]: arr[j+1], arr[j+1]);
}


void printArray(int arr[], int size){
     for(int i = 0;i<size;i++)
        cout<<arr[i]<<endl;
}

int main()
{
	int arr[] = { 604, 34, 25, 12, 22, 11, 90 };
	int N = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, N);
	cout << "Sorted array: \n";
	printArray(arr, N);
	return 0;
}

