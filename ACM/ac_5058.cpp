#include <cstdio>
typedef long long ll;
const int mod=1000003;
int tot,l[1010],r[1010],s[1010],v[1010],c[1010][1010];
void insert(int &x,int value)
{
    if (x==0)
    {
        x=++tot;
        l[x]=r[x]=0;
        s[x]=1;
        v[x]=value;
        return;
    }
    s[x]++;
    if (value<v[x])
        insert(l[x],value);
    else
        insert(r[x],value);
}
int calc(int x)
{
    if (x==0)
        return(1);
    int ans=ll(calc(l[x]))*calc(r[x])%mod*c[s[x]-1][s[l[x]]]%mod;
    return(ans);
}
int main()
{
    for (int i=0;i<=1000;i++)
    {
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int root=0;
        tot=0;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            insert(root,x);
        }
        int ans=ll(calc(root))*c[m][n]%mod;
        printf("%d\n",ans);
    }
    return(0);
}

