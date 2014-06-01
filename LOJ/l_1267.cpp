#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct tree
{
    int l,r,sum;
};
tree a[530000];
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].sum=0;
    if (l==r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void insert(int x,int pos)
{
    a[x].sum++;
    if (a[x].l==a[x].r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    insert(pos<=mid?ls:rs,pos);
}
int query(int x,int l,int r)
{
    if (a[x].l==l && a[x].r==r)
        return(a[x].sum);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        return(query(ls,l,r));
    else if (l>mid)
        return(query(rs,l,r));
    else
        return(query(ls,l,mid)+query(rs,mid+1,r));
}
struct event
{
    int x,y1,y2,kind;
    event(int x,int y1,int y2,int kind):x(x),y1(y1),y2(y2),kind(kind){}
};
inline bool operator <(const event &a,const event &b)
{
    return(a.x<b.x || a.x==b.x && a.kind<b.kind);
}
int ans[50010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        vector <event> e;
        vector <int> Y;
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            Y.push_back(y);
            e.push_back(event(x,y,y,0));
        }
        for (int i=1;i<=m;i++)
        {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            Y.push_back(y1);
            Y.push_back(y2);
            e.push_back(event(x1,y1,y2,-i));
            e.push_back(event(x2,y1,y2,i));
            ans[i]=0;
        }
        sort(Y.begin(),Y.end());
        Y.erase(unique(Y.begin(),Y.end()),Y.end());
        build(1,1,Y.size());
        sort(e.begin(),e.end());
        for (int i=0;i<e.size();i++)
        {
            int l=lower_bound(Y.begin(),Y.end(),e[i].y1)-Y.begin()+1;
            int r=lower_bound(Y.begin(),Y.end(),e[i].y2)-Y.begin()+1;
            if (e[i].kind==0)
                insert(1,l);
            else if (e[i].kind<0)
                ans[-e[i].kind]-=query(1,l,r);
            else
                ans[e[i].kind]+=query(1,l,r);
        }
        static int id=0;
        printf("Case %d:\n",++id);
        for (int i=1;i<=m;i++)
            printf("%d\n",ans[i]);
    }
    return(0);
}

