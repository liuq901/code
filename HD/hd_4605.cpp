#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#define less _less
#define equal _equal
#define greater _greater
using namespace std;
typedef pair <int,int> data;
const int N=100010;
inline data operator +(const data &a,const data &b)
{
    return(make_pair(a.first+b.first,a.second+b.second));
}
data less[N],equal[N],greater[N],ans[N];
int n,w[N],c[N],l[N],r[N],pos[N],L[N],R[N],qq[N],q[N][2];
bool child[N];
inline bool cmp1(int x,int y)
{
    return(w[x]<w[y]);
}
inline bool cmp2(int x,int y)
{
    return(q[x][1]<q[y][1]);
}
int Stack[N][2];
void dfs(int root)
{
    int tot=0,top=1;
    Stack[1][0]=root,Stack[1][1]=0;
    while (top>0)
    {
        int x=Stack[top][0],state=Stack[top][1];
        if (state==0)
        {
            tot++;
            pos[x]=L[x]=tot;
            Stack[top][1]=1;
            if (l[x])
            {
                Stack[++top][0]=l[x];
                Stack[top][1]=0;
            }
        }
        else if (state==1)
        {
            Stack[top][1]=2;
            if (r[x])
            {
                Stack[++top][0]=r[x];
                Stack[top][1]=0;
            }
        }
        else
        {
            R[x]=tot;
            top--;
        }
    }
}
void modify(data *a,int x,data v)
{
    for (int i=x;i<=n;i+=i&-i)
        a[i]=a[i]+v;
}
data query(data *a,int x)
{
    data ans(0,0);
    for (int i=x;i;i-=i&-i)
        ans=ans+a[i];
    return(ans);
}
data negate(const data &a)
{
    return(make_pair(-a.first,-a.second));
}
void add(data *a,int x,data v)
{
    if (x==0)
        return;
    modify(a,L[x],v);
    modify(a,R[x]+1,negate(v));
}
void del(data *a,int x,data v)
{
    if (x==0)
        return;
    modify(a,L[x],negate(v));
    modify(a,R[x]+1,v);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&w[i]);
            c[i]=i;
        }
        sort(c+1,c+n+1,cmp1);
        int m;
        scanf("%d",&m);
        memset(child,0,sizeof(child));
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        memset(less,0,sizeof(less));
        memset(equal,0,sizeof(equal));
        memset(greater,0,sizeof(greater));
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            child[y]=child[z]=true;
            l[x]=y,r[x]=z;
        }
        int root;
        for (int i=1;i<=n;i++)
            if (!child[i])
            {
                root=i;
                break;
            }
        dfs(root);
        int Q;
        scanf("%d",&Q);
        for (int i=1;i<=Q;i++)
        {
            scanf("%d%d",&q[i][0],&q[i][1]);
            qq[i]=i;
        }
        sort(qq+1,qq+Q+1,cmp2);
        for (int i=1;i<=n;i++)
        {
            add(greater,l[i],make_pair(0,1));
            add(greater,r[i],make_pair(0,1));
        }
        int t1,t2;
        t1=t2=1;
        for (int i=1;i<=Q;i++)
        {
            int id=qq[i],v=q[qq[i]][0],X=q[qq[i]][1];
            while (t1<t2 && w[c[t1]]<X)
            {
                del(equal,l[c[t1]],make_pair(1,0));
                del(equal,r[c[t1]],make_pair(1,0));
                add(less,l[c[t1]],make_pair(0,3));
                add(less,r[c[t1]],make_pair(1,3));
                t1++;
            }
            while (t2<=n && w[c[t2]]<=X)
            {
                del(greater,l[c[t2]],make_pair(0,1));
                del(greater,r[c[t2]],make_pair(0,1));
                if (w[c[t2]]==X)
                {
                    add(equal,l[c[t2]],make_pair(1,0));
                    add(equal,r[c[t2]],make_pair(1,0));
                }
                else
                {
                    add(less,l[c[t2]],make_pair(0,3));
                    add(less,r[c[t2]],make_pair(1,3));
                    t1++;
                }
                t2++;
            }
            data tmp=query(equal,pos[v]);
            if (tmp.first>0)
                ans[id]=make_pair(-1,-1);
            else
                ans[id]=query(less,pos[v])+query(greater,pos[v]);
        }
        for (int i=1;i<=Q;i++)
            if (ans[i].first==-1)
                printf("0\n");
            else
                printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return(0);
}

