#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,K,now,f[1010],a[110][1010],b[110][1010];
void dfs(int x0,int y0,int sum,int dep,int v0)
{
    if (dep!=0 && x0==1)
    {
        f[y0]=max(f[y0],sum);
        return;
    }
    if (dep==K)
        return;
    for (int i=-1;i<=1;i++)
    {
        int v=v0+b[x0][y0]+i,x=max(1,min(n,x0+v)),y=y0+1;
        dfs(x,y,sum+a[x][y],dep+1,v);
    }
}
int main()
{
    while (1)
    {
        scanf("%d%d%d",&n,&m,&K);
        if (n==0 && m==0 && K==0)
            break;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                char s[10];
                int x;
                scanf("%s",s);
                sscanf(s+1,"%d",&x);
                if (s[0]=='$')
                    a[i][j]=x;
                else if (i!=1)
                    b[i][j]=x;
            }
        memset(f,-63,sizeof(f));
        f[0]=0;
        for (int i=1;i<=m;i++)
        {
            f[i]=max(f[i],f[i-1]+a[1][i]);
            dfs(1,i,f[i],0,0);
        }
        printf("%d\n",f[m]);
    }
    return(0);
}

