#include <cstdio>
#include <algorithm>
using namespace std;
int a[110],b[110],c[110],f[110];
inline bool cmp(int x,int y)
{
    return(b[x]<b[y]);
}
int dfs(int len,int n)
{
    if (n==1)
        return(len);
    int num=len/f[n-1],rest=len%f[n-1];
    if (rest==0)
        num--,rest=f[n-1];
    return(num*b[n-1]+dfs(rest+a[n-1],n-1));
}
int q[110];
void change(int *a,int *c,int n)
{
    for (int i=1;i<=n;i++)
        q[i]=a[c[i]];
    for (int i=1;i<=n;i++)
        a[i]=q[i];
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            c[i]=i;
        }
        sort(c+1,c+n+1,cmp);
        change(a,c,n);
        change(b,c,n);
        bool flag=true;
        f[1]=b[1]-a[1];
        for (int i=2;i<=n;i++)
        {
            f[i]=(b[i]/b[i-1])*f[i-1]-a[i];
            if (f[i]<0)
            {
                flag=false;
                break;
            }
        }
        if (!flag)
            printf("-1\n");
        else
            printf("%d\n",dfs(a[n],n));
    }
    return(0);
}

