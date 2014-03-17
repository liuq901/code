#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
typedef int arr[6];
const int value[]={100,50,20,10,5,1};
struct state
{
    arr a;
    int &operator [](int x)
    {
        return(a[x]);
    }
    int operator [](int x) const
    {
        return(a[x]);
    }
};
arr a,b,c,s;
vector <int> f[10][1010];
void init(int m)
{
    for (int i=0;i<6;i++)
        for (int j=0;j<=m;j++)
            f[i][j].clear();
    for (int i=0;i<=m;i++)
        if (i%value[0]==0)
            f[0][i].push_back(i/value[0]);
    for (int i=1;i<6;i++)
        for (int j=0;j<=m;j++)
        {
            if (f[i-1][j].empty())
                continue;
            for (int k=0;k<=s[i];k++)
            {
                int delta=k*value[i];
                if (j+delta>m)
                    break;
                f[i][j+delta].push_back(k);
            }
        }
}
state now;
void dfs(int x,int dep,vector <state> &a)
{
    if (dep==-1)
    {
        a.push_back(now);
        return;
    }
    for (int i=0;i<f[dep][x].size();i++)
    {
        now[dep]=f[dep][x][i];
        dfs(x-f[dep][x][i]*value[dep],dep-1,a);
    }
}
int calc(const state &a,int *b)
{
    int ret=0;
    for (int i=0;i<6;i++)
        ret+=abs(a[i]-b[i]);
    return(ret);
}
state tmp;
bool check(const state &a,const state &b)
{
    for (int i=0;i<6;i++)
    {
        tmp[i]=s[i]-a[i]-b[i];
        if (tmp[i]<0)
            return(false);
    }
    return(true);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int ab,bc,ca;
        scanf("%d%d%d",&ab,&bc,&ca);
        int sa=ca-ab;
        int sb=ab-bc;
        int sc=bc-ca;
        for (int i=0;i<6;i++)
        {
            scanf("%d",&a[i]);
            sa+=a[i]*value[i];
        }
        for (int i=0;i<6;i++)
        {
            scanf("%d",&b[i]);
            sb+=b[i]*value[i];
        }
        for (int i=0;i<6;i++)
        {
            scanf("%d",&c[i]);
            sc+=c[i]*value[i];
        }
        for (int i=0;i<6;i++)
            s[i]=a[i]+b[i]+c[i];
        if (sa<0 || sb<0 || sc<0)
            printf("impossible\n");
        else
        {
            init(max(max(sa,sb),sc));
            if (f[5][sa].empty() || f[5][sb].empty() || f[5][sc].empty())
                printf("impossible\n");
            else
            {
                vector <state> p,q;
                dfs(sa,5,p);
                dfs(sb,5,q);
                int best=1<<30;
                for (int i=0;i<p.size();i++)
                {
                    int now=calc(p[i],a);
                    if (now>=best)
                        continue;
                    for (int j=0;j<q.size();j++)
                    {
                        if (!check(p[i],q[j]))
                            continue;
                        int here=now+calc(q[j],b)+calc(tmp,c);
                        if (here<best)
                            best=here;
                    }
                }
                if (best==1<<30)
                    printf("impossible\n");
                else
                    printf("%d\n",best>>1);
            }
        }
    }
    return(0);
}

