#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=10010;
char s[N];
int n,a[N],sa[N],rank[N],height[N];
void sort(int a[])
{
    int t=0,f[N],x[N];
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
    int b[N],c[N];
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
int calc(int l,int r)
{
    int ans=0;
    for (int i=1;i<=n;i++)
        ans+=max(0,min(r,n-sa[i]+1)-max(l,height[i]+1)+1);
    return(ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s);
        n=strlen(s);
        for (int i=1;i<=n;i++)
            a[i]=s[i-1];
        build();
        int l,r;
        scanf("%d%d",&l,&r);
        static int id=0;
        printf("Case %d: %d\n",++id,calc(l,r));
    }
    return(0);
}

