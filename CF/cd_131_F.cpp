#include <cstdio>
typedef long long ll;
const int c[5][2]={{-1,0},{1,0},{0,-1},{0,1},{0,0}};
char buf[510][510];
int a[510][510],s[510][510];
inline int calc(int x,int y)
{
    for (int i=0;i<5;i++)
        if (buf[x+c[i][0]][y+c[i][1]]!='1')
            return(0);
    return(1);
}
inline int get(int x1,int y1,int x2,int y2)
{
    return(s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]);
}
int main()
{
    int n,m,K;
    scanf("%d%d%d",&n,&m,&K);
    for (int i=1;i<=n;i++)
        scanf("%s",buf[i]+1);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            a[i][j]=calc(i,j);
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
    ll ans=0;
    for (int i=1;i<=n;i++)
        for (int j=i+2;j<=n;j++)
        {
            if (get(i+1,2,j-1,m-1)<K)
                continue;
            int l=1;
            for (int k=3;k<=m;k++)
            {
                while (l<=k && get(i+1,l+2,j-1,k-1)>=K)
                    l++;
                if (get(i+1,l+1,j-1,k-1)>=K)
                    ans+=l;
            }
        }
    printf("%I64d\n",ans);
    return(0);
}

