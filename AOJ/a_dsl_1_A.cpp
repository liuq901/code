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
    int n,Q;
    scanf("%d%d",&n,&Q);
    for (int i=1;i<=n;i++)
        f[i]=i;
    while (Q--)
    {
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        x++,y++;
        if (op==0)
            f[find(x)]=find(y);
        else
            printf("%d\n",find(x)==find(y));
    }
    return(0);
}

