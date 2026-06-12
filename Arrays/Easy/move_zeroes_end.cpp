#include<iostream>
using namespace std;
// Brute - Force Method. Time Complexity -> O(n),Space complexity = O(n).
// void moveZeroes(int arr[], int n)
// {
//     int temp[n];
//     int j = 0;
//     for(int i = 0; i < n; i++)
//     {
//         if(arr[i] != 0)
//         {
//             temp[j] = arr[i];
//             j++;
//         }
//     }
//     for(int i = j; i < n; i++)
//     {
//         temp[i] = 0;
//     }
//     for(int i = 0; i < n; i++)
//     {
//         arr[i] = temp[i];
//     }
// }

// Optimal Method. Time Complexity -> O(n),Space complexity = O(1).
void moveZeroes(int arr[], int n)
{
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

void printArray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    moveZeroes(arr,n);
    printArray(arr,n);
    return 0;
}