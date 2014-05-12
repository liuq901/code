#include <cstdio>
#include <cstring>
int n,a[30],cnt[4100],f[4100][30][2];
int check(int x,int y,int z)
{
    if (f[x][y][z]!=-1)
        return(f[x][y][z]);
    int &ret=f[x][y][z];
    if (x==0)
        return(y==0 && z==0);
    for (int i=1;i<=n;i++)
    {
        if (!(x>>i-1&1))
            continue;
        int state=x^1<<i-1;
        for (int j=state;;j=state&j-1)
        {
            for (int k=0;k<=y;k++)
            {
                int son=cnt[j]+k;
                if (son<a[i] && a[i]-son-1<=y-k)
                {
                    int p=a[i]-son-1;
                    if (z==1 && state==j || !check(state^j,y-k-p,0))
                        continue;
                    if (j==0 && k==0 && p>=2 || j>0 && check(j,k,p==0))
                        return(ret=true);
                }
            }
            if (j==0)
                break;
        }
    }
    return(ret=false);
}
int main()
{
    scanf("%d",&n);
    int leaf=0,m=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if (a[i]==1)
            leaf++;
        else
            a[++m]=a[i];
    }
    if (n==1)
        printf("%s\n",leaf?"YES":"NO");
    else
    {
        n-=leaf;
        if (n>=leaf)
            printf("NO\n");
        else
        {
            memset(f,-1,sizeof(f));
            for (int i=0;i<1<<n;i++)
                cnt[i]=__builtin_popcount(i);
            bool flag=false;
            for (int i=1;i<=n;i++)
                if (a[i]==n+leaf)
                    flag=true;
            printf("%s\n",flag && check((1<<n)-1,leaf,0)?"YES":"NO");
        }
    }
    return(0);
}

