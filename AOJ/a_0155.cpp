#include <cstdio>
#include <cmath>
bool vis[1010];
int n,pre[1010],X[1010],Y[1010];
double d[1010],a[1010][1010];
void print(int x)
{
    if (pre[x]!=0)
    {
        print(pre[x]);
        printf(" ");
    }
    printf("%d",x);
}
void dijkstra(int S,int T)
{
    for (int i=1;i<=n;i++)
    {
        d[i]=1e100;
        vis[i]=false;
    }
    d[S]=0;
    pre[S]=0;
    for (int i=1;i<=n;i++)
    {
        int k=-1;
        for (int j=1;j<=n;j++)
            if (!vis[j] && (k==-1 || d[j]<d[k]))
                k=j;
        if (d[k]==1e100)
            break;
        vis[k]=true;
        for (int j=1;j<=n;j++)
            if (d[k]+a[k][j]<d[j])
            {
                d[j]=d[k]+a[k][j];
                pre[j]=k;
            }
    }
    if (d[T]==1e100)
    {
        printf("NA\n");
        return;
    }
    print(T);
    printf("\n");
}
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
        {
            int id;
            scanf("%d",&id);
            scanf("%d%d",&X[id],&Y[id]);
        }
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
            {
                int p=(X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]);
                a[i][j]=a[j][i]=p<=2500?sqrt(double(p)):1e100;
            }
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            int S,T;
            scanf("%d%d",&S,&T);
            dijkstra(S,T);
        }
    }
    return(0);
}

