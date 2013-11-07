#include <cstdio>
#include <queue>
using namespace std;
queue <int> Q;
int c[210],u[210],b[210],d[210],a[100000][3];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&c[i],&u[i]);
        if (c[i]>0)
            Q.push(i);
    }
    for (int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        d[y]++;
        a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
    }
    while (!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            c[y]+=c[x]*a[i][1];
            if (--d[y]==0 && c[y]>u[y])
            {
                c[y]-=u[y];
                Q.push(y);
            }
        }
    }
    bool flag=false;
    for (int i=1;i<=n;i++)
        if (b[i]==0 && c[i]>0)
        {
            printf("%d %d\n",i,c[i]);
            flag=true;
        }
    if (!flag)
        printf("NULL\n");
    return(0);
}

