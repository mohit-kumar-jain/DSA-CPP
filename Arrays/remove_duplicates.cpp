#include<bits/stdc++.h>                   
using namespace std;
// Brute - Force Method. Time Complexity -> O(nlogn+n), Space Complexity -> O(n).
// void removeDuplicates(int arr[],int n){
//     set<int> st;
//     for (int i = 0; i < n; i++)
//     {
//         st.insert(arr[i]);
//     }
//     int index = 0;
//     for(auto it:st){
//        arr[index] = it;
//         index++;
//     }
//     cout<<index<<endl;
// }

// Optimal Method.Time Complexity -> O(n), Space Complexity -> O(1).
void removeDuplicates(int arr[],int n){
    if(n==0){
        cout<<0;
        return;
    }
    int i = 0;
    for(int j = 1;j<n;j++)
    {
        if (arr[j]!=arr[i])
        {
            i++;
            arr[i] = arr[j]; 
        } 
    }  
    cout<<i+1<<endl;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    removeDuplicates(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout <<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}