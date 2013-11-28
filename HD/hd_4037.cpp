#include <cstdio>
typedef long long ll;
const int mod=20110911*2;
struct tree
{
    int l,r,c0,c1,d0,d1,d2,changec,changed,delta0,delta1,delta2;
};
int c[100010],d[100010];
tree a[270000];
void updata(int x)
{
    if (a[x].l!=a[x].r)
    {
        int ls=x<<1,rs=ls+1;
        a[ls].changec+=a[x].changec;
        a[ls].changed+=a[x].changed;
        a[rs].changec+=a[x].changec;
        a[rs].changed+=a[x].changed;
    }
    if (a[x].changec)
    {
        a[x].c0=(a[x].c0+ll(a[x].delta0)*a[x].changec)%mod;
        a[x].c1=(a[x].c1+ll(a[x].delta1)*a[x].changec)%mod;
        a[x].changec=0;
    }
    if (a[x].changed)
    {
        a[x].d0=(a[x].d0+ll(a[x].delta0)*a[x].changed)%mod;
        a[x].d1=(a[x].d1+ll(a[x].delta1)*a[x].changed)%mod;
        a[x].d2=(a[x].d2+ll(a[x].delta2)*a[x].changed)%mod;
        a[x].changed=0;
    }
}
void update(int x)
{
    int ls=x<<1,rs=ls+1;
    updata(ls),updata(rs);
    a[x].c0=(a[ls].c0+a[rs].c0)%mod;
    a[x].c1=(a[ls].c1+a[rs].c1)%mod;
    a[x].d0=(a[ls].d0+a[rs].d0)%mod;
    a[x].d1=(a[ls].d1+a[rs].d1)%mod;
    a[x].d2=(a[ls].d2+a[rs].d2)%mod;
}
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r;
    a[x].changec=a[x].changed=0;
    if (l==r)
    {
        a[x].c0=c[l];
        a[x].c1=ll(c[l])*l%mod;
        a[x].d0=d[l];
        a[x].d1=ll(d[l])*l%mod;
        a[x].d2=ll(d[l])*l*l%mod;
        a[x].delta0=1;
        a[x].delta1=l;
        a[x].delta2=ll(l)*l%mod;
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    a[x].delta0=(a[ls].delta0+a[rs].delta0)%mod;
    a[x].delta1=(a[ls].delta1+a[rs].delta1)%mod;
    a[x].delta2=(a[ls].delta2+a[rs].delta2)%mod;
    update(x);
}
void modify(int x,int l,int r,int valuec,int valued)
{
    if (a[x].l==l && a[x].r==r)
    {
        a[x].changec+=valuec;
        a[x].changed+=valued;
        return;
    }
    updata(x);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        modify(ls,l,r,valuec,valued);
    else if (l>mid)
        modify(rs,l,r,valuec,valued);
    else
    {
        modify(ls,l,mid,valuec,valued);
        modify(rs,mid+1,r,valuec,valued);
    }
    update(x);
}
int get(int x,int l,int r,int kind)
{
    updata(x);
    if (a[x].l==l && a[x].r==r)
    {
        if (kind==0)
            return(a[x].c0);
        if (kind==1)
            return(a[x].c1);
        if (kind==2)
            return(a[x].d0);
        if (kind==3)
            return(a[x].d1);
        return(a[x].d2);
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        return(get(ls,l,r,kind));
    else if (l>mid)
        return(get(rs,l,r,kind));
    else
        return((get(ls,l,mid,kind)+get(rs,mid+1,r,kind))%mod);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d%d",&c[i],&d[i]);
        build(1,1,n);
        static int id=0;
        printf("Case %d:\n",++id);
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            char op[10];
            int x,y,z;
            scanf("%s",op);
            if (op[2]=='s')
            {
                scanf("%d%d%d",&x,&y,&z);
                modify(1,x,y,z,0);
            }
            else if (op[2]=='l')
            {
                scanf("%d%d%d",&x,&y,&z);
                modify(1,x,y,0,z);
            }
            else
            {
                scanf("%d%d",&x,&y);
                int ans=(ll(y)*(y+1)*get(1,x,y,2)-ll(2*y+1)*get(1,x,y,3)+get(1,x,y,4)-2*(ll(y+1)*get(1,x,y,0)-get(1,x,y,1)))%mod;
                if (ans<0)
                    ans+=mod;
                printf("%d\n",ans/2);
            }
        }
    }
    return(0);
}

