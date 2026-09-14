#include<bits/stdc++.h>
using namespace std;
            
// Brute. T.C -> O(N*N) , S.C -> O(1).
// int countSubStringLength(string s) {
//     int cnt = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
//         vector<int> mpp(3,0);
//         for (int j = i; j < s.size(); j++)
//         {
//             mpp[s[j] - 'a']++;
//             if(mpp[0] > 0 && mpp[1] > 0 && mpp[2] > 0){
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }                   

// Optimal. T.C -> O(N), S.C -> O(1).
int countSubStringLength(string s) {
    int cnt = 0, l = 0;
    vector<int> freq(3,0);
    for (int r = 0; r < s.size(); r++)
    {
        freq[s[r] - 'a']++;
        while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
        {
            cnt += (s.size() - r);
            freq[s[l] - 'a']--;
            l++;
        }
    }
    return cnt;
}
                   
int main() {
    string s = "abcba";
    cout << countSubStringLength(s) << endl;
    return 0;
}