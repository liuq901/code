#include <cstdio>
#include <cstdlib>
#include <cstring>
struct point
{
    int x,y,z;
    void in()
    {
        scanf("%d%d%d",&x,&y,&z);
    }
};
int operator -(point a,point b)
{
    return(abs(a.x-b.x)+abs(a.y-b.y)+abs(a.z-b.z));
}
int t[1010],b[1010],c[1010],a[1010][1010];
point begin[1010],end[1010];
bool f[1010];
bool hungary(int x)
{
    if (!x)
        return(true);
    for (int i=1;i<=a[x][0];i++)
    {
        int y=a[x][i];
        if (f[y])
            continue;
        f[y]=true;
        if (hungary(c[y]))
        {
            c[y]=x;
            return(true);
        }
    }
    return(false);
}
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&t[i]);
            begin[i].in(),end[i].in();
            b[i]=end[i]-begin[i]+t[i];
        }
        for (int i=1;i<=n;i++)
            a[i][0]=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (begin[j]-end[i]<=t[j]-b[i])
                    a[i][++a[i][0]]=j;
        int ans=n;
        memset(c,0,sizeof(c));
        for (int i=1;i<=n;i++)
        {
            memset(f,0,sizeof(f));
            ans-=hungary(i);
        }
        printf("%d\n",ans);
    }
    return(0);
}

