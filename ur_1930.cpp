#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int b[10010],f[10010][2],q[40010][2],a[200010][3];
int bfs(int S,int T)
{
    int l,r;
    l=20005,r=20006;
    q[l][0]=S,q[l][1]=0;
    q[r][0]=S,q[r][1]=1;
    memset(f,63,sizeof(f));
    f[S][0]=f[S][1]=0;
    while (l<=r)
    {
        int x=q[l][0],dir=q[l++][1];
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0],now=a[i][1];
            if (dir==now && f[x][dir]<f[y][now])
            {
                f[y][now]=f[x][dir];
                q[--l][0]=y,q[l][1]=now;
            }
            if (dir!=now && f[x][dir]+1<f[y][now])
            {
                f[y][now]=f[x][dir]+1;
                q[++r][0]=y,q[r][1]=now;
            }
        }
    }
    return(min(f[T][0],f[T][1]));
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[i][0]=y,a[i][1]=0,a[i][2]=b[x],b[x]=i;
        a[i+m][0]=x,a[i+m][1]=1,a[i+m][2]=b[y],b[y]=i+m;
    }
    int S,T;
    scanf("%d%d",&S,&T);
    printf("%d\n",bfs(S,T));
    return(0);
}

