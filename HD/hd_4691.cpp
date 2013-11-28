#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=100010;
char buf[N];
int n,Log[N],a[N],sa[N],rank[N],height[N],b[N],c[N],f[N],x[N],lcp[17][N];
void sort(int *a)
{
    int t=0;
    for (int i=1;i<=n;i++)
        if (a[i]>t)
            t=a[i];
    for (int i=0;i<=t;i++)
        f[i]=0;
    for (int i=1;i<=n;i++)
        f[a[i]]++;
    for (int i=1;i<=t;i++)
        f[i]+=f[i-1];
    for (int i=n;i;i--)
        x[f[a[sa[i]]]--]=sa[i];
    for (int i=1;i<=n;i++)
        sa[i]=x[i];
}
int count(int *a,int *b)
{
    rank[sa[1]]=1;
    int t=1;
    for (int i=2;i<=n;i++)
    {
        if (a[sa[i]]!=a[sa[i-1]] || b[sa[i]]!=b[sa[i-1]])
            t++;
        rank[sa[i]]=t;
    }
    return(t);
}
void build()
{
    a[n+1]=-1;
    for (int i=1;i<=n;i++)
    {
        c[i]=a[i];
        b[i]=-1;
        sa[i]=i;
    }
    sort(c);
    count(b,c);
    for (int k=1;;k<<=1)
    {
        for (int i=1;i<=n;i++)
        {
            c[i]=rank[i];
            b[i]=i+k<=n?rank[i+k]:0;
        }
        sort(b),sort(c);
        if (count(b,c)>=n)
            break;
    }
    int k=0;
    for (int i=1;i<=n;i++)
    {
        k=k?k-1:0;
        if (rank[i]==1)
        {
            height[rank[i]]=0;
            continue;
        }
        int p=sa[rank[i]-1],q=sa[rank[i]];
        while (a[p+k]==a[q+k])
            k++;
        height[rank[i]]=k;
    }
    for (int i=1;i<=n;i++)
        lcp[0][i]=height[i];
    for (int i=1;i<=Log[n];i++)
        for (int j=1;j<=n;j++)
        {
            if (j+(1<<i)-1>n)
                break;
            lcp[i][j]=min(lcp[i-1][j],lcp[i-1][j+(1<<i-1)]);
        }
}
int calc(int x)
{
    int ret=0;
    while (x)
    {
        ret++;
        x/=10;
    }
    return(max(ret,1));
}
int query(int x,int y)
{
    if (x==y)
        return(n-x+1);
    x=rank[x],y=rank[y];
    if (x>y)
        swap(x,y);
    x++;
    int t=Log[y-x+1];
    return(min(lcp[t][x],lcp[t][y-(1<<t)+1]));
}
int main()
{
    for (int i=2;i<=N;i++)
    {
        Log[i]=Log[i-1];
        if ((i&i-1)==0)
            Log[i]++;
    }
    while (scanf("%s",buf)==1)
    {
        n=strlen(buf);
        for (int i=1;i<=n;i++)
            a[i]=buf[i-1];
        build();
        int m,t=-1,prev;
        scanf("%d",&m);
        ll len=0,ans=0;
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            int l=y-x;
            x++;
            len+=l;
            if (t==-1)
                ans+=len+2;
            else
            {
                int tmp=query(x,t);
                tmp=min(tmp,min(prev,l));
                ans+=l-tmp+1+calc(tmp);
            }
            t=x;
            prev=l;
        }
        printf("%I64d %I64d\n",len+m,ans+m);
    }
    return(0);
}

