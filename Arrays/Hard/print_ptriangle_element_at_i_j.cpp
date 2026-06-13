#include<bits/stdc++.h>
using namespace std;

// Time Complexity -> O(min(c,r−c)),Space Complexity -> O(1).
long long nCr(int row,int col){
    long long res =  1;
    for(int i = 0;i < col;i++)
    {
        res = res * (row-i); 
        res = res / (i+1);
    }
    return res;
}

int main(){
    int m,n;
    cin >> m >> n;
    cout<<nCr(m-1,n-1)<<endl;
}