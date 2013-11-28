#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
typedef long long ll;
int q[10010],a[110][10010],b[110][10010];
ll s[10010],w[10010],p[10010],f[110][10010],g[110][10010];
void read(int &n)
{
    char ch;
    while (1)
    {
        ch=getchar();
        if (isdigit(ch) || ch=='-')
            break;
    }
    bool nega=ch=='-';
    n=0;
    if (isdigit(ch))
        n=ch-'0';
    while (1)
    {
        ch=getchar();
        if (isdigit(ch))
            n=(n<<3)+(n<<1)+ch-'0';
    }
    if (nega)
        n=-n;
}
int main()
{
    while (1)
    {
        int n,m,T;
        read(n);
        read(m);
        read(T);
        if (n==0 && m==0 && T==0)
            break;
        n++;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                read(a[i][j]);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                read(b[i][j]);
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        for (int i=1;i<=n;i++)
        {
            int l,r;
            l=1,r=0;
            s[0]=0;
            w[0]=0;
            for (int j=1;j<=m;j++)
            {
                s[j]=s[j-1]+b[i][j];
                w[j]=w[j-1]+a[i][j];
            }
            for (int j=0;j<=m;j++)
            {
                while (l<=r && s[j]-s[q[l]]>T)
                    l++;
                p[j]=f[i][j]=max(f[i-1][j],g[i-1][j]);
                if (l<=r)
                    f[i][j]=max(f[i][j],w[j]-w[q[l]]+p[q[l]]);
                while (l<=r && s[j]-s[q[l]]>=0 && p[j]>w[j]-w[q[r]]+p[q[r]])
                    r--;
                q[++r]=j;
            }
            l=1,r=0;
            s[m]=0;
            w[m]=0;
            for (int j=m-1;j>=0;j--)
            {
                s[j]=s[j+1]+b[i][j+1];
                w[j]=w[j+1]+a[i][j+1];
            }
            for (int j=m;j>=0;j--)
            {
                while (l<=r && s[j]-s[q[l]]>T)
                    l++;
                p[j]=g[i][j]=max(f[i-1][j],g[i-1][j]);
                if (l<=r)
                    g[i][j]=max(g[i][j],w[j]-w[q[l]]+p[q[l]]);
                while (l<=r && s[j]-s[q[l]]>=0 && p[j]>w[j]-w[q[r]]+p[q[r]])
                    r--;
                q[++r]=j;
            }
        }
        ll ans=0;
        for (int i=0;i<=m;i++)
            ans=max(ans,max(f[n][i],g[n][i]));
        printf("%d\n",int(ans));
    }
    return(0);
}

