#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <utility>
using namespace std;
struct point
{
    int x,y;
    point();
    point(int x,int y):x(x),y(y){}
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline int det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline int sign(int x)
{
    return(x<0?-1:x>0);
}
inline bool intersect(const point &a,const point &b,const point &c,const point &d)
{
    return(sign(det(a-d,c-d))*sign(det(b-d,c-d))==-1 && sign(det(c-b,a-b))*sign(det(d-b,a-b))==-1);
}
vector <pair <point,point> > a,b;
bool vis[1010][1010];
char buf[10];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,x0,y0;
        scanf("%d%d%d%d%s",&n,&m,&x0,&y0,buf);
        memset(vis,0,sizeof(vis));
        string S=buf;
        int op;
        if (S=="DR")
            op=0;
        else if (S=="UR")
            op=1;
        else if (S=="UL")
            op=2;
        else
            op=3;
        a.clear();
        b.clear();
        int ans=0;
        while (1)
        {
            vis[x0][y0]=true;
            int x,y,t,newop;
            if (op==0)
            {
                t=min(n-x0,m-y0);
                x=x0+t,y=y0+t;
                newop=x==n?1:3;
            }
            else if (op==1)
            {
                t=min(x0-1,m-y0);
                x=x0-t,y=y0+t;
                newop=y==m?2:0;
            }
            else if (op==2)
            {
                t=min(x0-1,y0-1);
                x=x0-t,y=y0-t;
                newop=x==1?3:1;
            }
            else
            {
                t=min(n-x0,y0-1);
                x=x0+t,y=y0-t;
                newop=y==1?0:2;
            }
            if (op&1)
                a.push_back(make_pair(point(x0,y0),point(x,y)));
            else
                b.push_back(make_pair(point(x0,y0),point(x,y)));
            if (vis[x][y] || x==1 && y==1 || x==n && y==1 || x==1 && y==m || x==n && y==m)
            {
                ans+=vis[x][y];
                break;
            }
            x0=x,y0=y,op=newop;
        }
        for (int i=0;i<a.size();i++)
            for (int j=0;j<b.size();j++)
                ans+=intersect(a[i].first,a[i].second,b[j].first,b[j].second);
        printf("%d\n",ans);
    }
    return(0);
}

