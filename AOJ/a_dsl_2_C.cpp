#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct event
{
    int pos,l,r;
    short kind;
    event(int pos,int l,int r,short kind):pos(pos),l(l),r(r),kind(kind){}
};
inline bool operator <(const event &a,const event &b)
{
    return(a.pos<b.pos || a.pos==b.pos && a.kind<b.kind);
}
vector <short> a[1100000];
vector <int> ans[20010];
void build(int x,int l,int r)
{
    if (l==r)
        return;
    int ls=x<<1,rs=ls+1,mid=l+r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void query(int x,int b,int e,int pos,int id)
{
    for (vector <short>::iterator k=a[x].begin();k!=a[x].end();k++)
        ans[*k].push_back(id);
    if (b==e)
        return;
    int ls=x<<1,rs=ls+1,mid=b+e>>1;
    pos<=mid?query(ls,b,mid,pos,id):query(rs,mid+1,e,pos,id);
}
void modify(int x,int b,int e,int l,int r,int id)
{
    if (b==l && e==r)
    {
        if (id<0)
            a[x].push_back(-id);
        else
            a[x].erase(find(a[x].begin(),a[x].end(),id));
        return;
    }
    int ls=x<<1,rs=ls+1,mid=b+e>>1;
    if (r<=mid)
        modify(ls,b,mid,l,r,id);
    else if (l>mid)
        modify(rs,mid+1,e,l,r,id);
    else
    {
        modify(ls,b,mid,l,mid,id);
        modify(rs,mid+1,e,mid+1,r,id);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    vector <event> e;
    vector <int> Y;
    for (int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e.push_back(event(x,y,i-1,0));
        Y.push_back(y);
    }
    int Q;
    scanf("%d",&Q);
    for (int i=1;i<=Q;i++)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
        e.push_back(event(x1,y1,y2,-i));
        e.push_back(event(x2,y1,y2,i));
        Y.push_back(y1);
        Y.push_back(y2);
    }
    sort(Y.begin(),Y.end());
    Y.erase(unique(Y.begin(),Y.end()),Y.end());
    build(1,1,Y.size());
    sort(e.begin(),e.end());
    for (int i=0;i<e.size();i++)
    {
        e[i].l=lower_bound(Y.begin(),Y.end(),e[i].l)-Y.begin()+1;
        if (e[i].kind!=0)
            e[i].r=lower_bound(Y.begin(),Y.end(),e[i].r)-Y.begin()+1;
    }
    int K=Y.size();
    Y.clear();
    for (int i=0;i<e.size();i++)
    {
        if (e[i].kind==0)
            query(1,1,K,e[i].l,e[i].r);
        else
            modify(1,1,K,e[i].l,e[i].r,e[i].kind);
    }
    for (int i=1;i<=Q;i++)
    {
        sort(ans[i].begin(),ans[i].end());
        for (int j=0;j<ans[i].size();j++)
            printf("%d\n",ans[i][j]);
        printf("\n");
    }
    return(0);
}

