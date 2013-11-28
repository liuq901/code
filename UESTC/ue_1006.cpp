#include <cstdio>
#include <algorithm>
using namespace std;
int x[100010],h[100010],c[100010];
inline int cmp(int a,int b)
{
    return(x[a]<x[b]);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&x[i],&h[i]);
            c[i]=i;
        }
        int u,v;
        scanf("%d/%d",&u,&v);
        sort(c+1,c+n+1,cmp);
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            int t=i;
            for (int j=i+1;j<=n;j++)
            {
                if ((h[c[t]]-h[c[j]])*v<(x[c[j]]-x[c[t]])*u)
                    break;
                i=j;
            }
            ans++;
        }
        printf("%d\n",ans);
    }
    return(0);
}

