#include<bits/stdc++.h>
using namespace std;
              
// T.C -> O(N), S.C -> O(1).
int binToDec(string x) {
    int p = 1, num = 0, len = x.size();
    for (int i = len - 1; i >= 0; i--)
    {
        if(x[i] == '1'){
           num += p; 
        }
        p *= 2;
    }
    return num;
}                   
                   
int main() {
    string num = "1101";
    cout << binToDec(num) << endl;
    return 0;
}