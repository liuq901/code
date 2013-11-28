#include <cstdio>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
struct point
{
    int x,y;
    point(){}
    point(int x,int y):x(x),y(y){}
};
inline bool operator <(const point &a,const point &b)
{
    return(a.x<b.x || a.x==b.x && a.y<b.y);
}
struct RangeSquaredSubsets
{
    set <pair <point,point> > s;
    point a[50];
    int n;
    long long countSubsets(int nlow,int nhigh,vector <int> x,vector <int> y)
    {
        s.clear();
        n=x.size();
        for (int i=0;i<n;i++)
            x[i]<<=1,y[i]<<=1;
        nlow<<=1,nhigh<<=1;
        for (int i=0;i<n;i++)
            a[i]=point(x[i],y[i]);
        int ans=0;
        for (int i=0;i<n;i++)
            for (int j=i;j<n;j++)
                for (int k=j;k<n;k++)
                    for (int l=k;l<n;l++)
                    {
                        int minx=min(min(a[i].x,a[j].x),min(a[k].x,a[l].x));
                        int maxx=max(max(a[i].x,a[j].x),max(a[k].x,a[l].x));
                        int miny=min(min(a[i].y,a[j].y),min(a[k].y,a[l].y));
                        int maxy=max(max(a[i].y,a[j].y),max(a[k].y,a[l].y));
                        ans+=check(minx,maxx,miny,maxy,nlow,nhigh);
                    }
        return(ans);
    }
    bool check(int x0,int x1,int y0,int y1,int nlow,int nhigh)
    {
        int target=max(x1-x0,y1-y0);
        if (target>nhigh)
            return(false);
        target=max(target,nlow);
        int dx=target-(x1-x0),dy=target-(y1-y0);
        vector <point> out;
        for (int i=0;i<n;i++)
        {
            if (a[i].x>=x0 && a[i].x<=x1 && a[i].y>=y0 && a[i].y<=y1)
                continue;
            out.push_back(a[i]);
        }
        point a(x0,y0),b(x1,y1);
        if (s.count(make_pair(a,b)))
            return(false);
        s.insert(make_pair(a,b));
        out.push_back(point(x0-dx-1,y0-dy-1));
        for (int i=0;i<out.size();i++)
        {
            if (out[i].x>=x0 || x0-out[i].x>dx+1)
                continue;
            for (int j=0;j<out.size();j++)
            {
                if (out[j].y>=y0 || y0-out[j].y>dy+1)
                    continue;
                int x=out[i].x+1,y=out[j].y+1;
                if (!in(out,x,y,x+target,y+target))
                    return(true);
            }
        }
        return(false);
    }
    bool in(const vector <point> &a,int x0,int y0,int x1,int y1)
    {
        for (int i=0;i<a.size();i++)
            if (a[i].x>=x0 && a[i].x<=x1 && a[i].y>=y0 && a[i].y<=y1)
                return(true);
        return(false);
    }
};
int main(){}

