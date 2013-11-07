#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ext/hash_map>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
const ull lq=10003;
const int to[]={0,1,3,2,6,5,4,7,9,8,11,10,12};
int n,m,v[20];
bool L[20],R[20],U[20],D[20];
void init()
{
    U[2]=D[2]=true;
    L[3]=R[3]=true;
    U[4]=R[4]=true;
    D[5]=R[5]=true;
    L[6]=D[6]=true;
    L[7]=U[7]=true;
    U[8]=D[8]=R[8]=true;
    L[9]=R[9]=D[9]=true;
    U[10]=D[10]=L[10]=true;
    L[11]=R[11]=U[11]=true;
    L[12]=R[12]=U[12]=D[12]=true;
}
int tmp[20];
void trans()
{
    swap(n,m);
    for (int i=1;i<=12;i++)
        tmp[to[i]]=v[i];
    for (int i=1;i<=12;i++)
        v[i]=tmp[i];
}
int f[20],c[10][10];
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
void Union(int x,int y)
{
    if (x==26 || y==26)
        return;
    x=find(x),y=find(y);
    f[max(x,y)]=min(x,y);
}
struct ha
{
    ull operator ()(ull x) const
    {
        return(x);
    }
};
struct equ
{
    bool operator ()(ull x,ull y) const
    {
        return(x==y);
    }
};
hash_map <ull,ll,ha,equ> M;
ll dfs(int dep,int now,int *b)
{
    if (now==m+1)
    {
        int a[10];
        for (int i=1;i<=m;i++)
        {
            a[i]=(dep-1)*m+i;
            f[a[i]]=a[i];
            if (b[i]!=26)
                f[b[i]]=b[i];
        }
        for (int i=1;i<=m;i++)
            if (U[c[dep][i]])
                Union(a[i],b[i]);
        for (int i=2;i<=m;i++)
            if (L[c[dep][i]] && R[c[dep][i-1]])
                Union(a[i],a[i-1]);
        for (int i=m-1;i;i--)
            if (R[c[dep][i]] && L[c[dep][i+1]])
                Union(a[i],a[i+1]);
        for (int i=1;i<=m;i++)
            a[i]=find(a[i]);
        if (dep==n)
            return(a[m]==1);
        else
        {
            bool flag=false;
            for (int i=1;i<=m;i++)
            {
                if (!D[c[dep][i]])
                    a[i]=26;
                if (a[i]==1)
                    flag=true;
            }
            ull state=0;
            state=dep*lq+now;
            for (int i=1;i<=m;i++)
                state=state*lq+a[i];
            for (int i=1;i<=12;i++)
                state=state*lq+(v[i]+1);
            if (M.count(state))
                return(M[state]);
            ll ret=0;
            if (flag)
                ret=dfs(dep+1,1,a);
            M[state]=ret;
            return(ret);
        }
    }
    ll ret=0;
    for (int i=1;i<=12;i++)
    {
        if (v[i]==0)
            continue;
        v[i]--;
        c[dep][now]=i;
        ret+=dfs(dep,now+1,b);
        v[i]++;
    }
    return(ret);
}
int main()
{
    init();
    scanf("%d%d",&n,&m);
    for (int i=1;i<=12;i++)
        scanf("%d",&v[i]);
    if (n<m)
        trans();
    int b[10];
    for (int i=1;i<=m;i++)
        b[i]=26;
    ll ans=dfs(1,1,b);
    cout<<ans<<endl;
    return(0);
}

