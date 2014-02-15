#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int a[]={0,2,3,5,2*5,3*4,5*3};
const int b[]={0,380,550,850,380*5*0.8,550*4*0.85,850*3*0.88};
int f[60];
int main()
{
    memset(f,63,sizeof(f));
    f[0]=0;
    for (int i=1;i<=6;i++)
        for (int j=a[i];j<=50;j++)
            f[j]=min(f[j],f[j-a[i]]+b[i]);
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        printf("%d\n",f[n/100]);
    }
    return(0);
}

