#include<bits/stdc++.h>
                   
using namespace std;
int fact(int n){
    if (n==1 || n== 0)   
    {
        return 1;
    }
    return n * fact(n-1);
}                   
int main() {
    int t ;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin>>n;
        cout<<fact(n)<<endl;
    }
    return 0;
}