#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[60],c[310][10];
int main()
{
    for (int i=1;i<=300;i++)
    {
        c[i][1]=i;
        for (int j=2;j<=min(i,4);j++)
            c[i][j]=c[i][j-1]*(i-j+1)/j;
    }
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        int ans=0;
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            a[x]++;
        }
        for (int i=1;i<=m;i++)
        {
            ans+=c[a[i]][3];
            for (int j=i+1;j<=m;j++)
                for (int k=j+1;k<=m;k++)
                    ans+=c[a[i]][1]*c[a[j]][1]*c[a[k]][1];
        }
        printf("%d ",ans);
        ans=0;
        for (int i=1;i<=m;i++)
        {
            ans+=c[a[i]][4];
            for (int j=1;j<=m;j++)
                if (i!=j)
                {
                    ans+=c[a[i]][3]*c[a[j]][1];
                    for (int k=j+1;k<=m;k++)
                        if (i!=k)
                        {
                            ans+=c[a[i]][2]*c[a[j]][1]*c[a[k]][1];
                            if (j>i)
                                for (int l=k+1;l<=m;l++)
                                    ans+=c[a[i]][1]*c[a[j]][1]*c[a[k]][1]*c[a[l]][1];
                        }
                }
        }
        printf("%d\n",ans);
    }
    return(0);
}

