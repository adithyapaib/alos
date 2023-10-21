#include <iostream>

using namespace std;

// Function to find the maximum and minimum of an array
void findMaxMin(int arr[], int low, int high, int& max, int& min) {
    // Base case: If the array contains only one element
    if (low == high) {
        max = arr[low];
        min = arr[low];
        return;
    }

    // Base case: If the array contains two elements
    if (high - low == 1) {
        if (arr[low] < arr[high]) {
            max = arr[high];
            min = arr[low];
        } else {
            max = arr[low];
            min = arr[high];
        }
        return;
    }

    // Divide the array into two halves
    int mid = (low + high) / 2, max1, min1, max2, min2;
    findMaxMin(arr, low, mid, max1, min1);
    findMaxMin(arr, mid + 1, high, max2, min2);

    max = (max1>max2)? max1 : max2;
    min = (min1 < min2)? min1 : min2;
}

int main() {
    int arr[100], max,min,n;
    cout<<"Enter the no of elements : ";
    cin>>n;
    cout<<"Enter the elements :";
    for(int i = 0; i<n;i++)
        cin>>arr[i];
    findMaxMin(arr, 0, n - 1, max, min);

    cout << "Maximum: " << max;
    cout <<endl<< "Minimum: " << min;

    return 0;
}