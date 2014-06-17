#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
const int N=50010,lq=1000000007;
int n,a[N],sa[N],rank[N],height[N];
void sort(int a[])
{
    int t=0;
    static int f[N],x[N];
    memset(f,0,sizeof(f));
    for (int i=1;i<=n;i++)
    {
        f[a[i]]++;
        t=max(t,a[i]);
    }
    for (int i=1;i<=t;i++)
        f[i]+=f[i-1];
    for (int i=n;i;i--)
        x[f[a[sa[i]]]--]=sa[i];
    for (int i=1;i<=n;i++)
        sa[i]=x[i];
}
int count(int a[],int b[])
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
    static int b[N],c[N];
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
}
char s[50010],t[50010];
ull h[50010],p[50010];
ull get(int start,int len)
{
    return(h[start+len-1]-h[start-1]*p[len]);
}
int len[50010];
void calc(int m)
{
    p[0]=1;
    for (int i=1;i<=n;i++)
    {
        h[i]=h[i-1]*lq+s[i];
        p[i]=p[i-1]*lq;
    }
    ull now=0;
    for (int i=1;i<=m;i++)
        now=now*lq+t[i];
    len[n+1]=0;
    for (int i=n;i;i--)
    {
        len[i]=len[i+1]+1;
        if (n-i+1>=m && get(i,m)==now)
            len[i]=m-1;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s%s",s+1,t+1);
        n=strlen(s+1);
        int m=strlen(t+1);
        for (int i=1;i<=n;i++)
            a[i]=s[i];
        build();
        calc(m);
        ull ans=0;
        for (int i=1;i<=n;i++)
            ans+=max(0,len[sa[i]]-height[i]);
        static int id=0;
        printf("Case %d: %llu\n",++id,ans);
    }
    return(0);
}

