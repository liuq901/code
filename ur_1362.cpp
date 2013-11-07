#include <cstdio>
#include <algorithm>
using namespace std;
int c[100010],f[100010],b[100010],a[200010][2];
inline bool cmp(int x,int y)
{
    return(f[x]>f[y]);
}
int dp(int x,int father)
{
    int ret=0,n=0;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        f[y]=dp(y,x);
    }
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        c[++n]=y;
    }
    sort(c+1,c+n+1,cmp);
    for (int i=1;i<=n;i++)
    {
        int y=c[i];
        ret=max(ret,f[y]+i);
    }
    return(ret);
}
int main()
{
    int n,m=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        while (1)
        {
            int x;
            scanf("%d",&x);
            if (!x)
                break;
            a[++m][0]=x,a[m][1]=b[i],b[i]=m;
            a[++m][0]=i,a[m][1]=b[x],b[x]=m;
        }
    int root;
    scanf("%d",&root);
    printf("%d\n",dp(root,0));
    return(0);
}

