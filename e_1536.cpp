#include <cstdio>
#include <algorithm>
using namespace std;
int a[1510];
int main()
{
    a[1]=1;
    int x=1,y=1,z=1;
    for (int i=2;i<=1500;i++)
    {
        int A=a[x]<<1,B=a[y]*3,C=a[z]*5;
        a[i]=min(min(A,B),C);
        if (a[x]<<1==a[i])
            x++;
        if (a[y]*3==a[i])
            y++;
        if (a[z]*5==a[i])
            z++;
    }
    printf("The 1500'th ugly number is %d.\n",a[1500]);
    return(0);
}

