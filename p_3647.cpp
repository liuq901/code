#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
string s[2510];
double a[2510],f[2510][2510];
int c[2510];
char buf[10000];
bool bye[2510],pre[2510][2510];
inline bool cmp(int x,int y)
{
    return(a[x]<a[y]);
}
inline double sqr(double x)
{
    return(x*x);
}
inline int calc(int n)
{
    int limit=1;
    while (limit<n)
        limit<<=1;
    return(n-(limit>>1));
}
void print(int n,int m)
{
    if (n==0 && m==0)
        return;
    if (pre[n][m])
    {
        bye[n]=true;
        print(n-1,m);
    }
    else
        print(n-2,m-1);
}
int main()
{
    bool first=true;
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        int m=calc(n);
        for (int i=1;i<=n;i++)
        {
            scanf("%s%lf",buf,&a[i]);
            s[i]=buf;
            c[i]=i;
        }
        sort(c+1,c+n+1,cmp);
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n;j++)
                f[i][j]=1e26;
        f[0][0]=0;
        for (int i=1;i<=n;i++)
        {
            double now=sqr(a[c[i]]-a[c[i-1]]);
            for (int j=0;j<=m;j++)
            {
                if (i>=2 && j>=1 && f[i-2][j-1]+now<f[i][j])
                {
                    f[i][j]=f[i-2][j-1]+now;
                    pre[i][j]=false;
                }
                if (f[i-1][j]<f[i][j])
                {
                    f[i][j]=f[i-1][j];
                    pre[i][j]=true;
                }
            }
        }
        if (!first)
            printf("\n");
        first=false;
        memset(bye,0,sizeof(bye));
        print(n,m);
        for (int i=1;i<=n;i++)
            if (bye[i])
                printf("%s\n",s[c[i]].c_str());
    }
    return(0);
}

