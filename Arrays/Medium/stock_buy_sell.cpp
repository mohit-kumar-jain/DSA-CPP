#include <bits/stdc++.h>
using namespace std;

int  maxProfit(int arr[],int n){
    int maxi = 0,mini =  arr[0];
    for (int i = 1; i < n; i++)
    {
        int cost = arr[i] - mini;
        maxi = max(maxi,cost);
        mini = min(mini,arr[i]);
    }
    return maxi;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout<<maxProfit(arr, n);
    return 0;
}