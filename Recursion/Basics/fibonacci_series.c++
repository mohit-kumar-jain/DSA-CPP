#include<bits/stdc++.h>
                   
using namespace std;
int fib(int n){
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fib(n-1) + fib(n-2);
}               
int main() {
    int n;
    cin>>n;
    for (int j = 0; j < n; j++)
    {
        int k ;
        cin>>k;
        for (int i = 0; i < k; i++)
        {
            cout<<fib(i)<<endl;
        }
    }
    
    return 0;
}