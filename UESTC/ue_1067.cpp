#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n,d1,d2,f;
    cin>>n>>d1>>d2>>f;
    if (f)
        cout<<right;
    else
        cout<<left;
    for (int i=1;i<=n;i++)
    {
        char s[100];
        int x;
        cin>>s>>x;
        cout<<setw(d1)<<s<<setw(d2)<<x<<endl;
    }
    return(0);
}

