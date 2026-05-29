#include<bits/stdc++.h>
                   
using namespace std;
// 1.Count the number of digits in a  number.
void count(int n){
    int cnt = 0;
    while(n>0){
        cnt+=1;
        n/=10;
    }
    cout<< cnt;
}                   
// 2.Reverse the number
void rev(int n){
    int revnum =0; 
    while(n>0){
        int digit = n%10;
        revnum = (revnum * 10)+digit;
        n /= 10 ;
    }
    cout<<revnum;
}
// 3.Palindrome number check
void pal(int n){
    int temp = n;
    int revnum = 0;
    while(n>0){
        int digit = n%10;
        revnum = (revnum * 10)+digit;
        n /= 10;
    }
    if(revnum == temp){
        cout<<temp<<" is a palindrome."<<endl;
    }else{
        cout<<temp<<" is not a palindrome."<<endl;
    }
}
// 4.GCD of 2 numbers
void GCD(int a,int b){
    while(b!=0){
        int temp = b;
        b = b%a;
        a = temp;
    }
    int res = a;
        cout<<"GCD of "<<a<<" and "<<b<<" is "<< res<<endl;
}
// 5. Armstrong number check
void arm(int n){
    int temp = n;
    int sum = 0;
    while(n>0){
        int digit = n%10;
        sum = sum + (digit* digit * digit);
        n /= 10;
    }
    if(sum == temp){
        cout<<"The Given number "<<temp<< " is a Armstrong number."<<endl;
    }else{
        cout<<"The Given number "<<temp<< " is not a Armstrong number."<<endl;

    }
}
// 6.Printing all divisors of a number
void div(int n){
    for (int i = 1; i <=n; i++)
    {
        while(n%i==0){
        cout<<"The Divisors of "<<n<<" are "<<i<<endl;
        i++;
        }
    }
}
// 7. Prime Number 
void Prime(int n){
    bool isPrime =true;
     if (n <= 1) {
        isPrime = false;
    } else {
        for (int i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                isPrime = false;
                break; 
            }
        }
    }
    if (isPrime)
        cout << n << " is a prime number." << endl;
    else
        cout << n << " is not a prime number." << endl;
}


int main() {
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin>>t;
        Prime(t);
    }
    
    return 0;
}