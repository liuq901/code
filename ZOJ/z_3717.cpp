#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
struct point
{
    int x,y,z;
    void in()
    {
        scanf("%d%d%d",&x,&y,&z);
    }
};
inline int sqr(int x)
{
    return(x*x);
}
inline int dist(const point &a,const point &b)
{
    return(sqr(a.x-b.x)+sqr(a.y-b.y)+sqr(a.z-b.z));
}
point A[210],B[210];
vector <int> d;
int id,n,top,idx,tot,belong[410],b[410],dfn[410],low[410],Stack[410],a[100000][2];
bool flag[410];
void add(int x,int y)
{
    a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
}
void tarjan(int x)
{
    dfn[x]=low[x]=++idx;
    Stack[++top]=x;
    flag[x]=true;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if (flag[y])
            low[x]=min(low[x],dfn[y]);
    }
    if (dfn[x]==low[x])
    {
        id++;
        while (Stack[top]!=x)
        {
            int p=Stack[top--];
            belong[p]=id;
            flag[p]=false;
        }
        belong[x]=id,flag[x]=false,top--;
    }
}
bool check(int limit)
{
    memset(b,0,sizeof(b));
    tot=0;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        {
            if (dist(A[i],A[j])<limit)
            {
                add(i,j+n);
                add(j,i+n);
            }
            if (dist(A[i],B[j])<limit)
            {
                add(i,j);
                add(j+n,i+n);
            }
            if (dist(B[i],A[j])<limit)
            {
                add(i+n,j+n);
                add(j,i);
            }
            if (dist(B[i],B[j])<limit)
            {
                add(i+n,j);
                add(j+n,i);
            }
        }
    memset(dfn,0,sizeof(dfn));
    memset(flag,0,sizeof(flag));
    id=idx=top=0;
    for (int i=1;i<=2*n;i++)
        if (!dfn[i])
            tarjan(i);
    for (int i=1;i<=n;i++)
        if (belong[i]==belong[i+n])
            return(false);
    return(true);
}
int main()
{
    while (scanf("%d",&n)==1)
    {
        for (int i=1;i<=n;i++)
            A[i].in(),B[i].in();
        d.clear();
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
            {
                d.push_back(dist(A[i],A[j]));
                d.push_back(dist(A[i],B[j]));
                d.push_back(dist(B[i],A[j]));
                d.push_back(dist(B[i],B[j]));
            }
        sort(d.begin(),d.end());
        d.erase(unique(d.begin(),d.end()),d.end());
        int l=0,r=d.size()-1,ans;
        while (l<=r)
        {
            int mid=l+r>>1;
            if (check(d[mid]))
                ans=d[mid],l=mid+1;
            else
                r=mid-1;
        }
        double result=sqrt(double(ans))/2;
        result=floor(result*1000)/1000;
        printf("%.3f\n",result);
    }
    return(0);
}

