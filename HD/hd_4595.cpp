#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
struct node
{
    ll count,sum;
    node *left,*right;
    static node *null;
    node(){}
    node (ll count,ll sum,node *left,node *right):count(count),sum(sum),left(left),right(right){}
    node *insert(int l,int r,int L,int R)
    {
        node *newnode(ll,ll,node *,node *);
        if (R<l || L>r)
            return(this);
        if (L<=l && R>=r)
            return(newnode(count+1,sum+r-l+1,left,right));
        int m=l+r>>1;
        return(newnode(count,sum+min(r,R)-max(l,L)+1,left->insert(l,m,L,R),right->insert(m+1,r,L,R)));
    }
    ll query(int l,int r,int L,int R)
    {
        if (R<l || L>r)
            return(0);
        if (L<=l && R>=r)
            return(sum);
        int m=l+r>>1;
        return(count*(min(r,R)-max(l,L)+1)+left->query(l,m,L,R)+right->query(m+1,r,L,R));
    }
};
node *node::null;
node *root[100010];
node lq[100010*40];
int tot;
node* newnode(ll count,ll sum,node *left,node *right)
{
    lq[tot]=node(count,sum,left,right);
    return(&lq[tot++]);
}
ll get(int x)
{
    vector <int> p;
    while (x)
    {
        p.push_back(x%10);
        x/=10;
    }
    sort(p.begin(),p.end(),greater <int>());
    ll ret=0;
    for (int i=0;i<p.size();i++)
        ret=ret*10+p[i];
    return(ret);
}
int to[100010],a[100010],mi[100010],ma[100010];
int main()
{
    int n,Q;
    while (scanf("%d%d",&n,&Q)==2)
    {
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        map <ll,int> pos;
        for (int i=1;i<=n;i++)
        {
            ll x=get(a[i]);
            to[i]=pos[x];
            pos[x]=i;
        }
        int pre0,pre1;
        pre0=pre1=0;
        for (int i=1;i<=n;i++)
        {
            if (to[i]>pre1)
            {
                pre0=pre1;
                pre1=to[i];
            }
            else if (to[i]>pre0)
                pre0=to[i];
            mi[i]=pre0+1;
            ma[i]=pre1;
        }
        tot=0;
        node::null=newnode(0,0,NULL,NULL);
        root[0]=node::null;
        node::null->left=node::null->right=node::null;
        for (int i=1;i<=n;i++)
            root[i]=root[i-1]->insert(1,n,mi[i],ma[i]);
        ll k=0;
        while (Q--)
        {
            ll l,r;
            scanf("%I64d%I64d",&l,&r);
            l+=k,r-=k;
            k=root[r]->query(1,n,l,r);
            printf("%I64d\n",k);
        }
    }
    return(0);
}

