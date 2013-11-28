#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
const int inf=1000000001;
struct process
{
    int A,B,C,a,b,c,id;
};
struct tree
{
    int l,r,x,a,b,c;
};
process A[50010];
inline bool cmpA(int x,int y)
{
    return(A[x].A<A[y].A);
}
inline bool cmpB(int x,int y)
{
    return(A[x].B<A[y].B);
}
tree a[200010];
int nowA,nowB,nowC,b[50010],c[50010],allocation[50010][3],request[50010][3];
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].x=inf;
    if (l==r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void insert(int x,const process &v)
{
    if (a[x].l==a[x].r)
    {
        a[x].x=v.C;
        a[x].a=v.a,a[x].b=v.b,a[x].c=v.c;
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (v.id+1<=mid)
        insert(ls,v);
    else
        insert(rs,v);
    a[x].x=min(a[ls].x,a[rs].x);
}
int get(int x,int l,int r)
{
    if (l==a[x].l && r==a[x].r)
        return(a[x].x);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        return(get(ls,l,r));
    else if (l>mid)
        return(get(rs,l,r));
    else
        return(min(get(ls,l,mid),get(rs,mid+1,r)));
}
void del(int x,int l,int r)
{
    if (a[x].l==a[x].r)
    {
        a[x].x=inf;
        nowA=min(inf-1,nowA+a[x].a);
        nowB=min(inf-1,nowB+a[x].b);
        nowC=min(inf-1,nowC+a[x].c);
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        del(ls,l,r);
    else if (a[ls].x==a[x].x)
        del(ls,l,mid);
    else
        del(rs,mid+1,r);
    a[x].x=min(a[ls].x,a[rs].x);
}
void read(int &x)
{
    char ch;
    while (1)
    {
        ch=getchar();
        if (isdigit(ch))
            break;
    }
    x=ch-'0';
    while (1)
    {
        ch=getchar();
        if (!isdigit(ch))
            break;
        x=x*10+ch-'0';
    }
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
    {
        memset(allocation,0,sizeof(allocation));
        memset(request,0,sizeof(request));
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                read(allocation[j][i]);
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                read(request[j][i]);
        scanf("%d%d%d",&nowA,&nowB,&nowC);
        for (int i=0;i<n;i++)
        {
            A[i].a=allocation[i][0];
            A[i].b=allocation[i][1];
            A[i].c=allocation[i][2];
            A[i].A=request[i][0];
            A[i].B=request[i][1];
            A[i].C=request[i][2];
        }
        for (int i=0;i<n;i++)
            c[i]=i;
        sort(c,c+n,cmpB);
        for (int i=0;i<n;i++)
        {
            b[i]=A[c[i]].B;
            A[c[i]].id=i;
        }
        for (int i=0;i<n;i++)
            c[i]=i;
        sort(c,c+n,cmpA);
        int now=0,t=0;
        build(1,1,n);
        while (1)
        {
            while (t<n && A[c[t]].A<=nowA)
            {
                if (A[c[t]].A<=nowA && A[c[t]].B<=nowB && A[c[t]].C<=nowC)
                {
                    now++;
                    nowA=min(inf-1,nowA+A[c[t]].a);
                    nowB=min(inf-1,nowB+A[c[t]].b);
                    nowC=min(inf-1,nowC+A[c[t]].c);
                    t++;
                    continue;
                }
                insert(1,A[c[t++]]);
            }
            int R=upper_bound(b,b+n,nowB)-b;
            if (R==0 || nowC<get(1,1,R))
                break;
            now++;
            del(1,1,R);
        }
        printf("%s\n",now==n?"Yes":"No");
    }
    return(0);
}

