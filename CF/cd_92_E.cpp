#include <cstdio>
const int mod=1000000009;
int checkmod(int x)
{
    x%=mod;
    if (x<0)
        x+=mod;
    return(x);
}
int f[100010];
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        f[i]=i;
    int ans=1;
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if (find(x)==find(y))
            ans=checkmod(ans+ans);
        else
            f[find(x)]=find(y);
        printf("%d\n",checkmod(ans-1));
    }
    return(0);
}

