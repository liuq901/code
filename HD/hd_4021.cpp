#include <cstdio>
#include <algorithm>
using namespace std;
const int c[]={0,1,2,3,8,17,22,23,24};
const int d[]={0,4,7,4,7,18,21,18,21};
int a[30],b[30],e[10][10];
bool f[30];
void change(int *a)
{
    int x=1,y=0,x0,y0;
    for (int i=1;i<=24;i++)
    {
        if (f[i])
            continue;
        y++;
        if (y==5)
            x++,y=1;
        e[x][y]=a[i];
        if (e[x][y]==0)
            x0=x,y0=y;
    }
    while (x0!=4)
    {
        swap(e[x0][y0],e[x0+1][y0]);
        x0++;
    }
    while (y0!=4)
    {
        swap(e[x0][y0],e[x0][y0+1]);
        y0++;
    }
    x=1,y=0;
    for (int i=1;i<=16;i++)
    {
        y++;
        if (y==5)
            x++,y=1;
        a[i]=e[x][y];
    }
}
bool check()
{
    for (int i=1;i<=8;i++)
    {
        if (a[c[i]]==0)
            swap(a[c[i]],a[d[i]]);
        if (b[c[i]]==0)
            swap(b[c[i]],b[d[i]]);
        if (a[c[i]]!=b[c[i]])
            return(false);
        f[c[i]]=true;
    }
    change(a);
    change(b);
    int s=0,t=0;
    for (int i=1;i<=16;i++)
        for (int j=i+1;j<=16;j++)
        {
            s+=a[i]>a[j];
            t+=b[i]>b[j];
        }
    return(s%2==t%2);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        for (int i=1;i<=24;i++)
            scanf("%d",&a[i]);
        for (int i=1;i<=24;i++)
            scanf("%d",&b[i]);
        printf("%c\n",!check()?'Y':'N');
    }
    return(0);
}

