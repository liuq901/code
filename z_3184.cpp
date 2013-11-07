#include <cstdio>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;
struct state
{
    bitset <15> s;
    bool row;
    int num;
};
vector <int> A[20],B[20];
vector <state> p;
bool row,f[20];
int n,m,num;
void getstate(int n)
{
    state now;
    now.row=row;
    now.num=num;
    now.s.reset();
    for (int i=0;i<n;i++)
        now.s[i]=f[i];
    p.push_back(now);
}
void dfs(int first,int dep,const vector <int> &a,int limit)
{
    if (dep==a.size())
    {
        getstate(limit);
        return;
    }
    int len=a[dep];
    for (int i=first;i+len<=limit;i++)
    {
        for (int j=i;j<i+len;j++)
            f[j]=true;
        dfs(i+len+1,dep+1,a,limit);
        for (int j=i;j<i+len;j++)
            f[j]=false;
    }
}
struct data
{
    int l,r,u,d,x,y;
};
data a[1000000];
vector <int> z;
int sum[260],q[260];
int get(int x,int y)
{
    return((x-1)*m+y);
}
void getpos(const state &p)
{
    z.clear();
    if (p.row)
    {
        for (int i=0;i<m;i++)
            if (p.s[i])
                z.push_back(get(p.num,i+1));
        z.push_back(n*m+p.num);
    }
    else
    {
        for (int i=0;i<n;i++)
            if (!p.s[i])
                z.push_back(get(i+1,p.num));
        z.push_back(n*m+n+p.num);
    }
}
void build()
{
    int N=n*m+n+m;
    for (int i=1;i<=N;i++)
    {
        a[i].l=i-1;
        a[i].r=i+1;
        sum[i]=0;
        a[i].x=-1;
        a[i].y=i;
        q[i]=i;
    }
    a[0].r=1;
    a[0].l=N;
    a[N].r=0;
    int tot=N;
    for (int i=0;i<p.size();i++)
    {
        getpos(p[i]);
        int first;
        for (int j=0;j<z.size();j++)
        {
            sum[z[j]]++;
            tot++;
            a[tot].x=i;
            a[tot].y=z[j];
            if (j!=0)
            {
                a[tot].l=tot-1;
                a[tot-1].r=tot;
            }
            else
                first=tot;
            a[tot].u=q[z[j]];
            a[q[z[j]]].d=tot;
            q[z[j]]=tot;
        }
        a[first].l=tot;
        a[tot].r=first;
    }
    for (int i=1;i<=N;i++)
    {
        a[i].u=q[i];
        a[q[i]].d=i;
    }
}
vector <int> ans;
void del(int x)
{
    a[a[x].l].r=a[x].r;
    a[a[x].r].l=a[x].l;
    for (int i=a[x].d;i!=x;i=a[i].d)
        for (int j=a[i].r;j!=i;j=a[j].r)
        {
            sum[a[j].y]--;
            a[a[j].u].d=a[j].d;
            a[a[j].d].u=a[j].u;
        }
}
void renew(int x)
{
    a[a[x].l].r=x;
    a[a[x].r].l=x;
    for (int i=a[x].u;i!=x;i=a[i].u)
        for (int j=a[i].l;j!=i;j=a[j].l)
        {
            sum[a[j].y]++;
            a[a[j].u].d=j;
            a[a[j].d].u=j;
        }
}
void print()
{
    sort(ans.begin(),ans.end());
    for (int i=0;i<ans.size();i++)
    {
        for (int j=0;j<m;j++)
            printf("%c",p[ans[i]].s[j]?'*':'.');
        printf("\n");
    }
}
bool DLX()
{
    if (a[0].r==0)
    {
        print();
        return(true);
    }
    int k,mi=1<<30;
    for (int i=a[0].r;i!=0;i=a[i].r)
        if (sum[i]<mi)
            mi=sum[k=i];
    del(k);
    for (int i=a[k].d;i!=k;i=a[i].d)
    {
        for (int j=a[i].r;j!=i;j=a[j].r)
            del(a[j].y);
        if (p[a[i].x].row)
            ans.push_back(a[i].x);
        if (DLX())
            return(true);
        if (p[a[i].x].row)
            ans.pop_back();
        for (int j=a[i].l;j!=i;j=a[j].l)
            renew(a[j].y);
    }
    renew(k);
    return(false);
}
int main()
{
    while (1)
    {
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=n;i++)
        {
            A[i].clear();
            while (1)
            {
                int x;
                scanf("%d",&x);
                if (x==0)
                    break;
                A[i].push_back(x);
            }
        }
        for (int i=1;i<=m;i++)
        {
            B[i].clear();
            while (1)
            {
                int x;
                scanf("%d",&x);
                if (x==0)
                    break;
                B[i].push_back(x);
            }
        }
        p.clear();
        for (int i=1;i<=n;i++)
        {
            num=i;
            row=true;
            dfs(0,0,A[i],m);
        }
        for (int i=1;i<=m;i++)
        {
            num=i;
            row=false;
            dfs(0,0,B[i],n);
        }
        build();
        ans.clear();
        DLX();
        printf("\n");
    }
    return(0);
}

