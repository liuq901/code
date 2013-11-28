#include <cstdio>
int f[10010];
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
int main()
{
    int n,m,Q;
    scanf("%d%d%d",&n,&m,&Q);
    for (int i=1;i<=n;i++)
        f[i]=i;
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        f[find(x)]=find(y);
    }
    while (Q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%s\n",find(x)==find(y)?":)":":(");
    }
    return(0);
}

