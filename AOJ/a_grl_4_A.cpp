#include <cstdio>
int q[110],b[110],d[110],a[1010][2];
bool topsort(int n)
{
    int l=1,r=0;
    for (int i=1;i<=n;i++)
        if (d[i]==0)
            q[++r]=i;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            if (--d[y]==0)
                q[++r]=y;
        }
    }
    return(r==n);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x++,y++;
        a[i][0]=y,a[i][1]=b[x],b[x]=i;
        d[y]++;
    }
    printf("%d\n",!topsort(n));
    return(0);
}

