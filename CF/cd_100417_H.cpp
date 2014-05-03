#include <cstdio>
#include <cstring>
int pos[5010],a[5010],b[5010],pa[5010][5010],pb[5010][5010],f[5010][5010],pre[5010][5010];
void init(int n,int K,int a[],int prev[][5010])
{
    memset(pos,0,sizeof(pos));
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=K;j++)
            prev[i][j]=pos[j];
        pos[a[i]]=i;
    }
}
bool first=true;
void print(int n,int m)
{
    if (n==0 && m==0)
        return;
    int x=pre[n][m];
    print(pa[n][x],pb[m][x]);
    if (!first)
        printf(" ");
    first=false;
    printf("%d",x);
}
int main()
{
    freopen("robots.in","r",stdin);
    freopen("robots.out","w",stdout);
    int K,n;
    scanf("%d%d",&K,&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int m;
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    n++,m++;
    init(n,K,a,pa);
    init(m,K,b,pb);
    memset(f,63,sizeof(f));
    int inf=f[0][0];
    f[0][0]=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=K;j++)
            if (f[pa[i][j]][0]+1<f[i][0])
            {
                f[i][0]=f[pa[i][j]][0]+1;
                pre[i][0]=j;
            }
    for (int i=1;i<=m;i++)
        for (int j=1;j<=K;j++)
            if (f[0][pb[i][j]]+1<f[0][i])
            {
                f[0][i]=f[0][pb[i][j]]+1;
                pre[0][i]=j;
            }
    for (int i=1;i<=n;i++)
    {
        int best=inf,value=-1;
        for (int j=1;j<=K;j++)
            if (f[pa[i][j]][pb[m][j]]<best)
            {
                best=f[pa[i][j]][pb[m][j]];
                value=j;
            }
        for (int j=m;j;j--)
        {
            int x=b[j];
            if (x!=0 && f[pa[i][x]][pb[j][x]]<best)
            {
                best=f[pa[i][x]][pb[j][x]];
                value=x;
            }
            f[i][j]=best+1;
            pre[i][j]=value;
        }
    }
    printf("%d\n",f[n][m]);
    print(n,m);
    printf("\n");
    return(0);
}

