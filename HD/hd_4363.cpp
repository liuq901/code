#include <cstdio>
const int mod=1000000007;
bool vis[41][41][5][5][5][5][2];
int f[41][41][5][5][5][5][2];
inline bool check(int x,int a,int b,int c,int d)
{
    return(x!=a && x!=b && x!=c && x!=d);
}
inline void update(int &x,int y)
{
    x+=y;
    if (x>=mod)
        x-=mod;
    if (x<0)
        x+=mod;
}
inline int calc(int n,int m,int left,int right,int up,int down,bool odd)
{
    int &ret=f[n][m][left][right][up][down][odd];
    if (vis[n][m][left][right][up][down][odd])
        return(ret);
    vis[n][m][left][right][up][down][odd]=true;
    for (int i=1;i<=4;i++)
        if (check(i,left,right,up,down))
            update(ret,1);
    if (odd)
        for (int i=1;i<n;i++)
            for (int j=1;j<=4;j++)
            {
                if (check(j,left,right,up,0))
                {
                    update(ret,calc(n-i,m,left,right,j,down,false));
                    for (int k=1;k<=4;k++)
                        if (check(k,left,right,j,down))
                            update(ret,-1);
                }
                if (check(j,left,right,0,down))
                    update(ret,calc(i,m,left,right,up,j,false));
            }
    else
        for (int i=1;i<m;i++)
            for (int j=1;j<=4;j++)
            {
                if (check(j,left,0,up,down))
                {
                    update(ret,calc(n,m-i,j,right,up,down,true));
                    for (int k=1;k<=4;k++)
                        if (check(k,j,right,up,down))
                            update(ret,-1);
                }
                if (check(j,0,right,up,down))
                    update(ret,calc(n,i,left,j,up,down,true));
            }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        printf("%d\n",calc(n,m,0,0,0,0,true));
    }
    return(0);
}

