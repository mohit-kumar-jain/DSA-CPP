#include<bits/stdc++.h>
using namespace std;
// Brute -Force Method.Time Complexity -> O(n), Space Complexity -> O(k).
void leftRotate_K(int arr[], int n, int k)
{
    k = k % n;
    int temp[k];
    for(int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }
    for(int i = k; i < n; i++)
    {
        arr[i - k] = arr[i];
    }
    for(int i = 0; i < k; i++)
    {
        arr[n - k + i] = temp[i];
    }
}

// Brute -Force Method.Time Complexity -> O(n), Space Complexity -> O(k).
void rightRotate_K(int arr[], int n, int k)
{
    k = k % n;
    int temp[k];
    // step 1: store last k elements
    for(int i = 0; i < k; i++)
    {
        temp[i] = arr[n - k + i];
    }
    // step 2: shift remaining elements to right
    for(int i = n-k-1; i >= 0; i--)
    {
        arr[i + k] = arr[i];
    }
    // step 3: copy temp to front
    for(int i = 0; i < k; i++)
    {
        arr[i] = temp[i];
    }
}

// Optimal Method.Time Complexity -> O(n), Space Complexity -> O(1).
// void rightRotate_K(int arr[],int n,int k)
// {
//     k = k%n;
//     reverse(arr,arr+n);
//     reverse(arr,arr+k);
//     reverse(arr+k,arr+n);
    
// }

// void leftRotate_K(int arr[],int n,int k)
// {
//     k = k % n;
//     reverse(arr,arr+k);
//     reverse(arr+k,arr+n);
//     reverse(arr,arr+n);
    
// }

void printArray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin>>k;
    rightRotate_K(arr,n,k);
    printArray(arr,n);
    return 0;
}