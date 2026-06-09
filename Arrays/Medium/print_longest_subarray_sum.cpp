#include <bits/stdc++.h>
using namespace std;

// Brute.T.C -> O(n*n) ,S.C -> O(1).
// void printMaxSubarrayBrute(int arr[], int n)
// {
//     int maxxi = INT_MIN;
//     int Arrstart = 0, Arrend = 0;
//     for(int i = 0; i < n; i++)
//     {
//         int sum = 0;
//         for(int j = i; j < n; j++)
//         {
//             sum += arr[j];
//             if(sum > maxxi)
//             {
//                 maxxi = sum;
//                 Arrstart = i;
//                 Arrend = j;
//             }
//         }
//     }
//     for(int i = Arrstart; i <= Arrend; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// Optimal.T.C -> O(n) ,S.C -> O(1).
void printLongestSubarraySum(int arr[],int n){
    int maxxi = INT_MIN,sum =0;
    int start = 0,Arrstart = -1,Arrend = -1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum == 0){
            start = i;
        }
        if (sum > maxxi)
        {
            maxxi = sum;
            Arrstart = start;
            Arrend = i;   
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    for (int i = Arrstart; i <= Arrend; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    printLongestSubarraySum(arr, n);
    return 0;
}