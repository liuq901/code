#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int b[510],d[510],a[32010][3];
bool in[510];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            x++,y++;
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=z,a[i+m][2]=b[y],b[y]=i+m;
        }
        int S;
        scanf("%d",&S);
        S++;
        queue <int> Q;
        Q.push(S);
        memset(d,63,sizeof(d));
        d[S]=0;
        in[S]=true;
        while (!Q.empty())
        {
            int x=Q.front();
            Q.pop();
            in[x]=false;
            for (int i=b[x];i;i=a[i][2])
            {
                int y=a[i][0];
                if (max(d[x],a[i][1])<d[y])
                {
                    d[y]=max(d[x],a[i][1]);
                    if (!in[y])
                    {
                        in[y]=true;
                        Q.push(y);
                    }
                }
            }
        }
        static int id=0;
        printf("Case %d:\n",++id);
        for (int i=1;i<=n;i++)
            if (d[i]==d[0])
                printf("Impossible\n");
            else
                printf("%d\n",d[i]);
    }
    return(0);
}

