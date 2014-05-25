#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long ll;
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
inline ll dot(const point &a,const point &b)
{
    return(ll(a.x)*b.x+ll(a.y)*b.y);
}
inline ll det(const point &a,const point &b)
{
    return(ll(a.x)*b.y-ll(a.y)*b.x);
}
inline ll area(const point &a,const point &b,const point &c)
{
    return(abs(det(b-a,c-a)));
}
inline bool in(const point &p,const point &a,const point &b,const point &c)
{
    return(area(p,a,b)+area(p,a,c)+area(p,b,c)==area(a,b,c));
}
point a[200010],b[200010];
int idx,pos,vis[200010];
point get(int id)
{
    id+=pos;
    if (vis[id]!=idx)
    {
        vis[id]=idx;
        b[id]=a[id];
    }
    return(b[id]);
}
inline bool in(const point &p,int n)
{
    if (n==3)
        return(in(p,get(0),get(1),get(2)));
    point A=get(0),B=get(n/2);
    if (det(B-A,p-A)==0)
        return(dot(p-A,p-B)<=0);
    if (det(B-A,p-A)>0)
    {
        b[pos+n]=A;
        vis[pos+n]=idx;
        pos+=n/2;
        return(in(p,n-n/2+1));
    }
    else
        return(in(p,n/2+1));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%d%d",&a[i].x,&a[i].y);
        int Q;
        scanf("%d",&Q);
        static int id=0;
        printf("Case %d:\n",++id);
        memset(vis,0,sizeof(vis));
        while (Q--)
        {
            point p;
            scanf("%d%d",&p.x,&p.y);
            idx++;
            pos=0;
            printf("%s\n",in(p,n)?"y":"n");
        }
    }
    return(0);
}

