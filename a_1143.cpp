#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef pair <int,int> coor;
typedef long long ll;
const int c[6][2]={{0,1},{0,-1},{1,0},{-1,0},{1,-1},{-1,1}};
map <ll,int> H;
map <coor,int> M;
set <coor> S;
queue <coor> Q;
queue <vector <coor> > q;
coor T,ori[10],a[10];
int n,ans;
ll h[10][2];
void bfs()
{
    M.clear();
    M[T]=0;
    Q.push(T);
    while (!Q.empty())
    {
        int x0=Q.front().first,y0=Q.front().second,dis=M[make_pair(x0,y0)];
        Q.pop();
        for (int i=0;i<6;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (!M.count(make_pair(x,y)))
            {
                M[make_pair(x,y)]=dis+1;
                if (dis<19)
                    Q.push(make_pair(x,y));
            }
        }
    }
}
bool adj(const coor &a,const coor &b)
{
    for (int i=0;i<6;i++)
    {
        coor d;
        d.first=a.first+c[i][0];
        d.second=a.second+c[i][1];
        if (b==d)
            return(true);
    }
    return(false);
}
ll hash()
{
    ll ret=0;
    for (int i=1;i<=n;i++)
        ret+=h[i][0]*a[i].first+h[i][1]*a[i].second;
    return(ret);
}
bool check(int n)
{
    if (S.count(a[n]))
        return(false);
    for (int i=1;i<n;i++)
        if (a[i]==a[n] || adj(a[i],a[n])!=adj(ori[i],ori[n]))
            return(false);
    return(true);
}
void out(const vector <coor> &b)
{
    for (int i=0;i<b.size();i++)
        a[i+1]=b[i];
}
vector <coor> get()
{
    vector <coor> ret;
    for (int i=1;i<=n;i++)
        ret.push_back(a[i]);
    return(ret);
}
bool move(int now,bool can,int dep)
{
    if (now==n+1)
    {
        ll Hash=hash();
        if (H.count(Hash) && dep>=H[Hash])
            return(false);
        H[Hash]=dep;
        int last=20-dep;
        if (!M.count(a[1]) || M[a[1]]>last)
            return(false);
        if (a[1]==T)
        {
            ans=dep;
            return(true);
        }
        q.push(get());
        return(false);
    }
    if (check(now) && move(now+1,true,dep))
        return(true);
    if (can)
        for (int i=0;i<6;i++)
        {
            a[now].first+=c[i][0],a[now].second+=c[i][1];
            if (check(now) && move(now+1,false,dep))
                return(true);
            a[now].first-=c[i][0],a[now].second-=c[i][1];
        }
    return(false);
}
void BFS()
{
    while (!q.empty())
    {
        out(q.front());
        q.pop();
        ll Hash=hash();
        int dep=H[Hash];
        if (move(1,true,dep+1))
            return;
    }
}
ll myrand()
{
    ll a=rand(),b=rand(),c=rand();
    return(a<<32|b<<16|c);
}
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&ori[i].first,&ori[i].second);
            a[i]=ori[i];
            h[i][0]=myrand();
            h[i][1]=myrand();
        }
        S.clear();
        int m;
        scanf("%d",&m);
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            S.insert(make_pair(x,y));
        }
        scanf("%d%d",&T.first,&T.second);
        bfs();
        while (!q.empty())
            q.pop();
        H.clear();
        q.push(get());
        H[hash()]=0;
        BFS();
        printf("%d\n",ans);
    }
    return(0);
}

