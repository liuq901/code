#include <cstdio>
#include <algorithm>
using namespace std;
char a[60][10];
inline bool check(int x,int y)
{
    return(a[x][0]==a[y][0] || a[x][1]==a[y][1]);
}
bool vis[60][60][60][60];
bool dfs(int n,int x,int y,int z)
{
    if (vis[n][x][y][z])
        return(false);
    if (n==1)
        return(true);
    if (check(y,z) && dfs(n-1,max(0,n-3),x,z))
        return(true);
    if (n>=4 && check(n-3,z) && dfs(n-1,z,x,y))
        return(true);
    vis[n][x][y][z]=true;
    return(false);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%s",a[i]);
    printf("%s\n",dfs(n,n-2,n-1,n)?"YES":"NO");
    return(0);
}

