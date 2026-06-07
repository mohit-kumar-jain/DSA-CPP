#include<bits/stdc++.h>
using namespace std;
// Optimal Method.T.C -> O(n).  S.C -> O(1).
int max_ConsecutiveOnes(int arr[],int n){
    int count = 0;
    int maxCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count++;
            maxCount = max(maxCount,count);
        }
        else{
            count = 0;
        }
    }
    return maxCount;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<max_ConsecutiveOnes(arr,n);
    return 0;
}