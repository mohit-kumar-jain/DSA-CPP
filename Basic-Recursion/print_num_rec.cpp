#include<bits/stdc++.h>
                   
using namespace std;
void print(int n){
    if (n<=0)
    {
        return;
    }
    int i = 0;
    i++; 
    print(n-1);
    cout<<n-n+i<<endl;
}            
int main() {
    print(5);
    return 0;
}