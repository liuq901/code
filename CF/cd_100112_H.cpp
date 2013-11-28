#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int b[1010],f[1010],a[20010][2];
queue <int> Q;
int main()
{
    int n,K,m;
    scanf("%d%d%d",&n,&K,&m);
    memset(f,63,sizeof(f));
    for (int i=1;i<=K;i++)
    {
        int x;
        scanf("%d",&x);
        Q.push(x);
        f[x]=0;
    }
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[i][0]=y,a[i][1]=b[x],b[x]=i;
        a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
    }
    while (!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            if (f[x]+1<f[y])
            {
                f[y]=f[x]+1;
                Q.push(y);
            }
        }
    }
    int ans=0;
    for (int i=1;i<n;i++)
        if (f[i]>f[ans])
            ans=i;
    printf("%d\n",ans);
    return(0);
}

