#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int b[110],d[110],a[20010][3];
bool in[110];
queue <int> Q;
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=z,a[i+m][2]=b[y],b[y]=i+m;
        }
        memset(d,63,sizeof(d));
        d[1]=0;
        in[1]=true;
        Q.push(1);
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
        printf("%d\n",d[n]);
    }
    return(0);
}

