#include <cstdio>
#include <algorithm>
using namespace std;
int n,X[30],Y[30],r[30],c[30];
char f[17000000];
bool flag[30][30];
int sqr(int x)
{
    return(x*x);
}
bool intersect(int a,int b)
{
    return(sqr(X[a]-X[b])+sqr(Y[a]-Y[b])<sqr(r[a]+r[b]));
}
bool move(int id,int state)
{
    for (int i=1;i<id;i++)
        if (flag[i][id] && state>>i-1&1)
            return(false);
    return(true);
}
char dp(int state)
{
    if (f[state]!=-1)
        return(f[state]);
    char &ret=f[state];
    ret=0;
    int p[10][30];
    for (int i=1;i<=4;i++)
        p[i][0]=0;
    for (int i=1;i<=n;i++)
    {
        if (!(state>>i-1&1) || !move(i,state))
            continue;
        p[c[i]][++p[c[i]][0]]=i;
    }
    for (int T=1;T<=4;T++)
        for (int i=1;i<=p[T][0];i++)
            for (int j=i+1;j<=p[T][0];j++)
            {
                int x=p[T][i],y=p[T][j];
                ret=max(ret,char(dp(state^1<<x-1^1<<y-1)+2));
            }
    return(ret);
}
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d%d%d%d",&X[i],&Y[i],&r[i],&c[i]);
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                flag[i][j]=intersect(i,j);
        for (int i=0;i<1<<n;i++)
            f[i]=-1;
        printf("%d\n",int(dp((1<<n)-1)));
    }
    return(0);
}

