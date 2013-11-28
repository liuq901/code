#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int q[100010],up[100010],down[100010],f[100010],d[100010],b[100010],a[200010][3];
void topsort()
{
    int l,r;
    q[l=r=1]=1;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            switch (a[i][1])
            {
            case 0:
                up[y]=up[x];
                down[y]=x;
                break;
            case 1:
                up[y]=x;
                down[y]=down[x];
                break;
            case 2:
                up[y]=up[x];
                break;
            case 3:
                down[y]=down[x];
                break;
            }
            if (--d[y]==0)
                q[++r]=y;
        }
    }
}
void getans()
{
    int l,r;
    q[l=r=1]=0;
    memset(f,0,sizeof(f));
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            f[y]=max(f[y],f[x]+1);
            if (--d[y]==0)
                q[++r]=y;
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            char op[10];
            int x,y,z;
            scanf("%s%d%d%d",op,&x,&y,&z);
            if (op[0]=='F')
            {
                a[i][0]=y,a[i][1]=0,a[i][2]=b[x],b[x]=i;
                a[i+m][0]=z,a[i+m][1]=1,a[i+m][2]=b[x],b[x]=i+m;
                d[y]++;
                d[z]++;
            }
            else
            {
                a[i][0]=z,a[i][1]=2,a[i][2]=b[x],b[x]=i;
                a[i+m][0]=z,a[i+m][1]=3,a[i+m][2]=b[y],b[y]=i+m;
                d[z]+=2;
            }
        }
        up[1]=0;
        down[1]=n+1;
        topsort();
        memset(b,0,sizeof(b));
        for (int i=1;i<=n;i++)
        {
            int x=up[i],y=down[i];
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            d[y]++;
        }
        getans();
        static int id=0;
        printf("Case #%d: %d\n",++id,f[n+1]);
    }
    return(0);
}

