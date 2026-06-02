#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
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

void printArray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    printArray(arr,n);
    return 0;
}