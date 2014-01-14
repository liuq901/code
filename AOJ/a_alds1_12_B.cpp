#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int d[110],b[110],a[1000000][3];
bool in[110];
void spfa()
{
    memset(d,63,sizeof(d));
    d[0]=0;
    queue <int> Q;
    Q.push(0);
    in[0]=true;
    while (!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        in[x]=false;
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (d[x]+a[i][1]<d[y])
            {
                d[y]=d[x]+a[i][1];
                if (!in[y])
                {
                    in[y]=true;
                    Q.push(y);
                }
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int tot=0;
    for (int i=1;i<=n;i++)
    {
        int x,m;
        scanf("%d%d",&x,&m);
        for (int j=1;j<=m;j++)
        {
            int y,p;
            scanf("%d%d",&y,&p);
            a[++tot][0]=y,a[tot][1]=p,a[tot][2]=b[x],b[x]=tot;
        }
    }
    spfa();
    for (int i=0;i<n;i++)
        printf("%d %d\n",i,d[i]);
    return(0);
}

