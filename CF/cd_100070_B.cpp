#include <cstdio>
FILE *in,*out;
int q[100010],d[100010],b[100010],a[100010][2];
bool topsort(int n)
{
    int l,r;
    l=1,r=0;
    for (int i=1;i<=n;i++)
        if (!d[i])
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
    in=fopen("topsort.in","r");
    out=fopen("topsort.out","w");
    int n,m;
    fscanf(in,"%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        fscanf(in,"%d%d",&x,&y);
        a[i][0]=y,a[i][1]=b[x],b[x]=i;
        d[y]++;
    }
    if (!topsort(n))
        fprintf(out,"-1\n");
    else
        for (int i=1;i<=n;i++)
            fprintf(out,"%d%c",q[i],i==n?'\n':' ');
    return(0);
}

