#include<bits/stdc++.h>
using namespace std;
                   
void printSequences(int ind,vector<int> arr,int s,int sum,int n,vector<int>& ds) {
    if(ind == n) {
        if(s == sum) {
            for(auto it : ds) cout << it << " ";
            cout << endl;
        }
        return;
    }
    s += arr[ind];
    ds.push_back(arr[ind]);
    printSequences(ind + 1, arr, s, sum, n, ds);
    s -= arr[ind];
    ds.pop_back();
    printSequences(ind + 1, arr, s, sum, n, ds);
}                   

                   
int main() {
    vector<int> nums = {1,2,3,4,5,6};
    int sum = 10;
    int n = nums.size();
    vector<int> ds;
    printSequences(0,nums,0,sum,n,ds);
    return 0;
}