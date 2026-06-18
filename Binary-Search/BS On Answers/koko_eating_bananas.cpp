#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(maxi*n), S.C -> O(1).
// int maximum(vector<int>& a){
//     int maxi = INT_MIN;
//     for (int i = 0; i < a.size(); i++)
//     {
//         maxi = max(maxi,a[i]);
//     }
//     return maxi;
// }

// int calculateHrs(vector<int>& a,int hrs){
//     int n = a.size();
//     int totalhrs = 0;
//     for (int i = 0; i < n; i++)
//     {
//         totalhrs += ceil((double)a[i] / (double) hrs);
//     }
//     return totalhrs;
// }

// int koko(vector<int> a,int h)
// {
//     int maxi = maximum(a);
//     for(int i = 1; i <= maxi;i++){
//         int  requiredTime = calculateHrs(a,i);
//         if(requiredTime <= h){
//             return i;
//         }
//     }
//     return  -1;
// }

// Optimal. T.C -> O(maxi*logn), S.C -> O(1).
int maximum(vector<int>& a){
    int maxi = INT_MIN;
    for (int i = 0; i < a.size(); i++)
    {
        maxi = max(maxi,a[i]);
    }
    return maxi;
}

int calculateHrs(vector<int>& a,int hrs){
    int n = a.size();
    int totalhrs = 0;
    for(int i = 0; i < n;i++){
        totalhrs += ceil((double)a[i] / (double) hrs);
    }
    return totalhrs;
}

int minEatingSpeed(vector<int>& a,int hrs){
    int n = a.size();
    int low = 1, high = maximum(a);
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(calculateHrs(a,mid) <= hrs){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {25, 12, 8, 14, 19};
    int hours = 5;
    cout << minEatingSpeed(arr,hours);
    return 0;
}