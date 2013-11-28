#include <cstdio>
#include <cstring>
typedef int array[20010];
int n;
array a,b,c,sa,rank,height,x,f;
void sort(int *a)
{
    int t=0;
    memset(f,0,sizeof(f));
    for (int i=1;i<=n;i++)
    {
        f[a[i]]++;
        if (a[i]>t)
            t=a[i];
    }
    for (int i=1;i<=t;i++)
        f[i]+=f[i-1];
    for (int i=n;i;i--)
    {
        x[f[a[sa[i]]]]=sa[i];
        f[a[sa[i]]]--;
    }
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
        if (k>0)
            k--;
        if (rank[i]==1)
        {
            height[1]=0;
            continue;
        }
        int p=sa[rank[i]-1],q=sa[rank[i]];
        while (1)
        {
            if (a[p+k]!=a[q+k])
                break;
            k++;
        }
        height[rank[i]]=k;
    }
    height[n+1]=-1;
}
bool check(int x)
{
    int min,max;
    min=max=0;
    for (int i=1;i<=n+1;i++)
    {
        if (height[i]<x)
        {
            if (max-min>x)
                return(true);
            min=sa[i];
            max=sa[i];
        }
        if (sa[i]>max)
            max=sa[i];
        if (sa[i]<min)
            min=sa[i];
    }
    return(false);
}
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for (int i=1;i<n;i++)
            a[i]-=a[i+1]-100;
        a[n--]=-1;
        build();
        int l=4,r=n/2,ans=0;
        while (l<=r)
        {
            int mid=l+r>>1;
            if (check(mid))
                ans=mid+1,l=mid+1;
            else
                r=mid-1;
        }
        printf("%d\n",ans);
    }
    return(0);
}

