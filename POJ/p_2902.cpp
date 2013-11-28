#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const double eps=1e-8;
struct flying
{
    int x,y,v,bomb;
    flying(){}
    flying(int x,int y,int v,int bomb):x(x),y(y),v(v),bomb(bomb){}
};
vector <pair <double,double> > interval;
vector <flying> ufo;
int missile[310],b[310],c[310][310];
bool vis[310];
inline int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
vector <pair <double,double> > merge(vector <pair <double,double> > interval)
{
    if (interval.empty())
        return(interval);
    vector <pair <double,double> > ret;
    sort(interval.begin(),interval.end());
    double l=interval[0].first,r=interval[0].second;
    for (int i=1;i<interval.size();i++)
    {
        double x=interval[i].first,y=interval[i].second;
        if (sign(x-r)==1)
        {
            ret.push_back(make_pair(l,r));
            l=x,r=y;
        }
        else
            r=max(r,y);
    }
    ret.push_back(make_pair(l,r));
    return(ret);
}
bool check(double l,double r)
{
    interval=merge(interval);
    for (int i=0;i<interval.size();i++)
    {
        double x=interval[i].first,y=interval[i].second;
        if (sign(l-x)>=0 && sign(y-r)>=0)
            return(false);
    }
    return(true);
}
bool hungary(int x)
{
    if (!x)
        return(true);
    for (int i=1;i<=c[x][0];i++)
    {
        int y=c[x][i];
        if (vis[y])
            continue;
        vis[y]=true;
        if (hungary(b[y]))
        {
            b[y]=x;
            return(true);
        }
    }
    return(false);
}
inline bool cmp(const flying &a,const flying &b)
{
    return(a.y<b.y);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int B,P,M;
        scanf("%d%d%d",&B,&P,&M);
        int vb,vp,vm;
        scanf("%d%d%d",&vb,&vp,&vm);
        ufo.clear();
        for (int i=1;i<=B;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            ufo.push_back(flying(x,y,vb,i));
        }
        for (int i=1;i<=P;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            ufo.push_back(flying(x,y,vp,0));
        }
        for (int i=1;i<=M;i++)
            scanf("%d",&missile[i]);
        sort(ufo.begin(),ufo.end(),cmp);
        for (int i=1;i<=M;i++)
        {
            c[i][0]=0;
            interval.clear();
            for (int j=0;j<ufo.size();j++)
            {
                int x=ufo[j].x,y=ufo[j].y;
                double dx=missile[i]-x;
                double t=double(y)/vm,t1=dx/vb,t2=(dx+1)/vb;
                double l=max(0.0,t1-t),r=t2-t;
                if (sign(r)==-1)
                    continue;
                if (ufo[j].bomb!=0 && check(l,r))
                    c[i][++c[i][0]]=ufo[j].bomb;
                interval.push_back(make_pair(l,r));
            }
        }
        memset(b,0,sizeof(b));
        int ans=0;
        for (int i=1;i<=M;i++)
        {
            memset(vis,0,sizeof(vis));
            ans+=hungary(i);
        }
        static int id=0;
        printf("Mission #%d: %d bomber(s) exploded\n",++id,ans);
    }
    return(0);
}

