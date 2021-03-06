#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int b[210],c[210];
ll K,f[210][210];
char a[210];
inline bool cmp(int x,int y)
{
    return(b[x]<b[y]);
}
ll dp(int n)
{
    f[0][0]=1;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=i;j++)
        {
            f[i][j]=0;
            if (j>0 && a[i]!=')')
                f[i][j]+=f[i-1][j-1];
            if (a[i]!='(')
                f[i][j]+=f[i-1][j+1];
            f[i][j]=min(f[i][j],K);
        }
    return(f[n][0]);
}
int main()
{
    int n,m;
    scanf("%d%d%I64d",&n,&m,&K);
    memset(b,63,sizeof(b));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            int x;
            scanf("%d",&x);
            b[i+j-1]=min(b[i+j-1],x);
        }
    for (int i=1;i<n+m;i++)
        c[i]=i;
    sort(c+1,c+n+m,cmp);
    for (int i=1;i<n+m;i++)
    {
        a[c[i]]='(';
        ll t=dp(n+m-1);
        if (K>t)
        {
            a[c[i]]=')';
            K-=t;
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
            printf("%c",a[i+j-1]);
        printf("\n");
    }
    return(0);
}

