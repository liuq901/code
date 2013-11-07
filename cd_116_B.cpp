#include <cstdio>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char a[20][20];
bool check(int x,int y)
{
    for (int i=0;i<4;i++)
        if (a[x+c[i][0]][y+c[i][1]]=='P')
            return(true);
    return(false);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    int ans=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]=='W')
                ans+=check(i,j);
    printf("%d\n",ans);
    return(0);
}

