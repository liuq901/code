#include <cstdio>
char now[100],s[20][100];
int ans,n,m,a[20];
bool check()
{
    for (int i=1;i<=m;i++)
    {
        int sum=0;
        for (int j=0;j<n;j++)
            sum+=now[j]!=s[i][j];
        if (sum!=a[i])
            return(false);
    }
    return(true);
}
void dfs(int x,int y)
{
    if (y==a[1])
    {
        ans+=check();
        return;
    }
    for (int i=x;i<n;i++)
    {
        now[i]='1'-s[1][i]+'0';
        dfs(i+1,y+1);
        now[i]=s[1][i];
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
        scanf("%s%d",s[i],&a[i]);
    for (int i=0;i<n;i++)
        now[i]=s[1][i];
    dfs(0,0);
    printf("%d\n",ans);
    return(0);
}

