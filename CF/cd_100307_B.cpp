#include <cstdio>
#include <cstring>
bool vis[3010][3010];
double f[3010][3010];
int n,A,B,me;
double dp(int a,int b)
{
    if (vis[a][b])
        return(f[a][b]);
    vis[a][b]=true;
    double &ret=f[a][b];
    if (a+b==n)
        ret=0;
    else
    {
        int da=A-a,db=B-b;
        double tot=da*2.0+db+me;
        ret=me/tot;
        if (a<A)
            ret+=dp(a+1,b)*da*2/tot;
        if (b<B)
            ret+=dp(a,b+1)*db/tot;
    }
    return(ret);
}
int main()
{
    freopen("bonus.in","r",stdin);
    freopen("bonus.out","w",stdout);
    scanf("%d%d%d",&n,&A,&B);
    me=2;
    printf("%.15f\n",dp(0,0));
    memset(vis,0,sizeof(vis));
    me=1;
    printf("%.15f\n",dp(0,0));
    return(0);
}

