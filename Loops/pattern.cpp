#include <bits/stdc++.h>
using namespace std;
// Box pattern
void pat1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pat2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pat3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
void pat4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}
void pat5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pat6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
// Triangle pattern
void pat7(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 1; j <= (2 * i - 1); j++)
        {
            cout << "*";
        }
        
        // spaces
         for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
// Reverse Triangle pattern
void pat8(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // space
        for (int j = 1; j <= i + 1; j++)
        {
            cout << " ";
        }

        // star
        for (int j = 1; j <= (2 * n )-(2*i-1); j++)
        {
            cout << "*";
        }
        
        // space
        for (int j = 1; j <= i + 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
// Triangle (Diamond)both side
void pat9(int n)
{

    // upper pyramid
    for (int i = 1; i <= n; i++)
    {
        // spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 1; j <= (2 * i - 1); j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    // lower inverted pyramid
    for (int i = 1; i <= n; i++)
    {
        // spaces
        for (int j = 1; j <= i; j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 1; j <= (2 * n) - (2 * i + 1); j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}
// Arrow pattern
void pat10(int n){
    for (int i = 1; i <= n; i++)
    {
            for (int j = 1; j <= i; j++)
            {
                cout<<"*";
            }
        cout<<endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j=n-1; j >= i; j--)
        {
            cout<<"*";
        }
        cout<<endl;        
    }    
}
// 1,0 Right triangle
void pat11(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if((i+j)%2==0){
                cout<<"1";
            }else{
                cout<<"0";
            }
            
        }
        cout<<endl;
    }
}
// num space num pattern
void pat12(int n){
    for (int i = 1; i <= n; i++)
    {
        // num
        for (int j = 1; j <= i ; j++)
        {
            cout<<j;
        }
        // space
        for (int j = 1; j <= (2*n-(2*i)); j++)
        {
            cout<<" ";
        }
        // num
        for (int j = i; j >= 1; j--)
        {
            cout<<j;
        }
        cout<<endl;
    }
}
// right triangle with numbers
void pat13(int n){
    int num=1;
    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<num<<" ";
            num+=1;
        }
        cout<<endl;
    }
}
// right angle with alphabets
void pat14(int n){
    for(int i = 1;i<= n;i++)
    {
        for (char j ='A'; j <= 'A'+ i-1; j++)
        {
            cout<<j;
        }
        cout<<endl;
    }
}
// right angle with alphabets (inverted)
void pat15(int n){
    for(int i = n;i>=1;i--)
    {
        for (char j ='A'; j <= 'A'+ i-1; j++)
        {
            cout<<j;
        }
        cout<<endl;
    }
}
// right angle with rows of same alphabet
void pat16(int n){
    for(int i = 1;i<=n;i++)
    {
        char ch = 'A' + i - 1;
        for (int j = 1; j <= i; j++)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}
// Triangle with alphabets
void pat17(int n){
    for (int i = 1; i <= n; i++)
    {
        
        // space
        for (int j = 1; j <= n-i; j++)
        {
            cout<<" ";
        }
        // alphabet
        char ch = 'A';
        int breakpoint = (2 * i - 1)/2;
        for (int j = 1 ; j <= 2 * i  -1 ; j++)
        {
            cout<<ch;
            if(j <= breakpoint){
                ch= ch + 1;
            }else{
                ch = ch -1;
            }
        }
        
            // space
        for (int j = 1; j <= n-i; j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }
}
// right triangle with highest to lowest alphabets
void pat18(int n){
    char ch = 'E';
    for (int i = 1; i <= n; i++)
    {
        
        for (char ch ='E'-i+1;ch<='E';ch++)
        {
            cout<<ch<<" ";  
        }
        cout<<endl;
    }
    
}
void pat19(int n){
    // Upper part
    for (int i = 0; i < n; i++)
    {
        //stars
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }

        // spaces
        for (int j = 0; j < 2 * i; j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    // Lower part
    for (int i = 1; i <= n; i++)
    {
        // stars
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }

        // spaces
        for (int j = 0; j < 2 * (n - i); j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}
// Butterfly pattern
void pat20(int n){
    // Upper part for butterfly
    for (int i = 1; i <= n; i++)
    {
        // stars
        for (int j = 0; j < i; j++)
        {
            cout<<"*";
        }
        // spaces
        for (int j = 1; j <= (2*n)-2*i; j++)
        {
            cout<<" ";
        }
        // stars
        for (int j = 0; j < i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    // Lower part for butterfly
    for (int i = 1; i < n; i++)
    {    
            // stars
            for (int j = n-i; j >= 1; j--)
            {
                cout<<"*";
            }
            // spaces
            for (int j = 1; j <= 2*i; j++)
            {
                cout<<" ";
            }
            
            // stars
            for (int j = n-i; j >= 1; j--)
            {
                cout<<"*";
            }          
            cout<<endl;
    }  
}
// square outline pattern
void pat21(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i==1 || i==n || j==1 || j==n)
            {
                cout<<"*";
            }else{
                cout<<" ";
            }
            
        }
        cout<<endl;
    }
    
}
// numbers frame
void pat22(int n){
    for (int i = 0; i < 2*n-1; i++)
    {
        for (int j = 0; j < 2*n-1; j++)
        {
            int top = i;
            int left = j;
            int right = (2*n-2)-j;
            int bottom = (2*n-2)-i;
            cout<<(n-min(min(top,bottom),min(left,right)));
        }
        cout<<endl;
    }
}
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        pat22(n);
    }
}