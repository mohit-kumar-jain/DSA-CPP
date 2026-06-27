#include<bits/stdc++.h>    
using namespace std;
     
// Brute-Force. T.C -> O(n*n) ,S.C -> O(1).
// void twoSum(int arr[],int n,int k){
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             if (arr[i]+arr[j] == k)
//             {
//                 cout<<i<<","<<j<<endl;
//                 return;
//             }
//         }
//     }
//     cout<<"No";
// }

// Better-Force. T.C -> O(n) ,S.C -> O(1). 
// Using HASHMAP.
void twoSum(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++)
    {
        int rem = k - arr[i];
        if(mp.find(rem) != mp.end())
        {
            cout << mp[rem] << "," << i << endl;
            return;
        }
        mp[arr[i]] = i;
    }
    cout << "No";
}

// Optimal Method.T.C -> O(nlogn) ,S.C -> O(1). To return yes or no as answer.
// Using two pointers.
// void twoSum(vector<int> arr,int n,int k){
//     int left = 0, right = n-1;
//     sort(arr.begin(),arr.end());
//     while (left < right)
//     {
//         int sum = arr[left] + arr[right];
//         if (sum == k)
//         {
//             cout<<"Yes";
//             return;
//         }
//         if (sum < k) left++;
//         else right--;
//     }
//     cout<<"No";
// }

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    // vector<int> arr(n);
    // for(int i = 0; i < arr.size(); i++)
    //     cin>>arr[i];
    int k;
    cin>>k;
    twoSum(arr,n,k);
    return 0;
}