#include <cstdio>
#include <cstring>
const int N=200010;
int n,a[N],b[N],c[N],x[N],f[N],sa[N],rank[N],height[N];
void build()
{
    a[n+1]=-1;
    void sort(int *);
    int count(int *,int *);
    for (int i=1;i<=n;i++)
    {
        c[i]=a[i];
        b[i]=-1;
        sa[i]=i;
    }
    sort(c);
    count(c,b);
    int k=1;
    while (1)
    {
        for (int i=1;i<=n;i++)
        {
            c[i]=rank[i];
            if (i+k<=n)
                b[i]=rank[i+k];
            else
                b[i]=0;
        }
        sort(b);
        sort(c);
        if (count(c,b)>=n)
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
    for (int i=n;i>=1;i--)
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
char s[200010];
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    for (int i=1;i<=n;i++)
        s[i+n]=s[i];
    n<<=1;
    for (int i=1;i<=n;i++)
        a[i]=s[i];
    build();
    for (int i=1;i<=n;i++)
        if (sa[i]<=n/2)
            printf("%c",s[sa[i]+n/2-1]);
    printf("\n");
    return(0);
}

