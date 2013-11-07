#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <map>
using namespace std;
int S,T,tot,num,b[160],d[160],a[20010][3];
map <string,int> M;
queue <int> Q;
bool in[160];
int hash(const string &s)
{
    if (!M.count(s))
        M[s]=++num;
    return(M[s]);
}
void add(int x,int y,int v)
{
    a[++tot][0]=y,a[tot][1]=v,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=v,a[tot][2]=b[y],b[y]=tot;
}
void spfa()
{
    memset(d,-1,sizeof(d));
    d[S]=0;
    Q.push(S);
    in[S]=true;
    while (!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        in[x]=false;
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (d[y]==-1 || d[x]+a[i][1]<d[y])
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
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==-1)
            break;
        char s[100],t[100];
        scanf("%s%s",s,t);
        M.clear();
        tot=num=0;
        memset(b,0,sizeof(b));
        S=hash(s),T=hash(t);
        for (int i=1;i<=n;i++)
        {
            int v;
            scanf("%s%s%d",s,t,&v);
            int x=hash(s),y=hash(t);
            add(x,y,v);
        }
        spfa();
        printf("%d\n",d[T]);
    }
    return(0);
}

