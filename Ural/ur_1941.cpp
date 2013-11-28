#include <cstdio>
#include <cstring>
int n,m;
int a[8010],b[500010],f[730000],g[730000];
char s[2000000];
void read(int &n,int *a)
{
    gets(s);
    int len=strlen(s);
    n=0;
    for (int i=0;i<len;i+=4)
    {
        a[++n]=0;
        for (int j=0;j<3;j++)
            a[n]=a[n]*90+s[i]-33;
    }
}
int main()
{
    read(n,a);
    read(m,b);
    int tot=0;
    for (int i=1;i<=n;i++)
    {
        f[a[i]]++;
        if (f[a[i]]==1)
            tot++;
    }
    int sum=0,ans=0;
    for (int i=1;i<=m;i++)
    {
        g[b[i]]++;
        if (g[b[i]]==f[b[i]])
            sum++;
        if (g[b[i]]==f[b[i]]+1)
            sum--;
        if (i>n)
        {
            g[b[i-n]]--;
            if (g[b[i-n]]==f[b[i-n]])
                sum++;
            if (g[b[i-n]]==f[b[i-n]]-1)
                sum--;
        }
        if (i>=n && tot==sum)
            ans++;
    }
    printf("%d\n",ans);
    return(0);
}

