#include<bits/stdc++.h>
using namespace std;
                   
bool printOne(int ind, vector<int> arr, int s, int sum, int n, vector<int>& ds ) {
    if(ind == n) {
        if(s == sum) {
            for(auto it : ds) cout << it << " ";
            cout << endl;
            return true;
        }
        else return false;
    }
    s += arr[ind];
    ds.push_back(arr[ind]);
    if(printOne(ind + 1, arr, s, sum, n, ds) == true){
        return true;
    }
    s -= arr[ind];
    ds.pop_back();
    if(printOne(ind + 1, arr, s, sum, n, ds) == true){
        return true;
    }
    else return false;
}                
                   
int main() {
    vector<int> nums = {1,2,3,4,5,6};
    int sum = 10;
    int n = nums.size();
    vector<int> ds;
    printOne(0,nums,0,sum,n,ds);
    return 0;
}