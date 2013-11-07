#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
typedef unsigned long long ull;
const char no[]="Impossible!";
struct state
{
    vector <char> route;
    ull mask,vis;
    int now;
    double t,value;
    bool in(int here) const
    {
        return(mask>>here-1&1);
    }
    state(){}
    state(double t,double value,ull mask1,int here):t(t),value(value),now(here)
    {
        mask=mask1|1ULL<<here-1;
    }
};
priority_queue <state> Q;
char buf[10000],buf1[10000];
int op,ed,limit,len[70],c[70][70];
double ans,T,X[70],Y[70],p[70],a[70][70],b[70][70];
map <string,int> M;
string name[70];
state best;
inline bool operator <(const state &a,const state &b)
{
    return(fabs(a.value-T)>fabs(b.value-T));
}
inline double sqr(double x)
{
    
    return(x*x);
}
inline double dist(int a,int b)
{
    return(sqrt(sqr(X[a]-X[b])+sqr(Y[a]-Y[b]))/4*60);
}
void print(const state &now)
{
    if (ans>=0.1)
    {
        printf("%s\n",no);
        return;
    }
    for (int i=0;i<now.route.size();i++)
    {
        if (now.route[i]<0)
            continue;
        int x=abs(now.route[i]);
    }
    printf("PATH FOUND: %.3f",now.value);
    for (int i=0;i<now.route.size();i++)
    {
        printf(" ");
        if (now.route[i]<0 && abs(now.route[i])!=ed)
            printf("!");
        int x=abs(now.route[i]);
        printf("%s",name[x].c_str());
    }
    printf("\n");
}
void astar()
{
    while (!Q.empty())
    {
        state now=Q.top();
        Q.pop();
        if (now.t+a[now.now][ed]>limit)
            continue;
        if (now.now==ed)
        {
            if (fabs(now.value-T)<ans)
            {
                ans=fabs(now.value-T);
                best=now;
                if (ans<0.1)
                {
                    print(best);
                    return;
                }
            }
            continue;
        }
        for (int i=1;i<=len[now.now];i++)
        {
            int y=c[now.now][i];
            double here=now.value+a[now.now][ed],d=b[now.now][i];
            if (now.in(y))
                continue;
            state tmp=state(now.t+d,here-d-a[y][ed],now.mask,y);
            tmp.route=now.route;
            tmp.route.push_back(-y);
            Q.push(tmp);
            if (y!=ed)
            {
                tmp=state(now.t+d+15,here+p[y]-d-a[y][ed],now.mask,y);
                tmp.route=now.route;
                tmp.route.push_back(y);
                Q.push(tmp);
            }
        }
    }
    print(best);
}
int main()
{
    int n,m;
    while (scanf("%*s%d%d",&n,&m)==2)
    {
        M.clear();
        for (int i=1;i<=n;i++)
        {
            scanf("%lf%lf%lf%s",&X[i],&Y[i],&p[i],buf);
            name[i]=buf;
            M[buf]=i;
            gets(buf);
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
                a[i][j]=1e100;
            a[i][i]=0;
            len[i]=0;
        }
        for (int i=1;i<=m;i++)
        {
            scanf("%s%s",buf,buf1);
            int x=M[buf],y=M[buf1];
            a[x][y]=a[y][x]=dist(x,y);
            b[x][++len[x]]=dist(x,y);
            c[x][len[x]]=y;
            b[y][++len[y]]=dist(x,y);
            c[y][len[y]]=x;
        }
        for (int k=1;k<=n;k++)
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        static int id=0;
        printf("MAP %d\n",++id);
        scanf("%*s");
        int h1,m1,h2,m2;
        while (scanf("%d:%d%s%d:%d%s%lf",&h1,&m1,buf,&h2,&m2,buf1,&T)==7)
        {
            int t1=h1*60+m1,t2=h2*60+m2;
            if (t1>t2)
                t2+=24*60;
            limit=t2-t1;
            op=M[buf],ed=M[buf1];
            while (!Q.empty())
                Q.pop();
            state tmp=state(0,-a[op][ed],0,op);
            tmp.route.clear();
            tmp.route.push_back(-op);
            Q.push(tmp);
            if (op!=ed)
            {
                tmp=state(15,p[op]-a[op][ed],0,op);
                tmp.route.clear();
                tmp.route.push_back(op);
                Q.push(tmp);
            }
            ans=1e100;
            astar();
        }
    }
    return(0);
}

