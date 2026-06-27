#include<bits/stdc++.h>
using namespace std;
// Brute - Force method. Time complexity -> O((m+n)logn(m+n)) , Space complexity -> O(m+n).
// Using set.
// void union_Arrays(int arr[],int arr2[],int m,int n){
//     set<int> st;
//     for (int i = 0; i < m; i++)
//     {
//         st.insert(arr[i]);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         st.insert(arr2[i]);
//     }
//     for(auto it:st){
//         cout<<it<<" ";
//     }
// }

// Better. Time complexity -> O((m+n)logn(m+n)) , Space complexity -> O(m+n).
// Using map
// void union_Arrays(int arr[],int arr2[],int m,int n){
//     vector<int> unioun;
//     map<int , int>Frequency;
//     for (int i = 0; i < m; i++)
//     {
//         Frequency[arr[i]]++;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         Frequency[arr2[i]]++;
//     }
//     for(auto it:Frequency){
//         unioun.push_back(it.first);
//     }
//     for(auto it:unioun){
//         cout<<it<<" ";
//     }
// }

// Optimal method. Time Complexity -> O(m+n), Space complexity -> O(m+n).
// Using Two - Pointer.
void union_Arrays(int arr[], int arr2[], int m, int n)
{
    int i = 0, j = 0, k = 0;
    int temp[m + n];

    while(i < m && j < n)
    {
        if(arr[i] < arr2[j])
        {
            if(k == 0 || temp[k-1] != arr[i])
                temp[k++] = arr[i];
            i++;
        }
        else if(arr[i] > arr2[j])
        {
            if(k == 0 || temp[k-1] != arr2[j])
                temp[k++] = arr2[j];
            j++;
        }
        else
        {
            if(k == 0 || temp[k-1] != arr[i])
                temp[k++] = arr[i];
            i++;
            j++;
        }
    }

    while(i < m)
    {
        if(k == 0 || temp[k-1] != arr[i])
            temp[k++] = arr[i];
        i++;
    }

    while(j < n)
    {
        if(k == 0 || temp[k-1] != arr2[j])
            temp[k++] = arr2[j];
        j++;
    }

    for(int x = 0; x < k; x++)
    {
        cout << temp[x] << " ";
    }
    cout << endl;
}

int main() {
    int m,n;
    cin >> m;
    cin >> n;
    int arr[m],arr2[n];
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    union_Arrays(arr,arr2,m,n);
    return 0;
}