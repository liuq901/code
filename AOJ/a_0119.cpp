#include <cstdio>
int q[30],b[30],d[30],a[110][2];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[i][0]=y,a[i][1]=b[x],b[x]=i;
        d[y]++;
    }
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
    for (int i=1;i<=n;i++)
        printf("%d\n",q[i]);
    return(0);
}

