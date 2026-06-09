#include <bits/stdc++.h>
using namespace std;
// Brute-Force. T.C -> O(n*logn) ,S.C -> O(n).
// Using Merge-Sort.
// void merge(int arr[], int low, int mid, int high)
// {
//     int i = low;
//     int j = mid + 1;
//     int k = low;
//     int temp[high + 1];
//     while(i <= mid && j <= high)
//     {
//         if(arr[i] <= arr[j]){
//             temp[k] = arr[i];
//             k++;i++;
//         }
//         else{
//             temp[k] = arr[j];
//             k++;j++;
//         }
//     }
//     while(i <= mid){
//         temp[k] = arr[i];
//         k++;i++;
//     }
//     while(j <= high){
//         temp[k] = arr[j];
//         k++;j++;
//     }
//     for(int i = low; i <= high; i++)
//         arr[i] = temp[i];
// }
// void mergeSort(int arr[],int low,int high){
//     if(low<high){
//         int mid = (low+high)/2;
//         mergeSort(arr,low,mid);
//         mergeSort(arr,mid+1,high);
//         merge(arr,low,mid,high);
//     }
// }

// Better-Force. T.C -> O(2n) ,S.C -> O(1).
// void sort_Array(int arr[], int n)
// {
//     int count = 0, count1 = 0, count2 = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == 0)
//         {
//             count += 1;
//         }
//         else if (arr[i] == 1)
//         {
//             count1 += 1;
//         }
//         else
//         {
//             count2 += 1;
//         }
//     }
//     for (int i = 0; i < count; i++)
//     {
//         arr[i] = 0;
//     }
//     for (int i = count; i < count+count1; i++)
//     {
//         arr[i] = 1;
//     }
//     for (int i = count+count1; i < n; i++)
//     {
//         arr[i] = 2;
//     }
// }

// Optimal .T.C -> O(n) ,S.C -> O(1).
// Dutch National Flag Algorithm.
void sort_Array(int arr[],int n){
    int low = 0,mid = 0,high = n-1;
    for (int i = 0; i < n; i++)
    {
        while(mid <= high){
            if(arr[mid] == 0) {
                swap(arr[low],arr[mid]);
                low++;mid++;
            }else if(arr[mid] == 1){
                mid++;
            }else{
                swap(arr[mid],arr[high]);
                high--;
            }
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // Brute- Force.Using sorting Alogorithm.
    // mergeSort(arr,0,n-1);
    sort_Array(arr, n);
    printArray(arr, n);
    return 0;
}