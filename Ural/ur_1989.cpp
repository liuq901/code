#include <cstdio>
#include <cstring>
typedef unsigned long long ull;
const int lq=10007;
struct tree
{
    int l,r,len;
    ull x,y;
};
tree a[270000];
char s[100010];
ull c[100010];
void update(tree &x,const tree &ls,const tree &rs)
{
    x.x=ls.x*c[rs.len]+rs.x;
    x.y=ls.y+rs.y*c[ls.len];
}
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].len=r-l+1;
    if (a[x].l==a[x].r)
    {
        a[x].x=a[x].y=s[l]-'0';
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    update(a[x],a[ls],a[rs]);
}
tree query(int x,int l,int r)
{
    if (a[x].l==l && a[x].r==r)
        return(a[x]);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        return(query(ls,l,r));
    else if (l>mid)
        return(query(rs,l,r));
    else
    {
        tree ret;
        ret.l=l,ret.r=r,ret.len=r-l+1;
        update(ret,query(ls,l,mid),query(rs,mid+1,r));
        return(ret);
    }
}
void modify(int x,int pos,char ch)
{
    if (a[x].l==a[x].r)
    {
        a[x].x=a[x].y=ch-'0';
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (pos<=mid)
        modify(ls,pos,ch);
    else
        modify(rs,pos,ch);
    update(a[x],a[ls],a[rs]);
}
int main()
{
    c[0]=1;
    for (int i=1;i<=100000;i++)
        c[i]=c[i-1]*lq;
    scanf("%s",s+1);
    build(1,1,strlen(s+1));
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        char op[20];
        scanf("%s",op);
        if (op[0]=='p')
        {
            int x,y;
            scanf("%d%d",&x,&y);
            tree tmp=query(1,x,y);
            printf("%s\n",tmp.x==tmp.y?"Yes":"No");
        }
        else
        {
            int x;
            char ch[10];
            scanf("%d%s",&x,ch);
            modify(1,x,ch[0]);
        }
    }
    return(0);
}

