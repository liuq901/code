#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <queue>
#include <map>
using namespace std;
struct point
{
    int x,y;
    point(){}
    point(int x,int y):x(x),y(y){}
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline bool operator <(const point &a,const point &b)
{
    return(a.x<b.x || a.x==b.x && a.y<b.y);
}
inline int det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline int sqr(int x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(double(sqr(a.x-b.x)+sqr(a.y-b.y))));
}
map <point,int> M;
point P[210];
int hash(const point &p)
{
    if (!M.count(p))
    {
        int tmp=M.size()+1;
        M[p]=tmp;
        P[tmp]=p;
    }
    return(M[p]);
}
double len[110],f[210][210];
int b[210],a[110][2];
bool in[210][210];
double spfa(int x0,int y0,double l,int n)
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            f[i][j]=1e100;
    queue <pair <int,int> > Q;
    Q.push(make_pair(x0,y0));
    f[x0][y0]=l;
    in[x0][y0]=true;
    while (!Q.empty())
    {
        int t=Q.front().first,x=Q.front().second;
        Q.pop();
        in[t][x]=false;
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            if (det(P[x]-P[t],P[y]-P[t])>0 && f[t][x]+len[i]<f[x][y])
            {
                f[x][y]=f[t][x]+len[i];
                if (!in[x][y])
                {
                    in[x][y]=true;
                    Q.push(make_pair(x,y));
                }
            }
        }
    }
    double ret=1e100;
    for (int i=1;i<=n;i++)
        if (det(P[x0]-P[i],P[y0]-P[x0])>0)
            ret=min(ret,f[i][x0]);
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        point p;
        scanf("%d%d%d",&n,&p.x,&p.y);
        M.clear();
        memset(b,0,sizeof(b));
        for (int i=1;i<=n;i++)
        {
            point u,v;
            scanf("%d%d%d%d",&u.x,&u.y,&v.x,&v.y);
            int x=hash(u),y=hash(v);
            len[i]=dist(u,v);
            if (det(v-u,p-u)>0)
                a[i][0]=y,a[i][1]=b[x],b[x]=i;
            else
                a[i][0]=x,a[i][1]=b[y],b[y]=i;
        }
        double ans=1e100;
        int N=M.size();
        for (int i=1;i<=N;i++)
            for (int j=b[i];j;j=a[j][1])
            {
                int x=a[j][0];
                ans=min(ans,spfa(i,x,len[j],N));
            }
        static int id=0;
        printf("Case %d: ",++id);
        if (ans==1e100)
            printf("-1\n");
        else
            printf("%.10f\n",ans*2);
    }
    return(0);
}

