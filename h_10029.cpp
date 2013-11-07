#include <cstdio>
#include <algorithm>
using namespace std;
int a[260][1000];
void work(int n,int l,int r)
{
    if (l>n)
        return;
    r=min(r,n);
    int x=1,y=n+1>>1;
    for (int i=1;i<=n*n;i++)
    {  
        if (x>=l && x<=r)
            a[x-l][y]=i;
        if (i%n)
        {  
            x--,y++;
            if (!x)
                x=n;
            if (y>n)
                y=1;
        }
        else
        {  
            x++;
            if (x>n)
                x=1;
        }
    }
    for (int i=0;i<=r-l;i++)
        for (int j=1;j<=n;j++)
            printf("%d%c",a[i][j],j==n?'\n':' ');
}
bool main2()
{
    int n;
    scanf("%d",&n);
    if (n==0)
        return(false);
    work(n,1,250);
    work(n,251,500);
    work(n,501,750);
    work(n,751,1000);
    printf("\n");
    return(true);
}
int main()
{
    while (main2());
    return(0);
}

