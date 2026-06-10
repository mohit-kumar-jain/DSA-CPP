#include<bits/stdc++.h>
using namespace std;
         
// Brute -Force.T.C -> O(2n) ,S.C -> O(n).
// void rearrangeElements(int nums[], int n)
// {
//     int pos[n/2];
//     int neg[n/2];
//     int p = 0, q = 0;
//     for(int i = 0; i < n; i++)
//     {
//         if(nums[i] >= 0)
//             pos[p++] = nums[i];
//         else
//             neg[q++] = nums[i];
//     }
//     for(int i = 0; i < n/2; i++)
//     {
//         nums[2*i] = pos[i];
//         nums[2*i + 1] = neg[i];
//     }
//     printArray(nums,n)
// }

// Optimal . T.C -> O(n) ,S.C -> O(n).
void rearrangeElements(int nums[],int n){
    int res[n];
    int pos = 0, neg = 1;
    for (int i = 0; i < n; i++)
    {
        if(nums[i] > 0){
            res[pos] = nums[i];
            pos += 2;
        }else{
            res[neg] = nums[i];
            neg += 2;
        }
    }
    printArray(res,n);
}

void printArray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
}

int main() {
    int n;
    cin >> n;   
    int nums[n]; 
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    rearrangeElements(nums,n);
    return 0;
}