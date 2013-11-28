#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
double ans[110],b[110],a[110][110];
int id[20][20],pos[110][2];
void gauss(int n)
{
    for (int i=1;i<=n;i++)
    {
        int k=i;
        for (int j=i;j<=n;j++)
            if (fabs(a[j][i])>fabs(a[k][i]))
                k=j;
        for (int j=i;j<=n;j++)
            swap(a[i][j],a[k][j]);
        swap(b[i],b[k]);
        for (int j=1;j<=n;j++)
        {
            if (i==j)
                continue;
            double t=a[j][i]/a[i][i];
            for (int k=i;k<=n;k++)
                a[j][k]-=a[i][k]*t;
            b[j]-=b[i]*t;
        }
    }
    for (int i=1;i<=n;i++)
        ans[i]=b[i]/a[i][i];
}
int main()
{
    bool first=true;
    while (1)
    {
        int n,m,D;
        scanf("%d%d%d",&m,&n,&D);
        if (n==0 && m==0 && D==0)
            break;
        int tot=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                id[i][j]=++tot;
                pos[tot][0]=i,pos[tot][1]=j;
                scanf("%lf",&b[tot]);
            }
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                int cnt=0;
                for (int k=1;k<=n;k++)
                    for (int l=1;l<=m;l++)
                        if (abs(i-k)+abs(j-l)<=D)
                        {
                            a[id[i][j]][id[k][l]]=1;
                            cnt++;
                        }
                b[id[i][j]]*=cnt;
            }
        gauss(tot);
        if (!first)
            printf("\n");
        first=false;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
                printf("%8.2f",ans[id[i][j]]);
            printf("\n");
        }
    }
    return(0);
}

