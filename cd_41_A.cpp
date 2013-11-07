#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    reverse(s.begin(),s.end());
    cout<<(s==t?"YES":"NO")<<endl;
    return(0);
}

