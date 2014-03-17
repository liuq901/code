#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct state
{
    int x,t,value;
    state(int x,int t,int value):x(x),t(t),value(value){}
};
inline bool operator <(const state &a,const state &b)
{
    return(a.value>b.value);
}
int p[1010],b[1010],d[1010][110],a[20010][3];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    for (int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x++,y++;
        a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
        a[i+m][0]=x,a[i+m][1]=z,a[i+m][2]=b[y],b[y]=i+m;
    }
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        int K,S,T;
        scanf("%d%d%d",&K,&S,&T);
        S++,T++;
        if (S==T)
        {
            printf("0\n");
            continue;
        }
        priority_queue <state> Q;
        memset(d,63,sizeof(d));
        Q.push(state(S,0,0));
        d[S][0]=0;
        int ans=-1;
        while (!Q.empty())
        {
            int x=Q.top().x,t=Q.top().t,value=Q.top().value;
            if (x==T)
            {
                ans=value;
                break;
            }
            Q.pop();
            if (t<K && d[x][t]+p[x]<d[x][t+1])
            {
                d[x][t+1]=d[x][t]+p[x];
                Q.push(state(x,t+1,d[x][t+1]));
            }
            for (int i=b[x];i;i=a[i][2])
            {
                int y=a[i][0];
                if (a[i][1]<=t && d[x][t]<d[y][t-a[i][1]])
                {
                    d[y][t-a[i][1]]=d[x][t];
                    Q.push(state(y,t-a[i][1],d[y][t-a[i][1]]));
                }
            }
        }
        if (ans==-1)
            printf("impossible\n");
        else
            printf("%d\n",ans);
    }
    return(0);
}

