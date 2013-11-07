#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=50010;
int n,m,l,r,c[N],d[N],q[N],b[N],rb[N],dist[N],add[N],a[N][3],ra[N][3];
bool S[N],T[N];
inline bool good(int x)
{
    return(S[x] && T[x]);
}
void getS()
{
    memset(S,0,sizeof(S));
    S[1]=true;
    q[l=r=1]=1;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (!S[y])
            {
                S[y]=true;
                q[++r]=y;
            }
        }
    }
}
void getT()
{
    memset(T,0,sizeof(T));
    T[n]=true;
    q[l=r=1]=n;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=rb[x];i;i=ra[i][2])
        {
            int y=ra[i][0];
            if (!T[y])
            {
                T[y]=true;
                q[++r]=y;
            }
        }
    }
}
void getd(int a[][3],int *b)
{
    for (int i=1;i<=n;i++)
    {
        if (!good(i))
            continue;
        for (int j=b[i];j;j=a[j][2])
        {
            int x=a[j][0];
            if (!good(x))
                continue;
            d[x]++;
        }
    }
}
void getdist()
{
    getd(ra,rb);
    q[l=r=1]=n;
    memset(dist,0,sizeof(dist));
    while (l<=r)
    {
        int x=q[l++];
        for (int i=rb[x];i;i=ra[i][2])
        {
            int y=ra[i][0];
            dist[y]=max(dist[y],dist[x]+ra[i][1]);
            if (--d[y]==0)
                q[++r]=y;
        }
    }
}
void getadd()
{
    getd(a,b);
    q[l=r=1]=1;
    memset(add,0,sizeof(add));
    while (l<=r)
    {
        int x=q[l++],value=-1;
        bool flag=false;
        for (int i=rb[x];i;i=ra[i][2])
        {
            if (value==-1)
            {
                flag=true;
                value=add[i];
            }
            if (value!=add[i])
            {
                flag=false;
                break;
            }
        }
        if (!flag)
            value=0;
        else
            for (int i=rb[x];i;i=ra[i][2])
                add[i]=0;
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            add[i]=dist[x]-dist[y]-a[i][1]+value;
            if (--d[y]==0)
                q[++r]=y;
        }
    }
}
bool check()
{
    getd(a,b);
    q[l=r=1]=1;
    memset(c,0,sizeof(c));
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            c[y]=max(c[y],c[x]+(add[i]!=0));
            if (--d[y]==0)
                q[++r]=y;
        }
    }
    return(c[n]<=1);
}
int main()
{
    while (1)
    {
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        memset(b,0,sizeof(b));
        memset(rb,0,sizeof(rb));
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
            ra[i][0]=x,ra[i][1]=z,ra[i][2]=rb[y],rb[y]=i;
        }
        getS();
        getT();
        getdist();
        getadd();
        static int id=0;
        printf("Case %d: ",++id);
        if (!check())
            printf("No solution\n");
        else
        {
            printf("%d %d\n",m-count(add+1,add+m+1,0),dist[1]);
            for (int i=1;i<=m;i++)
                if (add[i])
                    printf("%d %d\n",i,add[i]);
        }
    }
    return(0);
}

