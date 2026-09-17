#include<bits/stdc++.h>
using namespace std;
                
// T.C -> O(log N) , S.C -> O(log N).
string decToBin(int x) {
    if (x == 0) return "0";
    string res = "";
    while (x != 0)
    {
        if(x % 2 == 1) res += '1';
        else res += '0';
        x /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}                   
                   
int main() {
    int num = 6;
    cout << decToBin(num) << endl;
    return 0;
}