#include<bits/stdc++.h>
using namespace std;
      
// Brute. T.C -> O(N * N), S.C -> O(N).
// vector<int> StockSpan(vector<int>& arr) {
//     int n = arr.size();
//     vector<int> res(n);
//     for(int i = 0; i < n; i++){
//         int currSpan = 0;
//         for (int j = i; j >= 0; j--)
//         {
//             if(arr[j] <= arr[i]){
//                 currSpan++;
//             } else break;
//         }
//         res[i] = currSpan;
//     }
//     return res;
// }                   
   
// Brute. T.C -> O(N ), S.C -> O(N).
vector<int> StockSpan(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }
        res[i] = st.empty() ? 1 : i - st.top();
        st.push(i);
    }
    return res;
}

int main() {
    vector<int> arr = {120, 100, 60, 80, 90, 110, 115};
    vector<int> res = StockSpan(arr) ;
    for(auto it: res) cout << it << " ";
    cout << endl;
    return 0;
}