#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=10000;
int a[maxn+10];
bool f[maxn+10],ok[3000][3000];
int get(int x,int y)
{
    int ret=x,t=y;
    while (t)
    {
        ret*=10;
        t/=10;
    }
    ret+=y;
    return(ret);
}
bool check(int x)
{
    for (int i=2;i*i<=x;i++)
        if (x%i==0)
            return(false);
    return(true);
}
void init()
{
    for (int i=2;i*i<=maxn;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=maxn;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=maxn;i++)
        if (!f[i])
            a[++a[0]]=i;
    for (int i=1;i<=a[0];i++)
        for (int j=i+1;j<=a[0];j++)
        {
            int x=get(a[i],a[j]),y=get(a[j],a[i]);
            ok[i][j]=check(x) && check(y);
        }
}
int ans[10];
void dfs(int sum,int dep,int now)
{
    if (dep==6)
    {
        ans[0]=min(ans[0],sum);
        return;
    }
    for (int i=now;i<=a[0];i++)
    {
        bool flag=true;
        for (int j=1;j<dep;j++)
            if (!ok[ans[j]][i])
            {
                flag=false;
                break;
            }
        if (flag)
        {
            ans[dep]=i;
            dfs(sum+a[i],dep+1,i+1);
        }
    }
}
int main()
{
    init();
    ans[0]=1<<30;
    dfs(0,1,1);
    printf("%d\n",ans[0]);
    return(0);
}

