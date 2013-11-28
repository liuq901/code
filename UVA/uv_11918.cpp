#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int limit=1000000001;
struct data
{
    int x1,y1,x2,y2;
    data(int X1,int Y1,int X2,int Y2)
    {
        x1=min(X1,X2),x2=max(X1,X2);
        y1=min(Y1,Y2),y2=max(Y1,Y2);
    }
};
vector <data> c;
vector <int> X,Y;
int begin,end,tot,b[400010],a[2000000][3],to[650][650];
bool f[650][650];
inline int getX(int x)
{
    return(lower_bound(X.begin(),X.end(),x)-X.begin());
}
inline int getY(int y)
{
    return(lower_bound(Y.begin(),Y.end(),y)-Y.begin());
}
void add(int x,int y,int len)
{
    a[++tot][0]=y,a[tot][1]=len,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=len,a[tot][2]=b[y],b[y]=tot;
}
ll d[400010];
int q[400010];
bool in[400010];
void spfa()
{
    ll inf=d[1];
    q[1]=begin;
    d[begin]=0;
    in[begin]=true;
    int l,r;
    l=0,r=1;
    while (l!=r)
    {
        l=l==400005?1:l+1;
        int x=q[l];
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
                    r=r==400005?1:r+1;
                    q[r]=y;
                    int k=l==400005?1:l+1;
                    if (d[q[r]]<d[q[k]])
                        swap(q[r],q[k]);
                }
            }
        }
    }
    static int id=0;
    printf("Case %d: ",++id);
    if (d[end]==inf)
        printf("Impossible\n");
    else
        printf("%lld\n",d[end]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int Sx,Sy,Tx,Ty;
        scanf("%d%d%d%d",&Sx,&Sy,&Tx,&Ty);
        int m,n,o;
        scanf("%d%d%d",&m,&n,&o);
        c.clear();
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            c.push_back(data(x,y,x,y));
        }
        for (int i=1;i<=n;i++)
        {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            c.push_back(data(x1,y1,x2,y2));
        }
        for (int i=1;i<=o;i++)
        {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            c.push_back(data(x1,y1,x1,y2));
            c.push_back(data(x1,y1,x2,y1));
            c.push_back(data(x2,y1,x2,y2));
            c.push_back(data(x1,y2,x2,y2));
        }
        c.push_back(data(-limit,-limit,-limit,limit));
        c.push_back(data(-limit,-limit,limit,-limit));
        c.push_back(data(limit,-limit,limit,limit));
        c.push_back(data(-limit,limit,limit,limit));
        X.clear();
        Y.clear();
        for (int i=0;i<c.size();i++)
        {
            int x1=c[i].x1,y1=c[i].y1,x2=c[i].x2,y2=c[i].y2;
            X.push_back(x1-1);
            X.push_back(x1);
            X.push_back(x2);
            X.push_back(x2+1);
            Y.push_back(y1-1);
            Y.push_back(y1);
            Y.push_back(y2);
            Y.push_back(y2+1);
        }
        X.push_back(Sx);
        X.push_back(Tx);
        Y.push_back(Sy);
        Y.push_back(Ty);
        sort(X.begin(),X.end());
        X.erase(unique(X.begin(),X.end()),X.end());
        sort(Y.begin(),Y.end());
        Y.erase(unique(Y.begin(),Y.end()),Y.end());
        int tmp=0;
        for (int i=0;i<X.size();i++)
            for (int j=0;j<Y.size();j++)
            {
                to[i][j]=++tmp;
                b[tmp]=0;
                f[i][j]=true;
            }
        for (int i=0;i<c.size();i++)
        {
            int x1=getX(c[i].x1),y1=getY(c[i].y1),x2=getX(c[i].x2),y2=getY(c[i].y2);
            for (int j=x1;j<=x2;j++)
                for (int k=y1;k<=y2;k++)
                    f[j][k]=false;
        }
        tot=0;
        for (int i=0;i<X.size();i++)
            for (int j=0;j<Y.size();j++)
            {
                if (!f[i][j])
                    continue;
                if (i>0 && f[i-1][j])
                    add(to[i-1][j],to[i][j],X[i]-X[i-1]);
                if (j>0 && f[i][j-1])
                    add(to[i][j-1],to[i][j],Y[j]-Y[j-1]);
            }
        begin=to[getX(Sx)][getY(Sy)],end=to[getX(Tx)][getY(Ty)];
        for (int i=1;i<=tmp;i++)
            d[i]=1LL<<60;
        spfa();
    }
    return(0);
}

