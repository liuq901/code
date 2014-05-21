#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int n=100;
double *a[110],b[110],c[110][110];
double gauss()
{
    for (int i=1;i<=n;i++)
        a[i]=c[i];
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j<=n;j++)
            if (fabs(a[j][i])>fabs(a[i][i]))
            {
                swap(a[i],a[j]);
                swap(b[i],b[j]);
            }
        for (int j=1;j<=n;j++)
        {
            if (i==j)
                continue;
            double p=a[j][i]/a[i][i];
            for (int k=i;k<=n;k++)
                a[j][k]-=a[i][k]*p;
            b[j]-=b[i]*p;
        }
    }
    return(b[1]/a[1][1]);
}
int go[110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int N;
        scanf("%d",&N);
        memset(go,-1,sizeof(go));
        for (int i=1;i<=N;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            go[x]=y;
        }
        memset(c,0,sizeof(c));
        memset(b,0,sizeof(b));
        for (int i=1;i<n;i++)
        {
            if (go[i]!=-1)
            {
                c[i][i]=1;
                c[i][go[i]]=-1;
                b[i]=0;
                continue;
            }
            c[i][i]=b[i]=1;
            for (int j=1;j<=6;j++)
            {
                int x=i+j;
                if (x>100)
                    x=i;
                if (go[x]!=-1)
                    x=go[x];
                c[i][x]-=1.0/6;
            }
        }
        c[n][n]=1;
        static int id=0;
        printf("Case %d: %.10f\n",++id,gauss());
    }
}

