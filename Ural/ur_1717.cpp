#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf=1LL<<60;
struct tree
{
    int l,r;
    ll sum,left,right,best;
};
tree a[5000];
struct data
{
    int x,y,z,sum;
};
inline bool operator <(const data &a,const data &b)
{
    return(a.x<b.x || a.x==b.x && (a.y<b.y || a.y==b.y && a.z<b.z));
}
data b[1510],c[1510];
ll sum[1510];
vector <int> Y;
int s[1510];
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].sum=0,a[x].best=a[x].left=a[x].right=-inf;
    if (l==r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void insert(int x,int pos,int value,int sum)
{
    if (a[x].l==a[x].r)
    {
        if (s[pos]==0)
            a[x].sum=a[x].left=a[x].right=value;
        else
        {
            a[x].sum+=value;
            a[x].left+=value;
            a[x].right+=value;
        }
        s[pos]+=sum;
        if (s[pos]>=2)
            a[x].best=a[x].sum;
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (pos<=mid)
        insert(ls,pos,value,sum);
    else
        insert(rs,pos,value,sum);
    a[x].sum=a[ls].sum+a[rs].sum;
    a[x].left=max(a[ls].left,a[ls].sum+a[rs].left);
    a[x].right=max(a[rs].right,a[rs].sum+a[ls].right);
    a[x].best=max(max(a[ls].best,a[rs].best),a[ls].right+a[rs].left);
}
inline int get(int y)
{
    return(lower_bound(Y.begin(),Y.end(),y)-Y.begin()+1);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].z);
        b[i].sum=1;
        Y.push_back(b[i].y);
    }
    sort(Y.begin(),Y.end());
    Y.erase(unique(Y.begin(),Y.end()),Y.end());
    sort(b+1,b+n+1);
    int t=0;
    for (int i=1;i<=n;i++)
        if (t>0 && b[i].x==c[t].x && b[i].y==c[t].y)
        {
            c[t].z+=b[i].z;
            c[t].sum++;
        }
        else
            c[++t]=b[i];
    n=t;
    memcpy(b,c,sizeof(c));
    int x0,x1;
    ll ans=-inf;
    for (int p=1;p<=n;p++)
    {
        if (p>1 && b[p].x==b[p-1].x)
            continue;
        memset(s,0,sizeof(s));
        build(1,1,Y.size());
        for (int i=p;i<=n;)
        {
            int t=i;
            for (;i<=n && b[i].x==b[t].x;i++)
                insert(1,get(b[i].y),b[i].z,b[i].sum);
            if (a[1].best>ans)
                x0=b[p].x,x1=b[t].x,ans=a[1].best;
        }
    }
    printf("%d %d\n",x0,x1);
    memset(s,0,sizeof(s));
    memset(sum,0,sizeof(sum));
    for (int i=1;i<=n;i++)
        if (b[i].x>=x0 && b[i].x<=x1)
        {
            sum[get(b[i].y)]+=b[i].z;
            s[get(b[i].y)]+=b[i].sum;
        }
    for (int i=1;i<=Y.size();i++)
    {
        s[i]+=s[i-1];
        sum[i]+=sum[i-1];
    }
    for (int i=1;i<=Y.size();i++)
        for (int j=i;j<=Y.size();j++)
            if (sum[j]-sum[i-1]==ans && s[j]-s[i-1]>=2)
            {
                printf("%d %d\n",Y[i-1],Y[j-1]);
                goto out;
            }
out:
    return(0);
}

