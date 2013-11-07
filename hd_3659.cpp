#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int v[9][3]={{0,6,0},{2,1,0},{2,4,0},{3,2,1},{3,1,1},{2,4,0},{1,4,1},{2,2,0},{0,4,2}};
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline bool operator <(const point &a,const point &b)
{
    if (sign(a.x-b.x)!=0)
        return(sign(a.x-b.x)==-1);
    return(sign(a.y-b.y)==-1);
}
inline bool operator ==(const point &a,const point &b)
{
    return(sign(a.x-b.x)==0 && sign(a.y-b.y)==0);
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
bool vis[1010];
map <point,int> M;
vector <int> p,adj[1010];
vector <pair <double,int> > ans;
point a[1010],b[1010];
void dfs(int x)
{
    M[a[x]]++;
    M[b[x]]++;
    p.push_back(x);
    vis[x]=true;
    for (int i=0;i<adj[x].size();i++)
    {
        int y=adj[x][i];
        if (!vis[y])
            dfs(y);
    }
}
int two_five()
{
    point A,B,C;
    for (int i=0;i<p.size();i++)
    {
        int x=p[i];
        if (M[a[x]]==1)
        {
            A=a[x];
            B=b[x];
            break;
        }
        if (M[b[x]]==1)
        {
            A=b[x];
            B=a[x];
            break;
        }
    }
    for (int i=0;i<p.size();i++)
    {
        int x=p[i];
        if (a[x]==B && M[b[x]]==2)
        {
            C=b[x];
            break;
        }
        if (b[x]==B && M[a[x]]==2)
        {
            C=a[x];
            break;
        }
    }
    return(sign(det(C-B,B-A))>0?2:5);
}
int calc()
{
    int c[10]={0};
    for (map <point,int>::iterator k=M.begin();k!=M.end();k++)
        c[k->second]++;
    for (int i=0;i<9;i++)
    {
        if (i==2 || i==5)
            continue;
        if (c[1]==v[i][0] && c[2]==v[i][1] && c[3]==v[i][2])
            return(i);
    }
    return(two_five());
}
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        for (int i=1;i<=n;i++)
        {
            scanf("%lf%lf%lf%lf",&a[i].x,&a[i].y,&b[i].x,&b[i].y);
            adj[i].clear();
        }
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                if (a[i]==a[j] || a[i]==b[j] || b[i]==a[j] || b[i]==b[j])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
        ans.clear();
        memset(vis,0,sizeof(vis));
        for (int i=1;i<=n;i++)
        {
            if (vis[i])
                continue;
            M.clear();
            p.clear();
            dfs(i);
            ans.push_back(make_pair(a[i].x,calc()));
        }
        sort(ans.begin(),ans.end());
        for (int i=0;i<ans.size();i++)
            printf("%d",ans[i].second);
        printf("\n");
    }
    return(0);
}

