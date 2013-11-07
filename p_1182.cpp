#include <cstdio>
int f[150010];
void init(int n)
{
    for (int i=1;i<=n;i++)
        f[i]=i;
}
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
bool same(int x,int y)
{
    return(find(x)==find(y));
}
void Union(int x,int y)
{
    f[find(x)]=find(y);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    init(3*n);
    int ans=0;
    for (int i=1;i<=m;i++)
    {
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if (x<=0 || x>n || y<=0 || y>n)
        {
            ans++;
            continue;
        }
        if (op==1)
        {
            if (same(x,y+n) || same(x,y+2*n))
            {
                ans++;
                continue;
            }
            Union(x,y);
            Union(x+n,y+n);
            Union(x+2*n,y+2*n);
        }
        else
        {
            if (same(x,y) || same(x,y+2*n))
            {
                ans++;
                continue;
            }
            Union(x,y+n);
            Union(x+n,y+2*n);
            Union(x+2*n,y);
        }
    }
    printf("%d\n",ans);
    return(0);
}

