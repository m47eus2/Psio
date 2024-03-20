#include<iostream>
using namespace std;

int NWD(int a, int b)
{
    int c;
    while(b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    int a, b;
    cin>>a>>b;
    
    cout<<NWD(a,b)<<endl;
   
    return 0;
}