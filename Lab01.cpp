

/*
 *
 *
 * Code By Adithya Pai B
 * MTech CNE
 *
 *
 *
*/

#include <iostream>
#include <bits/stdc++.h>
#define ARR_SIZE 10
#include <ctime>
using namespace std;


void displayArray(int array[],int n, string title,int c=0){
cout<<"--------------";
cout<<endl<<title<<endl;
cout<<"--------------"<<endl;
 for(int i = 0;i<n;i++)
    cout<<array[i]<<" ";

if(c!=0)
    cout<<endl<<"Steps Counted: "<<c;
cout<<endl<<endl;
}




void bubbleSort(int arr[],int n )
{
    int c =1;
	for (int i = n - 1; i > 0; i--)
	{
	    c+=1;
		for (int j = 0; j <= i; j++)
		{
		    c+=2;
			if (arr[j] > arr[j + 1])
			{
			    c+=1;
                swap(arr[j],arr[j+1]);
			}
		}
	}
displayArray(arr,n,"Bubble Sort",c);
}


void selectionSort(int arr[], int n) {
int c = 1;
  for (int i = 0; i < n - 1; i++) {
    int mini = i;
    c+=2;
    for (int j = i + 1; j < n; j++) {
      c+=2;
      if (arr[j] < arr[mini]) {
        c+=1;
        mini = j;
      }
    }
    int temp = arr[mini];
    arr[mini] = arr[i];
    arr[i] = temp;
    c+=3;
  }
  displayArray(arr,n,"Selection Sort",c);
}


void insertionSort(int arr[],int n){
    cout<<endl<<endl;
    int c =1;
for (int i = 0; i <= n - 1; i++) {
        int j = i;
        c+=2;
        while (j > 0 && arr[j - 1] > arr[j]) {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
            c+=5;
        }
}
displayArray(arr,n,"Insertion Sort",c);
}

void binarySearch(int arr[], int n){
int l = 0, r = n-1,x,c=1;
cout<<endl<<"Binary Search"<<endl<<"Enter a key to search :";
cin>>x;
 while (l <= r) {
        c+=2;
        int m = l + (r - l) / 2;
        if (arr[m] == x){
            c+=2;

            cout<<"The Element found at "<<m;
            cout<<endl<<"Steps Counted: "<<c;
            return;
        }
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    c+=1;
    }
cout<<endl<<"Key Not found :/";
cout<<endl<<"Steps Counted: "<<c;


}


void randomizeArray(int arr[],int n ){

for(int i=0;i<n;i++)
      arr[i]=rand() % time(0)%500;

}



int main(){

//= { 10, 55, 2, 66, 8, 545, 1, 0, 96, 4 }
	int arr[ARR_SIZE] , n = ARR_SIZE;
	randomizeArray(arr,n);
	displayArray(arr,n,"Before Sort",0);

	// Bubble Sort
    bubbleSort(arr,n);

    // Binary Search

    binarySearch(arr,n);

    // Insertion Sort

    randomizeArray(arr,n);
    insertionSort(arr,n);

    // Selection Sort
    randomizeArray(arr,n);
    selectionSort(arr,n);


	return 0;

}
