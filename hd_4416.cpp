#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=300010;
char s[N];
int n,len,a[N],sa[N],rank[N],height[N],x[N],f[N],b[N],c[N];
void sort(int *a)
{
    int t=0;
    for (int i=1;i<=n;i++)
        t=max(t,a[i]);
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
int l[N];
ll getans()
{
    ll ans=0;
    for (int i=n;i;i--)
    {
        if (sa[i]>len)
            continue;
        if (i==n)
            l[i]=0;
        else if (sa[i+1]>len)
            l[i]=height[i+1];
        else
            l[i]=min(l[i+1],height[i+1]);
    }
    for (int i=1;i<=n;i++)
        if (sa[i]<=len)
        {
            int tmp=len-sa[i]+1;
            int now=max(0,min(tmp-height[i],tmp-l[i]));
            ans+=now;
        }
    return(ans);
}
void build()
{
    for (int i=1;i<=n;i++)
    {
        c[i]=a[i];
        b[i]=-1;
        sa[i]=i;
    }
    sort(c);
    count(b,c);
    int k=1;
    while (1)
    {
        for (int i=1;i<=n;i++)
        {
            c[i]=rank[i];
            b[i]=i+k<=n?rank[i+k]:0;
        }
        sort(b),sort(c);
        if (count(b,c)>=n)
            break;
        k<<=1;
    }
    k=0;
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
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int m;
        scanf("%d%s",&m,s);
        len=strlen(s);
        for (int i=1;i<=len;i++)
            a[i]=s[i-1];
        n=len;
        for (int i=1;i<=m;i++)
        {
            scanf("%s",s);
            int K=strlen(s);
            a[++n]=1000+i;
            for (int j=0;j<K;j++)
                a[++n]=s[j];
        }
        a[n+1]=-1;
        build();
        static int id=0;
        printf("Case %d: %I64d\n",++id,getans());
    }
    return(0);
}

