#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int S,T,inf,tot,b[500],pos[500][500],a[1000000][3];
void add(int x,int y,int c)
{
    a[++tot][0]=y,a[tot][1]=c,a[tot][2]=b[x],b[x]=tot;
}
int d[500];
bool in[500];
queue <int> Q;
int spfa()
{
    memset(d,63,sizeof(d));
    inf=d[0];
    d[S]=0;
    in[S]=true;
    Q.push(S);
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
    return(d[T]);
}
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        int t=0;
        for (int i=0;i<=n;i++)
            for (int j=0;j<=m;j++)
                pos[i][j]=++t;
        memset(b,0,sizeof(b));
        tot=1;
        for (int i=0;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                int x;
                char ch;
                scanf("%d %c",&x,&ch);
                if (x==0)
                    continue;
                if (ch=='*' || ch=='>')
                    add(pos[i][j-1],pos[i][j],2520/x);
                if (ch=='*' || ch=='<')
                    add(pos[i][j],pos[i][j-1],2520/x);
            }
            if (i==n)
                break;
            for (int j=0;j<=m;j++)
            {
                int x;
                char ch;
                scanf("%d %c",&x,&ch);
                if (x==0)
                    continue;
                if (ch=='*' || ch=='v')
                    add(pos[i][j],pos[i+1][j],2520/x);
                if (ch=='*' || ch=='^')
                    add(pos[i+1][j],pos[i][j],2520/x);
            }
        }
        S=pos[0][0],T=pos[n][m];
        int ans=spfa();
        if (ans==inf)
            printf("Holiday\n");
        else
            printf("%d blips\n",ans);
    }
    return(0);
}

