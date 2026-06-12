#include<bits/stdc++.h>
using namespace std;
           
// Brute-Force Method T.C -> O(n logn).  S.C -> O(n).

void merge(int arr[], int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int k = low;

    int temp[high + 1];

    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            k++;i++;
        }
        else{
            temp[k] = arr[j];
            k++;j++;
        }
    }

    while(i <= mid){
        temp[k] = arr[i];
        k++;i++;
    }

    while(j <= high){
        temp[k] = arr[j];
        k++;j++;
    }

    for(int i = low; i <= high; i++)
        arr[i] = temp[i];
    }
    
    void mergeSort(int arr[],int low,int high){
        if(low<high){
            int mid = (low+(high))/2;
            mergeSort(arr,low,mid);
            mergeSort(arr,mid+1,high);
            merge(arr,low,mid,high);
        }
}   


// Optimal Method T.C -> O(n).  S.C -> O(1).
void largestElement(int arr[],int n){
    int largest = 0;
    for (int i = 1; i < n; i++)
    {
        if(arr[i]>arr[largest]){
            largest = i;
        }
    }
    cout<<arr[largest];
}   

int main() {
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    // Brute-Force Method
    // mergeSort(arr,0,n-1);
    // cout<<arr[n-1]<<endl;
    largestElement(arr,n);
    return 0;
}