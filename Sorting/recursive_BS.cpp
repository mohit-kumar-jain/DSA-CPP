#include<iostream>
           
using namespace std;

void recBubbleSort(int arr[],int n){
    if (n==1) return;
    
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i]>arr[i+1])
        {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    recBubbleSort(arr,n-1);
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
    recBubbleSort(arr,n);
    printArray(arr,n);
    return 0;
}