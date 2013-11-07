#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct point
{
    int x,y;
    point(){}
    point(int x,int y):x(x),y(y){}
    void in()
    {
        scanf("%d%d",&x,&y);
    }
    void out()
    {
        printf("%d %d\n",x,y);
    }
};
typedef map <point,int>::iterator iter;
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline bool operator <(const point &a,const point &b)
{
    return(a.x<b.x || a.x==b.x && a.y<b.y);
}
inline int sign(int x)
{
    return(x<0?-1:x>0);
}
inline int dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
}
inline int det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline bool online(const point &p,const point &a,const point &b)
{
    return(sign(det(a-p,b-p))==0 && sign(dot(a-p,b-p))<=0);
}
inline int sqr(int x)
{
    return(x*x);
}
inline double dist(const point &p,const point &q)
{
    return(sqrt(double(sqr(p.x-q.x)+sqr(p.y-q.y))));
}
map <point,int> s;
vector <int> signs;
bool issign[210],left[410],right[410];
point a[210],b[210],to[410];
int tot,pre[410],c[410][410];
double d[410],v[410][410];
void addpoint(const point &p)
{
    if (s.count(p))
        return;
    s[p]=++tot;
    to[tot]=p;
}
inline void addedge(int x,int y)
{
    c[x][++c[x][0]]=y;
    v[x][c[x][0]]=dist(to[x],to[y]);
}
queue <int> q;
bool in[410];
bool spfa(int S,int T)
{
    bool flag=false;
    for (int i=0;i<s.size();i++)
        d[i+1]=1e20;
    pre[S]=0;
    d[S]=0;
    q.push(S);
    in[S]=true;
    while (!q.empty())
    {
        int x=q.front();
        in[x]=false;
        q.pop();
        for (int i=1;i<=c[x][0];i++)
        {
            int y=c[x][i];
            if (d[x]+v[x][i]<d[y])
            {
                d[y]=d[x]+v[x][i];
                pre[y]=x;
                if (!in[y])
                {
                    in[y]=true;
                    q.push(y);
                    if (y==T)
                        flag=true;
                }
            }
        }
    }
    return(flag);
}
void print(int S,int T)
{
    vector <int> ans;
    for (int i=T;i;i=pre[i])
        ans.push_back(i);
    reverse(ans.begin(),ans.end());
    for (int i=0;i<ans.size();i++)
        to[ans[i]].out();
    printf("0\n");
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        point S,T;
        S.in(),T.in();
        for (int i=1;i<=n;i++)
            a[i].in(),b[i].in();
        memset(issign,0,sizeof(issign));
        signs.clear();
        tot=0;
        s.clear();
        for (int i=1;i<=n;i++)
        {
            int sum1=0,sum2=0;
            for (int j=1;j<=n;j++)
            {
                if (i==j)
                    continue;
                sum1+=online(a[i],a[j],b[j]);
                sum2+=online(b[i],a[j],b[j]);
            }
            if (sum1==0 || sum2==0)
            {
                signs.push_back(i);
                issign[i]=true;
            }
            else
            {
                addpoint(a[i]);
                addpoint(b[i]);
            }
        }
        for (int i=0;i<s.size();i++)
            c[i+1][0]=0;
        for (int i=1;i<=n;i++)
        {
            if (issign[i])
                continue;
            point A=a[i],B=b[i];
            vector <point> now;
            for (iter k=s.begin();k!=s.end();k++)
                if (online(k->first,A,B))
                    now.push_back(k->first);
            for (int j=1;j<now.size();j++)
                left[j]=right[j]=true;
            for (int j=0;j<signs.size();j++)
            {
                point P=a[signs[j]],Q=b[signs[j]];
                bool flag=true;
                if (online(Q,A,B))
                    swap(P,Q);
                else if (!online(P,A,B))
                    flag=false;
                if (flag)
                {
                    int t=lower_bound(now.begin(),now.end(),P)-now.begin();
                    if (sign(dot(now[t-1]-P,Q-P))!=1)
                        left[t]=false;
                    if (sign(dot(now[t]-P,Q-P))!=1)
                        right[t]=false;
                }
            }
            for (int j=1;j<now.size();j++)
            {
                if (left[j])
                    addedge(s[now[j-1]],s[now[j]]);
                if (right[j])
                    addedge(s[now[j]],s[now[j-1]]);
            }
        }
        if (!spfa(s[S],s[T]))
            printf("-1\n");
        else
            print(s[S],s[T]);
    }
    return(0);
}

